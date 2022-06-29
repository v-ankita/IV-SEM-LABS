#include <iostream>
using namespace std;

int euclids(int m, int n)
{
int r;
if(n==0)
return  m;
while(n!=0)
{
r=m%n;
m=n;
n=r;
}
return m;
}
int main()
{
 int n,m ;
cout<<"Enter first number: ";
cin>>m;
cout<<"Enter second number: ";
cin>>n;
cout<<"GCD of the numbers is: "<<euclids(m,n)<<endl;

return 0;
}



