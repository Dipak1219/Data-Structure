#include <stdlib.h>
#include <stdio.h>
#define max 5
struct ird
{
    int item[max];
    int left, right;
};

void create(ird *);
void isempty(ird *);
void isfull(ird *);
void insert(ird *, int);
int remove_left(ird *);
int remove_right(ird *);
void display(ird *);

int main()
{
    int choice, ins_Element, rem_Element;
    ird *q, p;
    q = &p;
    do
    {
        printf("\n\nEnter your choice:");
        printf("\n1:Create \n2:IsEmpty \n3:IsFull \n4:Insert \n5:Remove_Left \n6:Remove_right \n7:Display \n8:Exit\t\t");
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
            rem_Element = remove_left(q);
            printf("\nRemoved value:%d", rem_Element);
            break;
        case 6:
            rem_Element = remove_right(q);
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

void create(ird *q)
{
    q->left = -1;
    q->right = -1;
    printf("\n\tird is created!");
}

void isempty(ird *q)
{
    if (q->left == q->right)
    {
        printf("\nird is Empty!");
    }
    else
    {
        printf("\nird is not Empty!");
    }
}
void isfull(ird *q)
{
    if (q->right == max - 1)
    {
        printf("\nird is Full!");
    }
    else
    {
        printf("\nird is not full!");
    }
}

void insert(ird *q, int ins_Element)
{
    if (q->right == max - 1)
    {
        printf("\nird Overflow...");
    }
    else
    {
        ++q->right;
        q->item[q->right] = ins_Element;
    }
}

int remove_left(ird *q)
{
    if (q->left == q->right)
    {
        printf("\nird Underflows!");
        return 0;
    }
    else
    {
        ++q->left;
        return (q->item[q->left]);
    }
}
int remove_right(ird *q)
{
    if (q->left == q->right)
    {
        printf("\nird Underflows!");
        return 0;
    }
    else
    {
        return (q->item[q->right--]);
    }
}

void display(ird *q)
{
    for (int i = q->left + 1; i <= q->right; i++)
    {
        printf("\t%d", q->item[i]);
    }
}