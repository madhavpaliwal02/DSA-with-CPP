#include <iostream>
using namespace std;

void print(int A[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << A[i] << " ";
        i++;
    }
}

void bubbleSortAd(int *A, int n)
{
    int i, j, temp, isSorted = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            isSorted = -1;
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}

int binSer(int *A, int low, int size, int val)
{
    if (low <= size)
    {
        int mid = low + (size - low) / 2;
        if (val == A[mid])
            return mid;

        if (val < A[mid])
            return binSer(A, 0, mid - 1, val);

        return binSer(A, mid + 1, size, val);
    }
    return -1;
}

int main()
{
    int A[] = {12, 46, 11, 34, 85, 29, 78, 73, 55, 43, 92, 38, 24, 67};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "\nBefore Sorting : ";
    print(A, n);
    bubbleSortAd(A, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    int found = binSer(A, 0, 11, 73);
    if (found == -1)
        cout << "\nNot Found !!!";
    else
        cout << "\nFound at position " << found + 1 << " !!!";
    return 0;
}