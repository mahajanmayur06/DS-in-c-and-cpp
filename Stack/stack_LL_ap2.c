#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL; // defining it as global variabale

int isEmpty(struct Node *tp)
{
    if (tp == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *tp)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

void print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        // ptr = (*ptr).next;
    }
    printf("\n");
}

struct Node *push(struct Node *tp, int x)
{
    if (isFull(tp))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = tp;
        top = n;
        return top;
    }
}

void *pop(struct Node *tp)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *p = tp;
        top = tp->next;
        int x = p->data;
        printf("Element popped is %d\n", x);
        free(p);
    }
}

int main()
{
    top = push(top, 29);
    top = push(top, 30);
    top = push(top, 12);
    top = push(top, 45);
    print(top);
    pop(top);
    print(top);
    printf("%d", peek(3));
    return 0;
}