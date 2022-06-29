#include<iostream>

using namespace std;
int main() {
  int i, j, k, n, count = 0;
  int Vertex, Edge, v1, v2;

  cout << "Enter the number of vertices:";
  cin >> n;
  int a[n][n], indeg[n], flag[n];
  cout << "Enter the number of edges:";
  cin >> Edge;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      a[i][j] = 0;
  }

  cout << ("Enter the edges (V1 V2) : \n");
  for (i = 0; i < Edge; i++) {
    cin >> v1 >> v2;
    a[v1 - 1][v2 - 1] = 1;
  }
  cout << "\nAdjacency Matrix of the given graph is " << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }

  for (i = 0; i < n; i++) {
    indeg[i] = 0;
    flag[i] = 0;
  }

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      indeg[i] = indeg[i] + a[j][i];

  cout << "\nThe topological order is: ";
  while(count<n){
        for(k=0;k<n;k++){

            if((indeg[k]==0) && (flag[k] ==0))    
            {
                cout<<k+1<<" ";
                flag[k]=1;  

                for(i=0;i<n;i++){
                    if(a[k][i]==1){
                        a[k][i]=0;             
                        indeg[i]--;            
                    }
                }

                count++;                      
                break;                         
            }
        }
    }
  return 0;
}