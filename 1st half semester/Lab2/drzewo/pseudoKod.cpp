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
    int vert_val, var;  //vert_val - ilosc wierzcholkow grafu
    double total_weight=0, new_weight=0, weight=0;
    bool added;
    vector <edge> edges;
    string str;
    edge edg;

    ifstream ifile("networkin.txt");
    ofstream ofile("networkout.txt", ios_base::in | ios_base::trunc);
    if(!ifile||!ofile)
    {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return -1;
    }
                                                            //Wczytanie grafu do macierzy
    getline(ifile, str);
    vert_val = atoi(str.c_str());

    matrix = new int * [vert_val];
    for(int k = 0; k < vert_val; k++)   matrix[k] = new int [vert_val];


    for(int i = 0; i < vert_val; i++)
        for(int j = 0; j < vert_val; j++)
        {
            if(j < vert_val - 1) getline(ifile, str,',');
                else getline(ifile, str);

            var = atoi(str.c_str());
            matrix[i][j] = var;
        }


                                                            //Stworzenie tablicy z posortowanymi krawedziami
    for(int i = 0; i < vert_val; i++)
    {
        for(int j = 0; j < vert_val; j++)
        {
            if(i > j && matrix[i][j] != 0)
            {
                edg.src = i;
                edg.dst = j;
                edg.weight = matrix[i][j];
                edges.push_back(edg);
                total_weight += matrix[i][j];
            }
        }
    }

    sort(edges.begin(), edges.end(), edgcmp);

    vector <vector <edge> > A;                              //Stworzenie zbioru A podzbiorow krawedzi

    for(int i = 0; i < edges.size(); i++)
    {
        int x = edges[i].src;
        int y = edges[i].dst;
        int w = edges[i].weight;
        int X = -1, Y = -1;

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

        if(X < 0 && Y < 0)                                  //Tworzenie nowego podzbioru krawedzi
        {
            vector <edge> n;
            n.push_back(edges[i]);
            A.push_back(n);
        }
        else if(X >= 0 && Y < 0)                            //Dodawanie krawedzi do odpowiednich podzbiorow
        {
            A[X].push_back(edges[i]);

        }
        else if(X < 0 && Y >= 0)
        {
            A[Y].push_back(edges[i]);
        }
        else if(X >= 0 && Y >= 0 && X != Y)                 //Jesli krawedzie naleza do roznych podzbiorow to unia podzbiorow
        {
            for(int s = 0; s < A[Y].size(); s++)
                A[X].push_back(A[Y][s]);
                A[X].push_back(edges[i]);
                A[Y].erase(A[Y].begin(), A[Y].end());
        }
    }
    /*cout << "===============" << endl;                    //Wypisywanie krawedzi tworzacych drzewo
        for(int m = 0; m < A.size(); m++)
        {
            for(int n = 0; n < A[m].size(); n++)
            {
                cout << A[m][n].src << " " << A[m][n].dst << " " << A[m][n].weight << endl;
            }
        }
    cout << "===============" << endl;*/
                                                            //Zapisywanie do pliku i wypisywanie w konsoli
    ofile << vert_val << endl;
    cout << vert_val << endl;

    for(int i = 0; i < vert_val; i++)
    {
        for(int j = 0; j < vert_val; j++)
        {
            added = false;
            for(int m = 0; m < A.size(); m++)
            {
                for(int n = 0; n < A[m].size(); n++)
                {
                    if((A[m][n].src==i)&&(A[m][n].dst==j)||(A[m][n].src==j)&&(A[m][n].dst==i))
                    {
                        if(j < vert_val - 1)
                        {
                            ofile << A[m][n].weight << ",";
                            cout <<  A[m][n].weight << ",";
                        }
                        else
                        {
                            ofile << A[m][n].weight << "\n";
                            cout << A[m][n].weight << "\n";
                        }
                        added = true;
                        new_weight += A[m][n].weight;
                    }

                }
            }
            if(!added)
                {
                    if(j < vert_val - 1)
                    {
                        ofile << "-,";
                        cout << "-,";
                    }
                    else
                    {
                        ofile << "-\n";
                        cout << "-\n";
                    }

                }
        }
    }
    weight = total_weight - (new_weight/2);
    cout << "Maksymalna oszczednosc to " << weight;

    for(int k = 0; k < vert_val; k++)   delete[] matrix[k];
    delete[] matrix;
    ifile.close();
    ofile.close();
    return 0;
}
