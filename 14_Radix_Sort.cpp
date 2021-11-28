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

int maximum(int *A, int high)
{
    int max = 0;
    for (int i = 0; i < high; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int size, int pos)
{
    int count[10] = {0}, output[size], i;

    for (i = 0; i < size; i++)
        count[(A[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)

        count[i] = count[i] + count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(A[i] / pos) % 10] - 1] = A[i];
        count[(A[i] / pos) % 10]--;
    }

    for (int i = 0; i < size; i++)
        A[i] = output[i];
}

void radixSort(int *A, int size)
{
    int max = maximum(A, size);
    for (int pos = 1; max / pos > 0; pos *= 10)
        countSort(A, size, pos);
}

int main()
{
    int A[] = {24, 48, 12, 82, 73, 19, 64};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Before Sorting : ";
    print(A, n);
    radixSort(A, n);
    cout << "\nAfter Sorting : ";
    print(A, n);
    return 0;
}