#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

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

struct node *create(int val)
{
    struct node *ptr = new struct node();
    ptr->data = val;
    ptr->left = ptr->right = NULL;
    return ptr;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        return create(val);
    }

    if (root->data == val)
    {
        cout << "Same data can't be added !" << endl;
        return root;
    }

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

int search(struct node *root, int val)
{
    if (root == NULL)
    {
        cout << endl
             << "Value " << val << " is not found !!" << endl;
        ;
        return val;
    }

    if (val == root->data)
    {
        cout << endl
             << "Value " << val << " is found !!" << endl;
        return val;
    }

    if (val > root->data)
        return search(root->right, val);

    else
        return search(root->left, val);
}

struct node *minValue(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int val)
{
    if (root == NULL)
        return root;

    if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 35);
    root = insert(root, 12);
    root = insert(root, 78);
    root = insert(root, 64);
    root = insert(root, 52);

    cout << "\nPreOrder : ";
    preOrder(root);
    search(root, 64);

    root = deleteNode(root, 64);
    preOrder(root);
    return 0;
}