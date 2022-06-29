#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<bool> v;
vector<vector<int>> g;
void bfsTraversal(int b)
{
    //Declare a queue to store all the nodes connected to b
    queue<int> q;
    //Insert b to queue
    q.push(b);
    //mark b as visited
    v[b] = true;
    cout << "\nThe BFS Traversal is:  ";
    while (!q.empty())
    {
        int a = q.front();
        q.pop(); //delete the first element from queue
        for (auto j = g[a].begin(); j != g[a].end(); j++)
        {
            if (!v[*j])
            {
                v[*j] = true;
                q.push(*j);
            }
        }
        cout << a+1 << "  ";
    }
}
void makeEdge(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
    //edge from a to b and b to a
}
int main()
{

 

    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    v.assign(n, false);
    g.assign(n, vector<int>());
    int a, b, i;
    cout << "Enter the edges (V1 V2) : \n ";
    for (i = 0; i < e; i++)
    {
        cin >> a >> b;
        makeEdge(a-1, b-1);
    }
    int source_node;
    cout<<("\nEnter the source: ");
    cin>>source_node;
    for (i = 0; i < n; i++)
    {
        //if the node i is unvisited
        if (!v[i])
        {
            bfsTraversal(i);
        }
    }

 

    return 0;
}