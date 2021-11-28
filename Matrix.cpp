#include <iostream>
#include <conio.h>
using namespace std;
class matrix
{
    int a[3][3], inc = 0;

public:
    void get()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                inc++;
                cout << "Enter " << inc << " element : ";
                cin >> a[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    void operator+(matrix m)
    {
        matrix s;
        int x = 0;
        while (x != 1)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    s.a[i][j] = a[i][j] + m.a[i][j];
                }
            }
            cout << "\nThe sum of two matrix is:" << endl;
            s.display();
            x++;
            break;
        }
    }
    void tran()
    {
        int t;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i > j)
                {
                    t = a[i][j];
                    a[i][j] = a[j][i];
                    a[j][i] = t;
                }
            }
        }
    }
    friend void mul(matrix m1, matrix m2)
    {
        matrix m3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m3.a[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    m3.a[i][j] = m3.a[i][j] + (m1.a[i][k] * m2.a[k][j]);
                }
            }
        }
        cout << "\nMultiply is:" << endl;
        m3.display();
    }
};
int main()
{
    matrix m1, m2, m3, m4;
    // clrscr();
    cout << "\nEnter 1st matrix" << endl;
    m1.get();
    cout << "\nEnter 2nd matrix" << endl;
    m2.get();

    cout << "\nEntered 1st matrix is:" << endl;
    m1.display();
    cout << "\nEntered 2nd matrix is:" << endl;
    m2.display();

    int x = 0, ch = 0;
    while (x == 0)
    {
        cout << "Enter 1 for add, 2 for transpose, 3 for multiply, 4 for exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            m1 + m2;
            break;
        case 2:
            m1.tran();
            m2.tran();
            cout << "\nThe transpose of 1st matrix is:" << endl;
            m1.display();
            cout << "\nThe transpose of 2nd matrix is:" << endl;
            m2.display();
            break;
        case 3:
            mul(m1, m2);
            break;
        case 4:
            cout << endl
                 << "You are Successfully Out !";
            x++;
            break;
        default:
            cout << endl
                 << "Invalid choice !!";
            break;
        }
    }
    return 0;
}