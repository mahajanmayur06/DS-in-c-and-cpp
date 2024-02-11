#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtEnd(struct Node *ptr, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if (ptr == NULL)
        return p;
    struct Node *h = ptr;
    while (h->next != NULL)
    {
        h = h->next;
    }
    h->next = p;
    return ptr;
}

void find(struct Node ht[], int m, int num)
{
    int x = num % m;
    int i = 0;
    struct Node *ptr = &ht[x];
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            printf("%d found at position %d from index %d of array\n", num, i+1, x);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    return;
}
void insert(struct Node ht[], int m)
{
    int in;
    printf("Enter value to be inserted: ");
    scanf("%d", &in);
    if (ht[in % m].data == -1)
    {
        ht[in % m].data = in;
    }
    else
    {
        ht[in % m].next = insertAtEnd(ht[in % m].next, in);
    }
}

void display(struct Node ht[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("Index %d: ", i);
        struct Node *ptr = &ht[i];
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter maximum size of hash Table\n");
    int m;
    scanf("%d", &m);
    printf("Enter numbers of elements to be inserted\n");
    int n;
    scanf("%d", &n);
    struct Node *hashTable = (struct Node *)malloc(sizeof(struct Node) * m);
    for (int i = 0; i < m; i++)
    {
        hashTable[i].data = -1;
        hashTable[i].next = NULL;
    }
    for (int i = 0; i < n; i++)
        insert(hashTable, m);
    display(hashTable, m);
    printf("Enter numbers to find\n");
    int num1,num2;
    scanf("%d %d", &num1, &num2);
    find(hashTable, m,num1);
    find(hashTable, m,num2);
    free(hashTable);
    return 0;
}