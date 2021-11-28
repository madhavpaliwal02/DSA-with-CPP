#include <iostream>
using namespace std;

void print(int *A, int high)
{
    for (int i = 0; i < high; i++)
    {
        cout << A[i] << " ";
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

void countSort(int *A, int high)
{
    int i, j;
    int max = maximum(A, high);
    int *count = new int[max + 1];

    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (j = 0; j < high; j++)
    {
        count[A[j]]++;
    }

    i = j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int A[] = {24, 11, 76, 92, 34, 56, 46};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Before Counting Sort : ";
    print(A, n);
    countSort(A, n);
    cout << "\nAfter Counting Sort : ";
    print(A, n);
    return 0;
}