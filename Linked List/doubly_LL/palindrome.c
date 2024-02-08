#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
};
struct Node *insertAtBiginning(struct Node *head, char data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    head->prev = ptr;
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, char data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    ptr->next = NULL;
    while (p->next != NULL)
        p = p->next;
    ptr->prev = p;
    p->next = ptr;
    return head;
}
int palindrome(struct Node *head, struct Node *tail)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = tail;
    int i=0;
    printf("%c %c\n", head->data, tail->data);
    while ((ptr1 != ptr2))
    {
        printf("%d ", i);
        if(ptr1->data != ptr2->data)
            return 0;
        ptr1 = ptr1->next;
        ptr2 = ptr2->prev;
        i++;
    }
    return 1;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = 'l';
    head->next = NULL;
    head = insertAtEnd(head, 'e');
    head = insertAtEnd(head, 'v');
    head = insertAtEnd(head, 'x');
    head = insertAtEnd(head, 'e');
    head = insertAtEnd(head, 'l');
    // head = insertAtEnd(head, 'a');
    struct Node *tail, *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    tail = ptr;
    if (palindrome(head,tail) == 1)
        printf("PALINDROME");
    else
        printf("Your girlfriend is beautiful");
    return 0;
}