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

int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteBinary(struct node *root, int index, int noNode)
{
    if (root == NULL)
        return true;

    if (index >= noNode)
        return false;

    return (isCompleteBinary(root->left, 2 * index + 1, noNode) && isCompleteBinary(root->right, 2 * index + 2, noNode));
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

    int countNode = countNodes(A);
    int index = 0;

    if (isCompleteBinary(A, index, countNode))
        cout << "\nIt is a Complete Binary Tree" << endl;
    else
        cout << "\nIt isn't a Complete Binary Tree" << endl;

    return 0;
}