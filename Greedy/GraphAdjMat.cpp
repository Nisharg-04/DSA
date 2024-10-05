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
    void addEdge(int u, int v)
    {
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
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
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printMat();
    return 0;
}