#include <stdio.h>
#include <stdlib.h>

struct Hash
{
    int max;
    int *hashTable;
    char *status;
};

void insert(struct Hash *hash, int key)
{
    int i = 0;
    while (1)
    {
        if (hash->hashTable[((key % hash->max) + i) % hash->max] != -1)
            i++;
        else
        {
            hash->hashTable[((key % hash->max) + i) % hash->max] = key;
            hash->status[((key % hash->max) + i) % hash->max] = 'O';
            return;
        }
    }
}

void find(struct Hash *hash, int key)
{
    int i = (key % hash->max) % hash->max;
    printf("finding %d in hash Table: ", key);
    while (hash->hashTable[i] != -1)
    {
        if (hash->hashTable[i % hash->max] == key && hash->status[i] == 'O')
        {
            printf("Success\n");
            return;
        }
        i++;
    }
    printf("Failure\n");
}

void delete(struct Hash *hash, int key)
{
    int i = 0;
    while (1)
    {
        i = ((key % hash->max) + i) % hash->max;
        if (hash->status[i] == 'O')
        {
            if (hash->hashTable[i] == key)
                hash->status[i] = 'D';
            break;
        }
        else
            i++;
    }
}

void print(struct Hash *hash)
{
    printf("\nIndex Value Status\n");
    for (int i = 0; i < hash->max; i++)
    {
        printf("%d\t%d\t%c\n", i, hash->hashTable[i], hash->status[i]);
    }
}
int main()
{
    struct Hash *hash = (struct Hash *)malloc(sizeof(struct Hash));
    hash->max = 13;
    hash->hashTable = (int *)malloc(sizeof(int) * hash->max);
    hash->status = (char *)malloc(sizeof(char) * hash->max);

    for (int i = 0; i < 13; i++)
    {
        hash->hashTable[i] = -1;
        hash->status[i] = 'E';
    }

    insert(hash, 18);
    insert(hash, 26);
    insert(hash, 35);
    insert(hash, 9);
    find(hash, 15);
    find(hash, 48);
    delete (hash, 35);
    delete (hash, 40);
    find(hash, 9);
    insert(hash, 64);
    insert(hash, 47);
    find(hash, 35);

    print(hash);
    free(hash->hashTable);
    free(hash);
}