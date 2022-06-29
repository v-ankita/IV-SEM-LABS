#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int index = -1;
    string t, p;
    cout << "Enter the strings" << endl;
    cin >> t >> p;

    int n = t.length();
    int m = p.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && p[j] == t[i + j])
        {
            j++;
        }
        if (j == m)
        {
            index = i;
        }
    }
    cout << index << endl;
}
