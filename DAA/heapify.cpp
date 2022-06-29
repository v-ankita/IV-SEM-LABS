#include <iostream>

using namespace std;
 
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}
// int Delete(int A[], int n){
//     int x = A[0];  // Max element
//     A[0] = A[n-1];
 
//     int i = 0;
//     int j = 2 * i + 1;
 
//     while (j < n-1){
//         // Compare left and right children
//         if (A[j] < A[j+1]){
//             j = j+1;
//         }
 
//         // Compare parent and largest child
//         if (A[i] < A[j]){
//             swap(A, i, j);
//             i = j;
//             j = 2 * i + 1;
//         } else {
//             break;
//         }
//     }
//     return x;
// }
 
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int main() {
 
 int i=0, n=0;

    cout<<"Enter number of elements: ";
    cin>>n;
    int H[100];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    cin>>H[i];
 
    Heapify(H, n);
    Print(H, n, "Heapified list");
 
   for (i = n; i >1; i--)
    {
        Delete(H, i);
    }
    for (i = 0; i < n; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}