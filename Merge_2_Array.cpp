#include <iostream>
using namespace std;

void merge(int A[], int B[], int C[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;

    while (i <= m && j <= n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j <= n)
    {
        C[k] = B[j];
        j++;
        k++;
    }
}

int main()
{
    int A[] = {2, 7, 9, 16, 24, 32};
    int B[] = {4, 8, 11, 19, 23, 28};

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int C[m + n];

    merge(A, B, C, m, n);

    cout << "The elements after merging two sorted array are :" << endl;
    for (int i = 0; i <= m + n; i++)
    {
        cout << C[i] << " ";
    }

    return 0;
}