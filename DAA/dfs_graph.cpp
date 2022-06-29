#include <iostream>
using namespace std;

int main()
{
        int m, n, matrix[100][100], i, j, k;

        cout << "Enter number of vertices: " << endl;
        cin >> m;
        cout << "Enter number of edges: " << endl;
        cin >> n;
        cout << "Enter edges: " << endl;
        for(k=0;k<n;k++)
        {
                cin >> i;
                cin >> j;
                matrix[i][j] = 1;
        }

        int v, visited[100], visit[100], stack[100], top;
        cout << "Enter initial vertex: " << endl;
        cin >> v;
    cout << "Visited Vertices: " << endl;
        cout << v << " ";
        visited[v] = 1;
        k = 1;

        while(k<n)
        {
                for(j=n; j>=1; j--)
                {
                        if(matrix[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
                        {
                                visit[j]=1;
                                stack[top]=j;
                                top++;
                        }
                }
                v = stack[--top];
                cout << v << " ";
                k++;
                visit[v]=0;
                visited[v]=1;
        }
        cout << endl; 

        return 0;
}
