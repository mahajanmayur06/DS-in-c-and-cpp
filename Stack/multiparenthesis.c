#include <stdio.h>
#include <stdlib.h>

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

struct stack *push(struct stack *s, char ch)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = ch;
        return s;
    }
    else
        printf("Stack Overflow\n");
}

char pop(struct stack *s)
{
    if (!isEmpty(s))
    {
        char ch = s->arr[s->top];
        s->top--;
        return ch;
    }
    // else
    //     printf("Stack Undeflow\n");
}

int match(char x, char y)
{
    if ((x == '(') && (y = ')'))
    {
        return 1;
    }
    if ((x == '[') && (y = ']'))
    {
        return 1;
    }
    if ((x == '{') && (y = '}'))
    {
        return 1;
    }
    return 0;
}

int paranthesis_matching(char *str)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            char ch = pop(s);
            if (match(ch, str[i]))
            {
                return 1;
            }
            else
                return 0;
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    char *str = "([8+40])";
    if (paranthesis_matching(str))
    {
        printf("Parenthesis is matching\n");
    }
    else
        printf("parenthesis is not matching\n");
    return 0;
}