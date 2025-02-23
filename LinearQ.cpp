#include <stdlib.h>
#include <stdio.h>
#define max 5
struct Queue
{
    int item[max];
    int front, rear;
};

void create(Queue *);
void isempty(Queue *);
void isfull(Queue *);
void insert(Queue *, int);
int remove(Queue *);
void display(Queue *);

int main()
{
    int choice, ins_Element, rem_Element;
    Queue *q, p;
    q = &p;
    do
    {
        printf("\n\nEnter your choice:");
        printf("\n1:Create \n2:IsEmpty \n3:IsFull \n4:Insert \n5:Remove \n6:Display \n7:Exit\t\t");
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
            printf("\nEnter value to insert:");
            scanf("%d", &ins_Element);
            insert(q, ins_Element);
            break;
        case 5:
            rem_Element = remove(q);
            printf("\nRemoved value:%d", rem_Element);
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
    q->front = -1;
    q->rear = -1;
    printf("\nQQQueue is created!");
}

void isempty(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("\nQueue is Empty!");
    }
    else
    {
        printf("\nQueue is not Empty!");
    }
}
void isfull(Queue *q)
{
    if (q->rear == max - 1)
    {
        printf("\nQueue is Full!");
    }
    else
    {
        printf("\nQueue is not full!");
    }
}

void insert(Queue *q, int ins_Element)
{
    if (q->front == max - 1)
    {
        printf("\nQueue Overflow...");
    }
    else
    {
        ++q->rear;
        q->item[q->rear] = ins_Element;
    }
}

int remove(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("\nQueue Underflows!");
        return 0;
        ;
    }
    else
    {
        ++q->front;
        return (q->item[q->front]);
    }
}

void display(Queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("\t%d", q->item[i]);
    }
}