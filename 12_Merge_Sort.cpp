#include <iostream>
using namespace std;

void insert(int *A, int x)
{
    cout << "\nEnter the elements of array :" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "Enter the " << i + 1 << " element : ";
        cin >> A[i];
    }
}

void print(int A[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << A[i] << " ";
        i++;
    }
}

void merge(int *A, int low, int mid, int high)
{
    int i, j, k;
    i = k = low;
    j = mid + 1;
    int C[high + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            C[k] = A[i];
            k++;
            i++;
        }
        else
        {
            C[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        C[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        C[k] = A[j];
        k++;
        j++;
    }
    for (int x = low; x < high + 1; x++)
    {
        A[x] = C[x];
    }
}

void mergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[100];
    int n = 0;
    cout << "Enter the no of elements to be stored in the array : ";
    cin >> n;
    insert(A, n);
    cout << "Before Sorting : ";
    print(A, n);
    mergeSort(A, 0, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    return 0;
}