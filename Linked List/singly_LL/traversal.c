#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
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

int main()
{
    struct Node *head, *first, *second,*ptr;
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    ptr = (struct Node *)malloc(sizeof(struct Node));

    head->data = 19;
    head->next = first;

    first->data = 56;
    first->next = second;

    second->data = 29;
    second->next = NULL;

    PrintLinkedList(head);
    return 0;
}
