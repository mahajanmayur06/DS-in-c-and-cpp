#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void PrintLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        // ptr = (*ptr).next;
    }
}

struct Node *insertAtBiginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    head->prev = ptr;
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
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

int main()
{
    struct Node *head, *first, *second, *ptr;
    head = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 19;
    head->next = NULL;
    head = insertAtBiginning(head, 78);
    head = insertAtBiginning(head, 32);
    head = insertAtBiginning(head, 10);
    head = insertAtEnd(head, 49);
    head = insertAtEnd(head, 81);
    head = insertAtEnd(head, 72);
    PrintLinkedList(head);
    return 0;
}
