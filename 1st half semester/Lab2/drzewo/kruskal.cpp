#include<iostream>
#include<vector>
#include<algorithm>

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

    int wagi_krav[7][7] = {{0,16,12,21,0,0,0},{16,0,0,17,20,0,0},
                          {12,0,0,28,0,31,0},{21,17,28,0,18,19,23},
                          {0,20,0,18,0,0,11},{0,0,31,19,0,0,27},
                          {0,0,0,23,11,27,0}};
    vector <edge> edges;

    edge edg;
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(i > j && wagi_krav[i][j] != 0)
            {
                edg.src = i;
                edg.dst = j;
                edg.weight = wagi_krav[i][j];
                edges.push_back(edg);
            }
        }
    }

    sort(edges.begin(), edges.end(), edgcmp);

    for(int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].src << " " << edges[i].dst << " " << edges[i].weight << endl;
    }

    vector <vector <edge> > A;

    for(int i = 0; i < edges.size(); i++)
    {
        int x = edges[i].src;
        int y = edges[i].dst;
        int w = edges[i].weight;
        int X = -1, Y = -1;
        for(int m = 0; m < A.size(); m++)
        {
            for(int n = 0; n < A[n].size(); n++)
            {
                if(x == A[m][n].src || x == A[m][n].dst)
                    X = m;
                if(y == A[m][n].src || y == A[m][n].dst)
                    Y = m;
           }
        }
        if(X < 0 && Y < 0)
        {
            vector <edge> n;
            n.push_back(edges[i]);
            A.push_back(n);
        }
        else if(X > 0 && Y < 0)
        {
            A[X].push_back(edges[i]);
        }
        else if(X < 0 && Y > 0)
        {
            A[Y].push_back(edges[i]);
        }
        else if(X > 0 && Y > 0 && X != Y)
        {
            for(int s = 0; s < A[Y].size(); s++)
                A[X].push_back(A[Y][s]);
                A[Y].erase(A[Y].begin(), A[Y].end());
        }
    }

        for(int m = 0; m < A.size(); m++)
        {
            for(int n = 0; n < A[n].size(); n++)
            {
                cout << A[m][n].src << " " << A[m][n].dst << endl;
            }
        }







    return 0;
}
