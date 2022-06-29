#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
//put t as min of m and n 
//divide m by t, if remainder is zero go to step 3 else go to step 4
//divite n by t, if remainder is zero return the value as answerotherwiser step 4
//decreaset by 1, go to step 2


int gcd(int m ,int n)
{
int t;
if(n>m)
t=m;
else 
t=n;

while(t>0)
{
if((m%t==0 && n%t==0))
{
return t;
}
t--;
}
}

int main()
{
int n,m;
cout<<"Enter the numbers "<<endl;
cin>>n>>m;

cout<<"The gcd of the numbers is "<<gcd(n,m)<<endl;
return 0;
}
