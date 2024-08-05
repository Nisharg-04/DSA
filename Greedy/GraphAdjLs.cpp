#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int nodes;
    vector<vector<int>> adjLs;

public:
    Graph(int n)
    {
        nodes = n;
        adjLs.resize(n);
    }
    void addEdge(int u, int v)
    {
        adjLs[u].push_back(v);
        adjLs[v].push_back(u);
    }
    void printLs()
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << i << " -> ";
            for (auto it : adjLs[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    void bfs(int node, vector<int> &visited, vector<int> &bfsTrav)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            bfsTrav.push_back(n);
            for (auto it : adjLs[n])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    void dfs(int node, vector<int> &visited, vector<int> &dfsTrav)
    {
        stack<int> st;
        st.push(node);
        visited[node] = 1;
        while (!st.empty())
        {
            int n = st.top();

            st.pop();
            dfsTrav.push_back(n);
            for (auto it : adjLs[n])
            {
                if (!visited[it])
                {
                    st.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    // void dfs(int node, vector<int> &visited, vector<int> &dfsTrav)
    // {
    //     visited[node] = 1;
    //     dfsTrav.push_back(node);
    //     for (auto it : adjLs[node])
    //     {
    //         if (!visited[it])
    //         {
    //             dfs(it, visited, dfsTrav);
    //         }
    //     }
    // }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    vector<int> visited(6, 0);
    // vector<int> bfsTrav;
    // g.bfs(0, visited, bfsTrav);
    vector<int> dfsTrav;
    g.dfs(0, visited, dfsTrav);
    for (auto it : dfsTrav)
    {
        cout << it << " ";
    }
    // g.printLs();
    return 0;
}