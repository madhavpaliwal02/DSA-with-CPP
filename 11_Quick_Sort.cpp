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

int partition(int *A, int low, int high)
{
    int pivot = 0, temp, i = low + 1, j = high;
    pivot = A[low];
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[j];
    A[j] = A[low];
    A[low] = temp;
    return j;
}

void quickSort(int *A, int low, int high)
{
    int partIndex = 0;
    if (high > low)
    {
        partIndex = partition(A, low, high);
        quickSort(A, low, partIndex - 1);
        quickSort(A, partIndex + 1, high);
    }
}

int main()
{
    int A[100];
    int n = 0;
    cout << "Enter the no of elements to be stored in the array : ";
    cin >> n;
    insert(A, n);
    cout << "\nBefore Sorting : ";
    print(A, n);
    quickSort(A, 0, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    return 0;
}