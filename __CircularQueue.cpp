#include <stdio.h>
#include <stdlib.h>

#define max 5
struct Queue
{
    int item[max];
    int front, rear;
    /* data */
};

void create(Queue *);
void isempty(Queue *);
void isfull(Queue *);
void insert(Queue *, int);
int remove(Queue *);
void display(Queue *);

int main()
{
    int choice, x, z;
    Queue *q, p;
    q = &p;
    do
    {
        printf("\nEnter your choice:");
        printf("\n1:Create \n2:Isempty \n3:IsFull \n4:Insert \n5:Remove \n6:Display \n7:Exit \t\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create(q);
            break;
        case 2:
            isempty(q);
            break;
        case 3:
            isfull(q);
            break;
        case 4:
            printf("\n\tEnter Element to insert:");
            scanf("%d", &x);
            insert(q, x);
            break;
        case 5:
            z = remove(q);
            printf("\n\tRemoved value:%d", z);
            break;
        case 6:
            display(q);
            break;
        case 7:
            exit(121);
        }
    } while (choice != 7);

    return 0;
}

void create(Queue *q)
{
    q->front = q->rear = -1;
    printf("\n\t Circular Queue is created!");
}

void isempty(Queue *q)
{
    if (q->front == -1)
    {
        printf("\n\tCircular Queue is empty!");
    }
    else
    {
        printf("\n\tCircular Queue not is empty!");
    }
}

void isfull(Queue *q)
{
    if ((q->front == 0 && q->rear == max - 1) || (q->front = q->rear + 1))
    {
        printf("\n\tCircular Queue is Full!");
    }
    else
    {
        printf("\n\tCircular Queue not is Full!");
    }
}

void insert(Queue *q, int x)
{
    if ((q->front == 0 && q->rear == max - 1) || (q->front == q->rear + 1))
    {
        printf("\n\t\tCircular queue overflow...");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = q->rear = 0;
        }
        else
        {
            q->rear = (q->rear + 1) % max;
        }
        q->item[q->rear] = x;
    }
}

int remove(Queue *q)
{
    int z;
    if (q->front == -1)
    {
        printf("\n\t\tCircular Queue underflow...");
        return (0);
    }
    else
    {
        z = q->item[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % max;
        }
        return (z);
    }
}

void display(Queue *q)
{
    for (int i = q->front; i != q->rear; i = (i + 1) % max)
    {
        printf("\t%d", q->item[i]);
    }
    printf("\t%d", q->item[q->rear]);
}