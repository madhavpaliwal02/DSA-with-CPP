#include <iostream>
using namespace std;

class Search
{
    int ele[100];

public:
    void Input(int);
    int LinearSearch(int item, int);
};

void Search::Input(int x)
{
    int i = 0;
    cout << "\nEnter Items : \n";
    for (i = 0; i < x; i++)
    {
        cout << "Enter Element (" << i + 1 << ") : ";
        cin >> ele[i];
    }
}

int Search::LinearSearch(int item, int x)
{
    int POS = -1;
    int LOC = 0;
    for (LOC = 0; LOC < x; LOC++)
    {
        if (ele[LOC] == item)
        {
            POS = LOC;
            break;
        }
    }
    return POS;
}

int main()
{
    int i = 0, x = 0;
    int item;
    int pos;

    Search s = Search();
    cout << "Enter the total no of elements to be stored : ";
    cin >> x;
    s.Input(x);

    cout << "\n\nEnter Item To Be Searched : ";
    cin >> item;

    pos = s.LinearSearch(item, x);

    if (pos >= 0)
    {
        cout << "\nItem Found At Position : " << pos + 1 << endl;
    }
    else
    {
        cout << "\nItem Not Found In The List\n";
    }

    return 0;
}