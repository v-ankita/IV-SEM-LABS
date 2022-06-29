#include<iostream>
using namespace std;
int min(int,int);
void floyds(int p[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    if(i==j)
     p[i][j]=0;
    else
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}
int main()
{
 int p[10][10],w,n,e,u,v,i,j;;
 cout<<"Enter the number of vertices:"<<endl;
 cin>>n;
 cout<<"Enter the number of edges:"<<endl;
 cin>>e;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   p[i][j]=999;
 }
 for(i=1;i<=e;i++)
 {
  cout<<"Enter the end vertices of edge"<< i << "with its weight"<<endl;
  cin>>u;
  cin>>v;
  cin>>w;
  p[u][v]=w;
 }
 cout<<"Matrix of input data:"<<endl;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   cout<<p[i][j]<<endl;

 }
 floyds(p,n);
 cout<<"Transitive closure:"<<endl;;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   cout<<p[i][j]<<endl;
 }
 cout<<"The shortest paths are:"<<endl;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   if(i!=j)
    cout<<i,j,p[i][j];
  }
  return 0;
}
