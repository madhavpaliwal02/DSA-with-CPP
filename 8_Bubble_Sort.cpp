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

void bubbleSort(int *A, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
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

int main()
{
    // int A[] = {24, 48, 12, 82, 73, 19, 64};
    int A[] = {12, 46, 11, 34, 85, 29, 78, 73, 55, 43, 92, 38, 24, 67};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Before Sorting : ";
    print(A, n);
    bubbleSort(A, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    bubbleSortAd(A, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    return 0;
}