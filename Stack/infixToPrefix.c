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
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = ch;
    // printf("%c pushed to stack\n", ch);
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    char ch = s->arr[s->top];
    // printf("%c is popped\n", ch);
    s->top--;
}

int precedence(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    return 0;
}

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int isOperand(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    if (ch >= 'A' && ch <= 'Z')
        return 1;
    if (ch >= '1' && ch <= '9')
        return 1;
    return 0;
}

int isOperater(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}
void infixToPrefix(char *infix)
{
    int i = 0;
    while (infix[i] != '\0')
    {
        i++;
    }
    int n = i;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);
    char *exp = (char *)malloc(sizeof(char) * (i + 1));
    int j = 0;
    while (i >= 0)
    {
        if (isOperand(infix[i]))
        {
            exp[j] = infix[i];
            i--;
            j++;
        }
        else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}')
        {
            push(s, infix[i]);
            i--;
        }
        else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{')
        {
            while (match(infix[i], stackTop(s)) == 0)
            {
                exp[j] = stackTop(s);
                pop(s);
                j++;
            }
            pop(s);
            i--;
        }
        else if (isOperater(infix[i]))
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s,infix[i]);
            }
            else
            {
                while (!isEmpty(s) && isOperater(stackTop(s)) & (precedence(infix[i]) < precedence(stackTop(s))))
                {
                    exp[j] = stackTop(s);
                    pop(s);
                    j++;
                }
                push(s, infix[i]);
            }
            i--;
        }
        else
            i--;
    }
    while (!isEmpty(s))
    {
        exp[j] = stackTop(s);
        pop(s);
        j++;
    }
    exp[j] = '\0';
    n = j - 1;
    while (n >= 0)
    {
        printf("%c", exp[n]);
        n--;
    }
    printf("\n");
}

int main()
{
    printf("Enter infix expression:  ");
    char *infix = (char *)malloc(50 * sizeof(char));
    scanf("%s", infix);
    // printf("Infix : %s\n", infix);
    infixToPrefix(infix);
    return 0;
}