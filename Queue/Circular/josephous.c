#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int f, r, size;
    int *arr;
};
struct Queue *create(int s)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = -1;
    q->r = -1;
    q->size = s;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    return q;
}
int isFull(struct Queue *q)
{
    if (q->f == -1 && q->r == q->size - 1)
        return 1;
    if (q->f == q->r + 1)
        return 1;
    return 0;
}
int isEmpty(struct Queue *q)
{
    if (q->f == -1)
        return 1;
    return 0;
}
void enqueue(struct Queue *q, int data)
{
    if ((q->r + 1) % q->size == q->f)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (q->f == -1)
        {
            q->f = 0;
        }
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
    }
}
int dequeue(struct Queue *q)
{
    if (isEmpty(q) == 1)
    {
        return -1;
    }
    else if (q->f == q->r)
    {
        int x = q->arr[q->f];
        q->r = -1;
        q->f = -1;
        return x;
    }
    else
    {
        int x = q->arr[q->f];
        q->f = (q->f + 1) % q->size;
        return x;
    }
}
int front(struct Queue *q)
{
    return q->arr[q->f];
}
int sizeofq(struct Queue *q)
{
    return (q->r - q->f + 1);
}
void display(struct Queue *q)
{
    int i = q->f;
    while (i != q->r + 1)
    {
        printf("%d ", q->arr[i]);
        i++;
    }
    printf("\n");
}
int safe(int n, int k)
{
    struct Queue *q = create(n);
    int j = 1, i = 1, c = 0;
    while (j <= n)
    {
        enqueue(q, j);
        // printf("%d enqueud\n", j);
        j++;
    }
    int x, val;
    while (1)
    {
        val = dequeue(q);
        if (i % k != 0)
        {
            enqueue(q, val);
        }
        else
        {
            i = 0;
        }
        // display(q);
        i++;
        if (sizeofq(q) == 1)
            return front(q);
    }
}
int main()
{
    int n, k;
    printf("Enter n and k\n");
    scanf("%d", &n);
    scanf("%d", &k);
    printf("The safe person is %d\n", safe(n, k));
    return 0;
}
