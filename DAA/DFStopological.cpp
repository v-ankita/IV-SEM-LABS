#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int source_node,Vertex,Edge,visited[10],Graph[10][10];
vector<int> push, pop;

void DepthFirstSearch(int i)
{
    int j;
    visited[i]=1;
    push.push_back(i+1);

    for(j=0;j<Vertex;j++)
    {	
			if(Graph[i][j]==1&&visited[j]==0)
			{	
				DepthFirstSearch(j);
            	
        	}	
    }
	if(j==Vertex)
		pop.push_back(i+1);
}

int main()
{
    int i,j,v1,v2;
    cout<<"Enter the number of vertices:";
    cin>>Vertex;
    cout<<"Enter the number of edges:";
    cin>>Edge;

    for(i=0;i<Vertex;i++)
    {
        for(j=0;j<Vertex;j++)
            Graph[i][j]=0;
	}

    cout<<("Enter the edges (V1 V2) : \n");
    for(i=0;i<Edge;i++)
    {
        cin>>v1>>v2;
        Graph[v1-1][v2-1]=1;

    }

    cout<<"\nAdjacency Matrix of the given graph is "<<endl;
    for(i=0;i<Vertex;i++)
    {
        for(j=0;j<Vertex;j++)
            cout<<Graph[i][j]<<" ";
		cout<<endl;
    }

int indeg[Vertex];

  for (i = 0; i < Vertex; i++) {
    indeg[i] = 0;
  }

  for (i = 0; i < Vertex; i++)
    for (j = 0; j < Vertex; j++)
      indeg[i] = indeg[i] + Graph[j][i];
      
  cout<<"\nThe topological sort using DFS is "<<endl;    
  for (i = 0; i < Vertex; i++)
  {
    if(indeg[i] ==0)
    {
        source_node=i+1;
        break;
    }
  }
   for (i = 0; i < Vertex; i++)
  {
    if(i+1==source_node)
    {
      continue;
    }
    if(indeg[i]==0)
    cout<<i+1<<" ";
  }
  
    DepthFirstSearch(source_node-1);
    reverse(pop.begin(), pop.end());
    for(i=0;i<pop.size();i++)
    {
        cout<<pop[i]<<" ";
    }
    
    return 0;

}
