#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int max(int a, int b, int q)
{
	if (a > b)
	{	
		 ans.push_back(q); //this didn't work
		return a;
	}
	else
		return b;
}

int knapSack(int Wt, int w[], int v[], int n)
{
	
	if (n == 0 || Wt == 0)	//base condition
		return 0;
	if (w[n - 1] > Wt)	//in case one item is larger than capacity of knapsack, we skip it
		return knapSack(Wt, w, v, n - 1);
	else
	{

		
		return max(
			(v[n - 1] + knapSack(Wt - w[n - 1], w, v, n - 1)),	// condition where we add current item to knapsack and check for next item
			knapSack(Wt, w, v, n - 1), w[n-1]);	//condition where we rejet this item and check for next
			
	}
}

int main()
{
	int Wt, n;
	cout << "Enter capacity of knapsack: ";
	cin >> Wt;
	cout << "Enter number of items: ";
	cin >> n;
	int w[n], v[n];
	cout << "Enter weights of the items: ";
	for (int i = 0; i < n; i++)
		cin >> w[i];
	cout << "Enter values of the items: ";
	for (int i = 0; i < n; i++)
		cin >> v[i];
	// int cost;
	cout <<"Value of most valuable subset is: "<< knapSack(Wt, w, v, n) << endl;
	cout<<"The items are: ";
	for(int i=0; i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}