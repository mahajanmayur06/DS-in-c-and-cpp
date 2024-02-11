#include <stdio.h>
#include <stdlib.h>

void insert(int *hashTable, int m)
{
    int in;
    printf("Enter value to be inserted: ");
    scanf("%d", &in);
    int i = 0;
    while (1)
    {
        if (hashTable[(in % m) + i] != -1)
            i++;
        else
        {
            hashTable[(in % m) + i] = in;
            break;
        }
    }
}

void display(int *hashTable, int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("Index %d : %d\n", i, hashTable[i]);
    }
    printf("\n");
}
int main()
{
    printf("Enter maximum size of hash Table\n");
    int m;
    scanf("%d", &m);
    printf("Enter numbers of elements to be inserted\n");
    int n;
    scanf("%d", &n);
    if (n > m)
    {
        printf("Cannot insert values greater than array size\n");
        return 0;
    }
    int *hashTable = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
    for (int i = 0; i < n; i++)
        insert(hashTable, m);
    display(hashTable, m);
    free(hashTable);
    return 0;
}