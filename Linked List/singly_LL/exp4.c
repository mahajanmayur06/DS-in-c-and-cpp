#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *insertAtFront(struct Node *head, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = head;
    ptr->prev = NULL;
    return ptr;
}
struct Node *insertAtEnd(struct Node *head, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    if (head == NULL)
    {
        ptr->prev = NULL;
        head = ptr;
    }
    else
    {
        struct Node *p = head;
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        while (p->next != NULL)
        {
            t = p;
            p = p->next;
        }
        p->prev = t;
        p->next = ptr;
    }
    return head;
}
struct Node *insertAtIndex(struct Node *head, int val, int i)
{
    if (i == 0)
    {
        head = insertAtFront(head, val);
        return head;
    }
    int j = 0;
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    while (j != i - 1)
    {
        ptr = ptr->next;
        j++;
    }
    p->data = val;
    p->next = ptr->next;
    ptr->next = p;
    p->prev = ptr;
    return head;
}
struct Node *merge(struct Node *l1, struct Node *l2)
{
    while (l2 != NULL)
    {
        l1 = insertAtEnd(l1, l2->data);
        l2 = l2->next;
    }
    return l1;
}
void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node *sortList(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2;
    int t;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                t = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = t;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
}
int main()
{
    struct Node *h1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *h2 = (struct Node *)malloc(sizeof(struct Node));
    h1->prev = h2->prev = NULL;
    h1->next = h2->next = NULL;
    h1->data = 1;
    h2->data = 2;
    h1 = insertAtFront(h1, 3);
    h2 = insertAtFront(h2, 4);
    h1 = insertAtFront(h1, 5);
    h1 = insertAtFront(h1, 7);
    h2 = insertAtFront(h2, 6);
    h2 = insertAtFront(h2, 8);
    struct Node *list = (struct Node *)malloc(sizeof(struct Node));
    printf("List 1 : ");
    traverse(h1);
    printf("List 2 : ");
    traverse(h2);
    printf("Merged List : ");
    list = merge(h1, h2);
    traverse(list);
    printf("Sorted List : ");
    list = sortList(list);
    traverse(list);
    return 0;
}