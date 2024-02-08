#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

struct Node *insertAtBiginning(struct Node *head, int n)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = n;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int n)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = n;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head; // if returns ptr it will become list first node, to return list have to return head
}

struct Node *insertAtIndex(struct Node *head, int n, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    struct Node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = n;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prev, int n)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = prev;
    ptr->data = n;
    ptr->next = prev->next;
    prev->next = ptr;
    return head;
}

void PrintLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        // ptr = (*ptr).next;
    }
}

struct Node *deleteAtFront(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head, *p1;
    while (p->next != NULL)
    {
        p1 = p;
        p = p->next;
    }
    p1->next = NULL;
    free(p);
    return head;
}
int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    // head->data = 31;
    // head->next = NULL;
    // head = insertAtBiginning(head, 29);
    // printf("Before insertion:\n");
    // PrintLinkedList(head);
    // printf("\nAfter insertion\n");
    // head = insertAtBiginning(head, 89);
    // head = insertAtBiginning(head, 49);
    // head = insertAtIndex(head, 45, 4);
    // head = insertAtEnd(head, 81);
    // PrintLinkedList(head);
    // printf("\nAfter deletion\n");
    // head = deleteAtFront(head);
    // head = deleteAtEnd(head);
    head = NULL;
    head = insertAtEnd(head, 12);
    PrintLinkedList(head);
    return 0;
}
