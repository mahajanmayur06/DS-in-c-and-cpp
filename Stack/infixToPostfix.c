#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, char ch)
{
    if (isFull(s) == 0)
    {
        s->top++;
        s->arr[s->top] = ch;
    }
    else
        printf("Stack Overflow\n");
}

char pop(struct stack *s)
{
    if (isEmpty(s) == 0)
    {
        char ch = s->arr[s->top];
        s->top--;
        return ch;
    }
    else
        printf("Stack Undeflow\n");
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%')
        return 1;
    else
        return 0;
}
    
char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int isOperand(char a)
{
    if ('a' <= a && a <= 'z')
        return 1;
    if ('A' <= a && a <= 'Z')
        return 1;
}
int precedence(char a)
{
    if (a == '%')
        return 4;
    if (a == '*' || a == '/')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    else
        return 0;
}

char *InfixToPostfix(char *str)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *exp = (char *)malloc((strlen(str) + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isOperand(str[i]) == 1)
        {
            exp[j++] = str[i];
        }
        else if (str[i] == '(')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')')
        {
            while (isEmpty(s) == 0 && stackTop(s) != '(')
            {
                exp[j++] = pop(s);
            }
            char x = pop(s);
        }
        else if (isOperator(str[i])  == 1)
        {
            while (isEmpty(s) == 0 && precedence(stackTop(s)) >= precedence(str[i]))
            {
                exp[j++] = pop(s);
            }
            push(s, str[i]);
        }
    }

    while (isEmpty(s) == 0)
    {
        exp[j++] = pop(s);
    }

    exp[j++] = '\0';
    free(s->arr);
    free(s);
    return exp;
}

int main()
{
    char *infix = (char *)malloc(sizeof(char) * 30);
    printf("Enter infix:  ");
    scanf("%s", infix);
    char *postfix = InfixToPostfix(infix);
    // printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    return 0;
}