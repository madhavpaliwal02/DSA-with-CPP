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

bool isFullBinary(struct node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    if ((root->left) && (root->right))
        return (isFullBinary(root->left) && isFullBinary(root->right));

    return false;
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

    if (isFullBinary(A))
        cout << "\nIt is a Full Binary Tree" << endl;
    else
        cout << "\nIt isn't a Full Binary Tree" << endl;

    return 0;
}