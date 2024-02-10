#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int arr1[6],arr2[6];
int i = 0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *initialize(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
}
struct node *create()
{
    struct node *temp, *root;
    int data, choice;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nPress 0 to exit");
    printf("\nPress 1 for new node");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    if (choice == 0)
        return 0;
    else
    {
        printf("Enter the data:");
        scanf("%d", &data);
        temp->data = data;
        printf("\nEnter the left child of %d", data);
        temp->left = create();
        printf("\nEnter the right child of %d", data);
        temp->right = create();
        return temp;
    }
}
void inorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d", root->data);
    arr1[i] = root->data;
    inorder_traversal(root->right);
    i++;
}
void checkmirror(int arr1[],int arr2[])
{
    for (int i = 0; i < 6; i++)
    {
        if (arr1[i] == arr1[i])
            continue;
        if (arr1[i] != arr1[i])
        {
            printf("\nNot Identical\n");
            return;
        }
    }
    printf("\nOriginal and Mirrored Trees are Identical\n");
}
void mirror(struct node *root)
{
    if (root == NULL)
        return;
    struct node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
int main()
{
    printf("Create a binary tree\n");
    struct node *root = create();
    printf("\n");
    printf("\n\nEnter values of mirror tree\n");
    struct node *root2 = create();
    printf("**Inorder Traversal of Original Tree: ");
    inorder_traversal(root);
    printf("\n**Inorder Traversal of Mirror Tree: ");
    mirror(root);
    inorder_traversal(root);
    printf("\n**Inorder Traversal of mirrored tree: ");
    inorder_traversal(root2);
    printf("\n*******");
    checkmirror(arr1,arr2);
    return 0;
}
