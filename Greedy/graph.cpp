#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int nodes;
    vector<vector<int>> adjMat;

public:
    Graph(int n)
    {
        nodes = n;
        adjMat.resize(nodes);
        for (int i = 0; i < nodes; i++)
        {
            adjMat[i].resize(nodes);
            for (int j = 0; j < nodes; j++)
            {
                adjMat[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v, int w)
    {
        adjMat[u][v] = w;
        adjMat[v][u] = w;
    }
    void printMat()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 5, 6);
    g.printMat();
    return 0;
}