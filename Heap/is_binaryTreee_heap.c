#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// for max-binary heap
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int countNodes(struct Node *tree)
{
    if (tree == NULL)
        return 0;
    int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
    return ans;
}
struct Node *create()
{
    struct Node *ptr, *root;
    int data, choice;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nPress 0 to exit: ");
    scanf("%d", &choice);
    if (choice == 0)
        return 0;
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

bool isCBT(struct Node *tree, int index, int count)
{
    if (tree == NULL)
        return true;
    if (index >= count)
        return false;
    if (tree->left == NULL && tree->right != NULL)
        return false;
    else
    {
        bool left = isCBT(tree->left, 2 * index + 1, count);
        bool right = isCBT(tree->right, 2 * index + 2, count);
        return left && right;
    }
}

bool isMaxHeap(struct Node *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return true;
    if (root->right == NULL)
        return (root->data > root->left->data);
    else
    {
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        return left && right && (root->data > root->left->data) && (root->data > root->right->data);
    }
}

int main()
{
    struct Node *tree = create();
    int index = 0;
    int count = countNodes(tree); //  && isCBT(tree,index,count)
    if (isMaxHeap(tree) == true && isCBT(tree, index, count) == true)
        printf("Binary tree is heap\n");
    else
        printf("Binary is tree is not heap or not CBT\n");
    return 0;
}