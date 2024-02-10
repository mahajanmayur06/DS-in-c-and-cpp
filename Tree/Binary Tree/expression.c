#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};
struct Stack
{
    int size;
    int top;
    struct Node **arr;
};
struct Node *getNode(char data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void inorder(struct Node *tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    printf("%c ", tree->data);
    inorder(tree->right);
}
void preorder(struct Node *tree)
{
    if (tree == NULL)
        return;
    printf("%c ", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}
void postorder(struct Node *tree)
{
    if (tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%c ", tree->data);
}
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return true;
    return false;
}
void push(struct Stack *s, struct Node *n)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflowed!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = n;
    }
}
void pop(struct Stack *s)
{
    if (s->top == -1)
        printf("Stack is empty\n");
    else
    {
        s->top--;
    }
}
struct Node *exptree(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = i;
    s->arr = (struct Node **)malloc(sizeof(struct Node *) * s->size);
    while (i >= 0)
    {
        if (isOperator(str[i]))
        {
            struct Node *root1 = getNode(str[i]);
            root1->left = s->arr[s->top];
            pop(s);
            root1->right = s->arr[s->top];
            pop(s);
            push(s, root1);
        }
        else
        {
            struct Node *root2 = getNode(str[i]);
            push(s, root2);
        }
        i--;
    }
    return s->arr[s->top];
}
int evaluate(struct Node *tree)
{
    if (tree == NULL)
        return 0;
    if (tree->data == '+')
        return evaluate(tree->left) + evaluate(tree->right);
    else if (tree->data == '-')
        return evaluate(tree->left) - evaluate(tree->right);
    else if (tree->data == '*')
        return evaluate(tree->left) * evaluate(tree->right);
    else if (tree->data == '/')
        return evaluate(tree->left) / evaluate(tree->right);
    else
        return tree->data - '0';
}
int main()
{
    char pre[30];
    printf("Enter prefix: ");
    scanf("%s", pre);
    struct Node *tree = exptree(pre);
    printf("\nInorder traversal: ");
    inorder(tree);
    printf("\nPreorder traversal: ");
    preorder(tree);
    printf("\n");
    printf("\n");
    printf("Evaluation: %d", evaluate(tree));
    return 0;
}