#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
struct Node *swap(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode = NULL;
    while (current != NULL && current->next != NULL)
    {
        nextNode = current->next;
        current->next = nextNode->next;
        nextNode->next = current;
        if (prev != NULL)
        {
            prev->next = nextNode;
        }
        else
        {
            head = nextNode;
        }
        prev = current;
        current = current->next;
    }
    return head;
}
int main()
{
    struct Node *head = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    printf("Original Linked List: ");
    printList(head);
    head = swap(head);
    printf("Linked List after swapping adjacent elements: ");
    printList(head);
    return 0;
}