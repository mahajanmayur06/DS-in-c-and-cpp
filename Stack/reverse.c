#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    char *arr;
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

void push(struct Stack *s, char data)
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
        char val = s->arr[s->top];
        s->top--;
        // printf("%c is popped from stack\n", val);
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

char stacktop(struct Stack *s)
{
    return s->arr[s->top];
}

void reverse(char *str)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 30;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);
    int i = 0;
    while (str[i] != '\0')
    {
        push(s, str[i]);
        i++;
    }
    int j = 0;
    while (isEmpty(s) == 0)
    {
        str[j] = stacktop(s);
        j++;
        pop(s);
    }
    str[j] = '\0';
    printf("Reverse string; %s\n", str);
}
int main()
{
    printf("Enter a string\n");
    char *str;
    str = (char *)malloc(30 * sizeof(char));
    scanf("%s", str);
    reverse(str);
    return 0;
}