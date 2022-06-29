#include <bits/stdc++.h>
using namespace std;

int main() {
int m;
cout << "Enter number of people/jobs " << endl;
cin >> m;
int arr[m][m];
int a[m];

cout << "Enter cost matrix " << endl;
for (int i = 0; i < m; i++) {
a[i] = i;
for (int j = 0; j < m; j++) {
cin >> arr[i][j];
}
}
int n = m;

sort(a, a + n);
int max=INT_MAX;
do {


int sum = 0;


 

int j = 0;
for (int i = 0; i < n; i++) {
sum = sum + arr[j][a[i]];
j++;


 

}
if(sum<max)
max=sum;


 

//cout << sum;
cout << endl;
}


 

while (next_permutation(a, a + n));
cout<<"The minimum cost of job assignment is "<<max<<endl;


 

do{
int sigma=0;int j=0;
for(int i = 0; i<n ; i++){
sigma=sigma + arr[j][a[i]];
j++;


 

}
if (sigma==max)
{
for(int i = 0; i<n ; i++)
cout<<i+1<<"th person gets job number "<<a[i]+1<<" "<<endl;
}
//break;
}
while(next_permutation(a, a + n));


 

return 0;
}