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
void PrintLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        // ptr = (*ptr).next;
    }
    printf("\n");
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
struct Node *sortList(struct Node *head)
{
    struct Node *ptr = head, *p;
    int temp;
    while (ptr != NULL)
    {
        p = ptr->next;
        while (p != NULL)
        {
            if (ptr->data > p->data)
            {
                temp = ptr->data;
                ptr->data = p->data;
                p->data = temp;
            }
            p = p->next;
        }
        ptr = ptr->next;
    }
    return head;
}
int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    
    head = insertAtBiginning(head, 56);
    head = insertAtBiginning(head, 84);
    head = insertAtEnd(head, 72);
    head = insertAtEnd(head, 54);
    head = insertAtEnd(head, 13);
    head = insertAtEnd(head, 46);
    PrintLinkedList(head);
    head = sortList(head);
    PrintLinkedList(head);
    return 0;
}
