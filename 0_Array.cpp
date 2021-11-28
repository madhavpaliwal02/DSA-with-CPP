#include <iostream>
#include <conio.h>
using namespace std;
class arr
{
    int a[100];ff

public:
    void insert(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter the " << i << " element : ";
            cin >> a[i - 1];
        }
    }
    void display(int n)
    {
        cout << endl
             << "Entered elements are: " << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "Element " << i << " is : " << a[i - 1] << endl;
        }
    }
    void maxElement(int);
    void minElement(int);
    void search(int);
};
void arr::search(int n)
{
    int num;
    cout << endl
         << "Enter the searching number : ";
    cin >> num;

    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] == num)
            cout << "The element is Found";
        else
            cout << "The element is Not Found";
    }
}

void arr::maxElement(int n)
{
    int t = 0; //temp
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    cout << "Max element in the array is: " << a[n - 1] << endl;
}

void arr::minElement(int n)
{
    int t = 0; //temp
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    cout << "Min element in the array is: " << a[0] << endl;
}

int main()
{
    arr a1;
    int num = 0, srch = 0, ch = 0, i = 0;
    cout << "Enter the no of elements you have to insert : ";
    cin >> num;
    a1.insert(num);
    a1.display(num);
    while (i == 0)
    {
        cout << "\n1. For Searching an Element"
             << "\n2. For Maximum Element"
             << "\n3. For Minimum Element"
             << "\n4. For Exit"
             << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a1.search(num);
            break;
        case 2:
            a1.maxElement(num);
            break;
        case 3:
            a1.minElement(num);
            break;
        case 4:
            cout << endl
                 << "You are Successfully Out !";
            i++;
            break;

        default:
            cout << "Invalid choice";
            break;
        }
        cout << endl;
    }

    return 0;
}