#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *top)
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

struct Node *push(struct Node** top, int x){
    if(isFull(*top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = *top;
        *top = n;
        return *top;
    }
}

void *pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* p = * top;
        *top = (*top)->next;
        int x = p->data;
        printf("Element popped is %d\n", x);
        free(p);
    }
}

int main()
{
    struct Node *top = (struct Node*)malloc(sizeof(struct Node*));
    top = NULL;
    top = push(&top, 29); 
    top = push(&top, 30);
    top = push(&top, 12);
    top = push(&top, 45);
    print(top);
    pop(&top);
    print(top);
    return 0;
}