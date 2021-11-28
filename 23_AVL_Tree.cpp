#include <iostream>
using namespace std;

class node
{
public:
    int key, height;
    node *left, *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

node *create(int key)
{
    struct node *newnode = new struct node();
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBF(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *insertNode(node *N, int key)
{
    if (N == NULL)
        return create(key);

    if (key < N->key)
        N->left = insertNode(N->left, key);

    else if (key > N->key)
        N->right = insertNode(N->right, key);
    else
        return N;

    N->height = max(height(N->left), height(N->right)) + 1;
    int BF = getBF(N);

    if (BF > 1)
    {
        if (key < N->left->key)
            return rightRotate(N);
        else if (key > N->left->key)
        {
            N->left = leftRotate(N->left);
            return rightRotate(N);
        }
    }

    if (BF < 1)
    {
        if (key > N->right->key)
            return leftRotate(N);
        else if (key < N->right->key)
        {
            N->right = rightRotate(N->right);
            return leftRotate(N);
        }
    }
    return N;
}

node *minKeyNode(node *N)
{
    node *current = N;
    while (current->left != NULL)
        current = current->left;
    return current;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;

    if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            node *temp = minKeyNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int BF = getBF(root);

    if (BF > 1)
    {
        if (getBF(root->left) >= 0)
            return rightRotate(root);
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (BF < 1)
    {
        if (getBF(root->right) <= 0)
            return leftRotate(root);
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

void print(node *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "    ";
        }
        else
        {
            cout << "L----";
            indent += "|    ";
        }
        cout << root->key << endl;
        print(root->left, indent, false);
        print(root->right, indent, true);
    }
}

int main()
{
    node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 49);
    root = insertNode(root, 37);
    root = insertNode(root, 76);
    root = insertNode(root, 28);
    root = insertNode(root, 83);
    root = insertNode(root, 19);
    root = insertNode(root, 96);
    root = insertNode(root, 156);
    root = insertNode(root, 31);
    root = insertNode(root, 48);

    print(root, "", true);
    return 0;
}