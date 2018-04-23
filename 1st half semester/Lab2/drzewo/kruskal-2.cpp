#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstdlib>

using namespace std;

struct edge
{
    int src;
    int dst;
    int weight;
};

bool edgcmp(edge a, edge b)
{
    return (a.weight < b.weight);
}

int main()
{
    int **matrix;
    int edges_val;
    int var;
    bool added;
    vector <edge> edges;
    string str;

    ifstream ifile("networkin.txt");
    ofstream ofile ("networkout.txt", ios_base::in | ios_base::trunc);
    if(!ifile||!ofile)
    {
        cout << "Nie mo¿na otworzyæ pliku!" << endl;
        return -1;
    }

    getline(ifile, str);
    edges_val = atoi(str.c_str());

    matrix = new int * [edges_val];
    for(int k = 0; k < edges_val; k++)   matrix[k] = new int [edges_val];


    for(int i = 0; i < edges_val; i++)
        for(int j = 0; j < edges_val; j++)
        {
            if(j < edges_val - 1) getline(ifile, str,',');
                else getline(ifile, str);

            var = atoi(str.c_str());
            matrix[i][j] = var;
        }



      for(int i = 0; i < edges_val; i++)
      {
         for(int j = 0; j < edges_val; j++)

    cout << matrix[i][j]<< "  " ;
        cout << endl;
      }
      cout << endl;

    edge edg;
    for(int i = 0; i < edges_val; i++)
    {
        for(int j = 0; j < edges_val; j++)
        {
            if(i > j && matrix[i][j] != 0)
            {
                edg.src = i;
                edg.dst = j;
                edg.weight = matrix[i][j];
                edges.push_back(edg);
            }
        }
    }

    sort(edges.begin(), edges.end(), edgcmp);

    for(int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].src << " " << edges[i].dst << " " << edges[i].weight << endl;
    }

    cout << endl;

    vector <vector <edge> > A;

    for(int i = 0; i < edges.size(); i++)
    {
        int x = edges[i].src;
        int y = edges[i].dst;
        int w = edges[i].weight;
        int X = -1, Y = -1;
        cout << x << " " << y << " " << w << endl;
        for(int m = 0; m < A.size(); m++)
        {
            for(int n = 0; n < A[m].size(); n++)
            {
                if(x == A[m][n].src || x == A[m][n].dst)
                    X = m;
                if(y == A[m][n].src || y == A[m][n].dst)
                    Y = m;
           }
        }
        cout << X << " " << Y << " " << endl;
        if(X < 0 && Y < 0)//Tworzenie nowego podzbioru krawedzi
        {
            vector <edge> n;
            n.push_back(edges[i]);
            A.push_back(n);
        }
        else if(X >= 0 && Y < 0)
        {
            A[X].push_back(edges[i]);

        }
        else if(X < 0 && Y >= 0)
        {
            A[Y].push_back(edges[i]);
        }
        else if(X >= 0 && Y >= 0 && X != Y) //Jesli krawedzie naleza do roznych podzbiorow to unia podzbiorow
        {
            for(int s = 0; s < A[Y].size(); s++)
                A[X].push_back(A[Y][s]);
                A[X].push_back(edges[i]);
                A[Y].erase(A[Y].begin(), A[Y].end());
        }
        cout << "size: " << A.size();
        for(int w = 0; w < A.size(); w++)
            cout << " " << A[w].size();
        cout << endl;
    }

        cout << "===============" << endl;
        for(int m = 0; m < A.size(); m++)
        {
            for(int n = 0; n < A[m].size(); n++)
            {
                cout << A[m][n].src << " " << A[m][n].dst << " " << A[m][n].weight << endl;
            }
        }
    cout << "===============" << endl;




    ofile << edges_val << endl;

    for(int i = 0; i < edges_val; i++)
    {
        for(int j = 0; j < edges_val; j++)
        {
            added = false;
            for(int m = 0; m < A.size(); m++)
            {
                for(int n = 0; n < A[m].size(); n++)
                {
                    if((A[m][n].src==i)&&(A[m][n].dst==j)||(A[m][n].src==j)&&(A[m][n].dst==i))
                    {
                        if(j < edges_val - 1) ofile << A[m][n].weight << ",";
                        else
                            ofile << A[m][n].weight << "\n";
                        added = true;
                    }

                }
            }
            if(!added)
                {
                    if(j < edges_val - 1) ofile << "-,";
                    else
                        ofile << "-\n";
                }
        }
    }


    ifile.close();
    ofile.close();
    return 0;
}
