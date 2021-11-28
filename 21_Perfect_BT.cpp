#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *ptr, int val)
{
    struct node *newnode = new struct node();
    newnode->data = val;
    return newnode;
}

void print(struct node *ptr)
{
    cout << ptr->data << " ";
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        print(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        print(root);
        inOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        print(root);
    }
}

int depth(struct node *node)
{
    int d = 0;
    while (node != NULL)
    {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfect(struct node *root, int d, int level = 0)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return isPerfect(root->left, d, level + 1) && isPerfect(root->right, d, level + 1);
}

bool isPerfectBinary(struct node *root)
{
    int d = depth(root);
    return isPerfect(root, d);
}

int main()
{
    struct node *A;
    A = create(A, 45);
    struct node *B;
    B = create(B, 16);
    struct node *C;
    C = create(C, 4);
    struct node *D;
    D = create(D, 59);
    struct node *E;
    E = create(E, 78);
    struct node *F;
    F = create(F, 12);
    struct node *G;
    G = create(G, 63);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    C->left = G;

    cout << "\nPreOrder : ";
    preOrder(A);

    cout << "\nInOrder : ";
    inOrder(A);

    cout << "\nPostOrder : ";
    postOrder(A);

    if (isPerfectBinary(A))
        cout << "\nIt is a Perfect Binary Tree" << endl;
    else
        cout << "\nIt isn't a Perfect Binary Tree" << endl;

    return 0;
}