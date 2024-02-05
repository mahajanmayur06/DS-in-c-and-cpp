#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void printStack(struct Stack *s)
{
    int i = 0;
    while (i != s->top + 1)
    {
        printf("%d ", s->arr[i]);
        i++;
    }
    printf("\n");
}

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int data)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = data;
    }
    else
    {
        printf("Stack Overflow Cannot add %d to Stack\n", data);
    }
}

void pop(struct Stack *s)
{
    if (!isEmpty(s))
    {
        int val = s->arr[s->top];
        s->top--;
        printf("%d is popped from stack\n", val);
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

int peek(struct Stack *s, int index)
{
    int n = s->top - index + 1;
    if (n < 0)
    {
        return -1;
    }
    return s->arr[n];
}

int stackTop(struct Stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct Stack *s)
{
    return s->arr[0];
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 5; // n
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->arr[0] = 83;
    s->top++;
    printf("Before Operation\n");
    printStack(s);
    printf("\nAfter Operation\n");
    push(s, 67);   // 83 67
    push(s, 32);   // 83 67 32
    push(s, 11);   // 83 67 32 11
    push(s, 42);   // 83 67 32 11 42
    push(s, 31);   // Stack is overflowed cannot add 31
    pop(s);        // Last In First Out it popped 42 when n = 5
    printStack(s); // 83 67 32 11
    // printf("%d is peeked from stack for %d index\n", peek(s,3), 3);
    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("Element at %d position from stack is %d\n", i, s->arr[s->top - i + 1]);
    }

    return 0;
}
