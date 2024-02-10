#include <stdio.h>
#include <stdlib.h>
int COUNT = 10;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void preorder(struct Node *tree)
{
    if (tree == NULL)
        return;
    printf("%d ", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

void inorder(struct Node *tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

void postorder(struct Node *tree)
{
    if (tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    pritf("%d ", tree->data);
}
struct Node *insert(struct Node *tree, int data)
{
    struct Node *ptr, *parent, *node;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
    }
    else
    {
        node = tree;
        parent = NULL;
        while (node != NULL)
        {
            parent = node;
            if (data < node->data)
                node = node->left;
            else
                node = node->right;
        }
        if (data < parent->data)
            parent->left = ptr;
        else
            parent->right = ptr;
    }
    return tree;
}
 
int main()
{
    struct Node *tree = NULL;
    tree = insert(tree, 42);
    tree = insert(tree, 35);
    tree = insert(tree, 38);
    tree = insert(tree, 30);
    tree = insert(tree, 28);
    tree = insert(tree, 32);
    tree = insert(tree, 50);
    tree = insert(tree, 48);
    tree = insert(tree, 54);
    tree = insert(tree, 52);
    tree = insert(tree, 60);
    tree = insert(tree, 34);
    inorder(tree);
    print2D(tree);
    return 0;
}