#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} node;

struct Node *insertAtEnd(struct Node *head, char n)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = n;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head; // if returns ptr it will become list first node, to return list have to return head
}

void Traverse(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

char deleteAtFront(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return -1;
    }
    else
    {
        struct Node *p = *head;
        char x = p->data;
        *head = p->next;
        free(p);
        return x;
    }
}

char deleteAtEnd(struct Node **head)
{
    struct Node *p = *head, *p1;
    while (p->next != NULL)
    {
        p1 = p;
        p = p->next;
    }
    char x = p->data;
    p1->next = NULL;
    free(p);
    return x;
}
void checkPalindrome(struct Node *s, int n)
{
    char a, b;
    while (s != NULL || s->next != NULL)
    {
    }

    printf("Given string is palindrome\n");
}
int main()
{
    struct Node *head = NULL;
    char *str = "hiit";
    int i = 0;
    while (str[i] != '\0')
    {
        head = insertAtEnd(head, str[i]);
        i++;
    }
    Traverse(head);
    // checkPalindrome(head, i);
    char x = deleteAtEnd(&head);
    char xy = deleteAtEnd(&head);
    char xy1 = deleteAtEnd(&head);
    char xy2 = deleteAtEnd(&head);
    printf("\n");
    Traverse(head);
    free(str);
    return 0;
}
