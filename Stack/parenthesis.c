#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int size;
    int top;
    char *arr;
} stack;

bool isFull(stack *s)
{
    if (s->top == s->size - 1)
        return true;
    return false;
}
bool isEmpty(stack *s)
{
    if (s->top == -1)
        return true;
    return false;
}

void push(stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}
char pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    char data = s->arr[s->top];
    s->top--;
    return data;
}
char stacktop(stack *s)
{
    return s->arr[s->top];
}
bool match(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    return false;
}
int isOperand(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
    {
        return 1;
    }
    return 0;
}
void parenthesis(char *str)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);
    int i = 0, j, a = -1, b = -1, c = -1;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            push(s, str[i]);
            a = i;
        }
        else if (str[i] == '[')
        {
            push(s, str[i]);
            b = i;
        }
        else if (str[i] == '{')
        {
            push(s, str[i]);
            c = i;
        }
        else if (str[i] == ')' && match(stacktop(s), str[i]) == 1)
        {
            printf("Bracket Match found: '(' at %d and ')' at %d\n", a, i);
            pop(s);
            a = -1;
        }
        else if (str[i] == ']' && match(stacktop(s), str[i]) == 1)
        {
            printf("Bracket Match found: '[' at %d and ']' at %d\n", b, i);
            pop(s);
            b = -1;
        }
        else if (str[i] == '}' && match(stacktop(s), str[i]) == 1)
        {
            printf("Bracket Match found: '{' at %d and '}' at %d\n", c, i);
            pop(s);
            c = -1;
        }

        else
            printf("Bracket match not found for %c\n", str[i]);
        i++;
    }
    if (a >= 0)
    {
        printf("Bracket not found: '(' on %d\n", a);
    }
    if (b >= 0)
    {
        printf("Bracket not found: '[' on %d\n", b);
    }
    if (c >= 0)
    {
        printf("Bracket not found: '{' on %d\n", c);
    }
}
int main()
{
    char exp[30];
    printf("Enter expression\n");
    scanf("%s", exp);
    parenthesis(exp);
    return 0;
}