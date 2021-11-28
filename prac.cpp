#include <iostream>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *create(int val)
{
    struct node *newnode = new struct node();
    newnode->val = val;
    return newnode;
}

void display(struct node *root)
{
    cout << endl;
    struct node *ptr = root;
    while (ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}

struct node *insertAtFirst(struct node *root, int val)
{
    struct node *ptr = new struct node();
    ptr->val = val;
    ptr->next = root;
    return ptr;
}

struct node *deleteAtFirst(struct node *root)
{
    struct node *ptr = root;
    root = root->next;
    free(ptr);
    return root;
}

struct node *insertAtBetween(struct node *root, int val, int place)
{
    struct node *ptr = new struct node();
    ptr->val = val;
    int i = 1;
    struct node *p = root;
    while (i < place - 1)
    {
        i++;
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
    return root;
}

struct node *deleteAtBetween(struct node *root, int place)
{
    int i = 1;
    struct node *p = root;
    while (i < place - 1)
    {
        i++;
        p = p->next;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return root;
}

struct node *insertAtEnd(struct node *root, int val)
{
    struct node *ptr = new struct node();
    ptr->val = val;

    struct node *p = root;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return root;
}

struct node *deleteAtEnd(struct node *root)
{
    struct node *p = root;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = NULL;
    free(q);
    return root;
}

struct node *insertAfter(struct node *root, int val, struct node *N)
{
    struct node *ptr = new struct node();
    ptr->val = val;

    struct node *p = root;
    while (p != N)
    {
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
    return root;
}

struct node *deleteAfter(struct node *root, struct node *N)
{
    struct node *p = root;
    while (p != N)
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return root;
}

int main()
{
    struct node *root;
    root = create(10);
    struct node *B = create(25);
    struct node *C = create(46);
    struct node *D = create(79);
    struct node *E = create(34);

    root->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = NULL;

    display(root);
    // root = insertAtFirst(root, 54);
    // root = insertAtBetween(root, 54, 3);
    // root = insertAtEnd(root, 54);
    // root = insertAfter(root, 54, C);
    // display(root);

    // root = deleteAtFirst(root);
    // root = deleteAtBetween(root, 3);
    // root = deleteAtEnd(root);
    root = deleteAfter(root, B);
    display(root);
    return 0;
}