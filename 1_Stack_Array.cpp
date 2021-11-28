#include <iostream>
using namespace std;
const int size = 10;

class stack
{
    int stack[size], top = -1;

public:
    void push()
    {
        if (top >= size - 1)
        {
            cout << "Stack Overflow !" << endl;
        }
        else
        {
            cout << "Enter element to be push : ";
            cin >> stack[++top];
            cout << "Pushed element is : " << stack[top];
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow !" << endl;
        }
        return stack[top--];
    }
    void display()
    {
        int x = 0;
        cout << endl
             << "The elements in the stack is :" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << "The " << ++x << " element in stack is : " << stack[i] << endl;
        }
    }
};

int main()
{
    stack s;
    int ch, x;

    while (ch != 4)
    {
        cout << "\n\n1. For Pushing"
             << "\n2. For Poping"
             << "\n3. For Display all Elements"
             << "\n4. For Exit"
             << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            x = s.pop();
            if (x != 2)
                cout << "The popped element is : " << x;
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << endl
                 << "You are Successfully Out !";
            break;
        default:
            cout << endl
                 << "Invalid choice !!";
            break;
        }
    }

    return 0;
}