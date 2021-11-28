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

void insertionSort(int *A, int n)
{
    int temp = 0, j = 0;
    for (int i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while (A[j] > temp)
        {
            A[j + 1] = A[j];
            A[j] = temp;
            j--;
        }
        A[j + 1] = temp;
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
    insertionSort(A, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    return 0;
}