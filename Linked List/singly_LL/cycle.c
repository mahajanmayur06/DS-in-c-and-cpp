#include <stdio.h>
#include <stdlib.h>
// Floyd's Cycle or 'Tortois and hare algorithm'
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
int detect_cycle(struct Node *head)
{
    struct Node *fast = head;
    struct Node *slow = head;
    int pos = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
                pos++;
            }
            return pos;
        }
    }
    return -1;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 56;
    head->next = first;

    first->data = 92;
    first->next = second;

    second->data = 13;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 13;
    fourth->next = third;

    int x = detect_cycle(head);
    if (x == -1)
    {
        printf("NO Cycle detected\n");
    }
    else
    {
        printf("Cycle at %d position\n", x);
    }
    return 0;
}
