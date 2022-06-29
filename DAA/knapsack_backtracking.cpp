#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> w;
int c;
int bestp=0;
vector<int> p;
int cw=0;
int cp=0;
int Bound(int i)
{
    int cleft=c-cw;
    int b=cp;
    while(i<=n && cleft>=w[i])
    {
        cleft-=w[i];
        b+=w[i];
        i++;
    }
    if(i<=n)
        b+=(p[i]/w[i])*cleft;
    return b;
}
void knapsack(int i)
{
    if(i==n)
    {
        if(cw>bestp)
        {
            bestp=cp;
        }
        return;
    }
    if(cw+w[i]<=c)
    {
        cw+=w[i];
        cp+=p[i];
        knapsack(i+1);
        cw-=w[i];
        cp-=p[i];
    }
    if(Bound(i+1)>bestp)
    {
        knapsack(i+1);
    }
    return;
}
int main()
{
    //take input for knapsack
    cin >> n;
    w.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    knapsack(0);
    cout << bestp << endl;
    return 0;
}