#include <iostream> 
#include <queue> 
using namespace std; 

int graph[10][10], source, vertex, edge;

bool isBipartite(int source) 
{ 
	int color[vertex]; 
	for (int i = 0; i < vertex; ++i) 
		color[i] = -1; 

	// Assign first color to source 
	color[source] = 1; 

	// Create a queue (FIFO) of vertex 
	// numbers and enqueue source vertex 
	// for BFS traversal 
	queue <int> q; 
	q.push(source); 

	// Run while there are vertices 
	// in queue (Similar to BFS) 
	while (!q.empty()) 
	{ 
		// Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
		int u = q.front(); 
		q.pop(); 

		// Return false if there is a self-loop 
		if (graph[u][u] == 1) 
		return false; 

		// Find all non-colored adjacent vertices 
		for (int j = 0; j < vertex; ++j) 
		{ 
			// An edge from u to v exists and 
			// destination v is not colored 
			if (graph[u][j] && color[j] == -1) 
			{ 
				// Assign alternate color to this adjacent v of u 
				color[j] = 1 - color[u]; 
				q.push(j); 
			} 

			// An edge from u to v exists and destination 
			// v is colored with same color as u 
			else if (graph[u][j] && color[j] == color[u]) 
				return false; 
		} 
	} 

	// If we reach here, then all adjacent 
	// vertices can be colored with alternate color 
	return true; 
} 


int main(){

    int v1, v2, i, j;
    printf("Enter the number of edges:");

    scanf("%d",&edge);

    
    printf("Enter the number of vertices:");

    scanf("%d",&vertex);

    for(i=0;i<vertex;i++)

    {

        for(j=0;j<vertex;j++)

            graph[i][j]=0;

    }

    for(i=0;i<edge;i++)

    {

        printf("Enter the edges (V1 V2) : ");

        scanf("%d%d",&v1,&v2);

        graph[v1-1][v2-1]=1;

    }

    for(i=0;i<vertex;i++)

    {

        for(j=0;j<vertex;j++)

            printf(" %d ",graph[i][j]);

        printf("\n");

    }

    printf("Enter the source: ");

    scanf("%d",&source);

        isBipartite(source-1)? cout << "Yes, the graph is Bipartite" : cout << "No, the graph is not Bipartite"; 
	return 0; 
} 

