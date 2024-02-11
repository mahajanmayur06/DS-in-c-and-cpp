#include <stdio.h>
#include <stdlib.h>

void insert(int *hashTable, int m, int c1, int c2)
{
    int in;
    printf("Enter value to be inserted: ");
    scanf("%d", &in);
    int i = 0;
    while (1)
    {
        if (hashTable[((in % m) + c1 * i + c2 * i * i) % m] != -1)
            i++;
        else
        {
            hashTable[((in % m) + c1 * i + c2 * i * i) % m] = in;
            break;
        }
    }
}
void find(int *hashTable, int m, int c1, int c2, int num)
{
    int i = 0;
    int x = num % m;
    while (hashTable[x] != num)
        x = ((num % m) + c1 * i + c2 * i * i) % m;
    printf("%d found at index %d\n", num, x);

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
    int n, c1, c2;
    scanf("%d", &n);
    c1 = c2 = 1;
    if (n > m)
    {
        printf("Cannot insert values greater than array size\n");
        return 0;
    }
    // printf("Enter c1 and c2 for quadratic probing : ");
    // scanf("%d %d", &c1, &c2);
    int *hashTable = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
    for (int i = 0; i < n; i++)
        insert(hashTable, m, c1, c2);
    display(hashTable, m);

    int num;
    scanf("%d", &num);
    // find(hashTable, m,c1,c2,num);
    free(hashTable);
    return 0;
}