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

void insert(int *A, int x)
{
    cout << "\nEnter the elements of array :" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "Enter the " << i + 1 << " element : ";
        cin >> A[i];
    }
}

void selectionSort(int *A, int x)
{
    int i, j, min = 0;
    for (i = 0; i < x - 1; i++)
    {
        min = i;
        for (j = i + 1; j < x; j++)
        {
            if (A[min] > A[j])
            {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main()
{
    int A[] = {24, 48, 12, 82, 73, 19, 64};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Before Sorting : ";
    print(A, n);
    selectionSort(A, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    return 0;
}