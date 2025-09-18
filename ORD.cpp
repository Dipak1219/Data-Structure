// ORD
#include <stdlib.h>
#include <stdio.h>
#define max 5
struct ord
{
    int item[max];
    int left, right;
};

void create(ord *);
void isempty(ord *);
void isfull(ord *);
void insert_left(ord *, int);
void insert_right(ord *, int);
int remove(ord *);
void display(ord *);

int main()
{
    int choice, ins_Element, rem_Element;
    ord *q, p;
    q = &p;
    do
    {
        printf("\n\nEnter your choice:");
        printf("\n1:Create \n2:IsEmpty \n3:IsFull \n4:Insert_left \n5:Insert_Right \n6:Remove \n7:Display \n8:Exit\t\t");
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
            insert_left(q, ins_Element);
            break;
        case 5:
            printf("\nEnter value to insert:");
            scanf("%d", &ins_Element);
            insert_right(q, ins_Element);
            break;
        case 6:
            rem_Element = remove(q);
            printf("\nRemoved value:%d", rem_Element);
            break;
        case 7:
            display(q);
            break;
        case 8:
            exit(121);
        }
    } while (choice != 8);
    return 0;
}

void create(ord *q)
{
    q->left = -1;
    q->right = -1;
    printf("\n\tord is created!");
}

void isempty(ord *q)
{
    if (q->left == q->right)
    {
        printf("\nord is Empty!");
    }
    else
    {
        printf("\nord is not Empty!");
    }
}
void isfull(ord *q)
{
    if (q->right == max - 1)
    {
        printf("\nord is Full!");
    }
    else
    {
        printf("\nord is not full!");
    }
}

void insert_right(ord *q, int ins_Element)
{
    if (q->right == max - 1)
    {
        printf("\nord Overflow...");
    }
    else
    {
        ++q->right;
        q->item[q->right] = ins_Element;
    }
}
void insert_left(ord *q, int ins_Element)
{
    if (q->right == max - 1)
    {
        printf("\nord Overflow...");
    }
    else
    {
        for (int i = q->right + 1; i >= q->left + 2; i--)
        {
            q->item[i] = q->item[i - 1];
        }
        q->item[q->left + 1] = ins_Element;
        ++q->right;
    }
}

int remove(ord *q)
{
    if (q->left == q->right)
    {
        printf("\nord Underflows!");
        return 0;
    }
    else
    {
        ++q->left;
        return (q->item[q->left]);
    }
}

void display(ord *q)
{
    for (int i = q->left + 1; i <= q->right; i++)
    {
        printf("\t%d", q->item[i]);
    }
}