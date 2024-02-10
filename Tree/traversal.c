#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
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
    printf("%d ", tree->data);
}
int height(struct Node *tree)
{
    if (tree == NULL)
        return 0;
    int left = height(tree->left);
    int right = height(tree->right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}
int minimum(struct Node *tree)
{
    if (tree->left == NULL)
        return tree->data;
    return (minimum(tree->left));
}
int maximum(struct Node *tree)
{
    if (tree->right == NULL)
        return tree->data;
    return (maximum(tree->right));
}

struct Node *insertion(struct Node *tree, int data)
{
    struct Node *node, *parent, *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
        return ptr;
    node = tree;
    while (node != NULL)
    {
        parent = node;
        if (node->data == data)
            return tree;
        if (data < node->data)
            node = node->left;
        else
            node = node->right;
    }
    if (data < parent->data)
        parent->left = ptr;
    else
        parent->right = ptr;
    return tree;
}

int parent(struct Node *tree, int data)
{
    if (tree == NULL)
        return -1;
    struct Node *p = tree;
    struct Node *ptr = NULL;
    while (p->data != data)
    {
        if (p->data > data)
        {
            ptr = p;
            p = p->left;
        }
        else
        {
            ptr = p;
            p = p->right;
        }
        if (p == NULL)
            return -1;
    }
    return ptr->data;
}

int main()
{
    struct Node *tree = (struct Node *)malloc(sizeof(struct Node));
    tree = NULL;
    int num = 0;
    printf("Insert values in tree\n");
// 21, 18,33,35, 20, 13,41,55.
    tree = insertion(tree, 21);
    tree = insertion(tree, 18);
    tree = insertion(tree, 33);
    tree = insertion(tree, 35);
    tree = insertion(tree, 20);
    tree = insertion(tree, 13);
    tree = insertion(tree, 41);
    tree = insertion(tree, 55);
    // tree = insertion(tree, 91);
    // tree = insertion(tree, 21);
    // tree = insertion(tree, 23);
    printf("Preorder: ");
    preorder(tree);
    printf("\nPostorder: ");
    postorder(tree);
    printf("\nInorder: ");
    inorder(tree);
    printf("\nHeight of the Tree is %d", height(tree));
    printf("\nThe minimum value of in tree is %d\n", minimum(tree));
    printf("The maximum value of in tree is %d\n", maximum(tree));
    printf("Parent of 21 is %d\n", parent(tree,100));
    return 0;
}