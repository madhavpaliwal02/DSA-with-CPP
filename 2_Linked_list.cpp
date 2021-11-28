#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *head)
{
    cout << endl;
    while (head != NULL)
    {
        cout << "The element is : " << head->data << endl;
        head = head->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = new struct Node();
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtBetween(struct Node *head, int data, int place)
{
    struct Node *ptr = new struct Node();
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    while (i != place - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = new struct Node();
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *pNode, int data)
{
    struct Node *ptr = new struct Node();
    ptr->data = data;

    ptr->next = pNode->next;
    pNode->next = ptr;
    return head;
}

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtBetween(struct Node *head, int place)
{
    struct Node *ptr = head;
    int i = 0;
    while (i != place - 2)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtNode(struct Node *head, struct Node *pNode)
{
    struct Node *ptr = head;
    struct Node *q = pNode;
    while (ptr->next != pNode)
    {
        ptr = ptr->next;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = new struct Node();
    second = new struct Node();
    third = new struct Node();

    head->data = 10;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 47;
    third->next = NULL;

    traverse(head);
    head = insertAtFirst(head, 45);
    head = insertAtBetween(head, 78, 2);
    // head = insertAtEnd(head, 78);
    // head = insertAfterNode(head, second, 78);
    // head = deleteAtFirst(head);
    // head = deleteAtBetween(head, 2);
    // head = deleteAtEnd(head);
    // head = deleteAtNode(head, second);
    // cout << "\nAfter deleting :";
    traverse(head);

    return 0;
}