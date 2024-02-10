#include <stdio.h>
#include <stdlib.h>
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
    printf("%d ", tree->data);
}
struct Node *create()
{
    struct Node *ptr, *root;
    int data, choice;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nPress 0 to exit: ");
    scanf("%d", &choice);
    if (choice == 0)
    {
        return 0;
    }
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        ptr->data = data;
        printf("\nEnter the left child of %d ", data);
        ptr->left = create();
        printf("\nEnter the right child of %d ", data);
        ptr->right = create();
        return ptr;
    }
}
void checkLeafNode(struct Node *tree)
{
    if (tree->left == NULL && tree->right == NULL)
    {
        printf("There is a leaf node %d\n", tree->data);
        return;
    }
    checkLeafNode(tree->left);
    checkLeafNode(tree->right);
}
void delete(struct Node *tree, int data)
{
    if (tree->data == data)
    {
        free(tree);
        return;
    }
    if (data < tree->data)
        delete (tree->left, data);
    else
        delete (tree->right, data);
}
int main()
{
    struct Node *tree = create();
    inorder(tree);
    printf("\n");
    checkLeafNode(tree);
    printf("\n");
    delete(tree,34);
    inorder(tree);
    return 0;
}