// For Dynamic Implementation of Queue we need ins_end & rem__beg  Operations

#include <stdlib.h>
#include <stdio.h>

struct node
{
    node *next;
    int info;
    /* data */
} *list;

node *create();
void isempty();
void insert(int);
int remove();
void display();

int main()
{
    int choice, x, z;
    do
    {
        printf("\nENter your choice:");
        printf("\n1:Isempty \n2:insert \n3:remove \n4:display \n5:Exit \t\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            isempty();
            break;
        case 2:
            printf("\n\tEnter any value to insert:");
            scanf("%d", &x);
            insert(x);
            break;
        case 3:
            z = remove();
            printf("\n\tRemoved value:%d", z);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(121);
        }
    } while (choice != 5);
    return 0;
}

node *create()
{
    node *z;
    z = (node *)malloc(sizeof(node));
    return z;
}

void insert(int x)
{
    node *p, *q;
    p = list;
    if (p == NULL)
    {
        p = create();
        p->info = x;
        p->next = NULL;
        list = p;
    }
    else {
        while(p->next != NULL) {
            p = p->next;
        }
        q = create();
        q->info = x;
        q->next = NULL;
        p->next = q;
    }
}

int remove() {
    node *p;
    int z;
    p = list;
    if(p == NULL) {
        printf("\n\t Queue underflow...");;
    }
    else if(p->next == NULL) {
        z = p->info;
        list = NULL;
        free(p);
        return z;
    }
    else {
        z = p->info;
        list = p->next;
        free(p);
        return (z);
    }
}

void isempty() {
    node *p;
    p = list;
    if(p == NULL)  {
        printf("\n\tQueue is empty!");
    }
    else {
        printf("\n\tQueue is not Empty!");
    }
}

void display() {
    node *p;
    p = list;
    while(p != NULL) {
        printf("\t%d",p->info);
        p = p->next;
    }
}