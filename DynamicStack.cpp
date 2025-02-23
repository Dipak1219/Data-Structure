// For Dynamic Implementation of Stack we need ins_beg & rem__beg  Operations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    node *next;
    int info;
} *list;

node *create();
void isempty();
void push(int);
int pop();
void display();

int main()
{
    int choice, x, z;
    do
    {
        printf("\nENter your choice:");
        printf("\n1:Isempty \n2:push \n3:pop \n4:display \n5:Exit \t\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            isempty();
            break;
        case 2:
            printf("\n\tEnter any value to insert:");
            scanf("%d", &x);
            push(x);
            break;
        case 3:
            z = pop();
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

void isempty()
{
    node *p;
    p = list;
    if (p == NULL)
    {
        printf("\n\tStack is Empty!");
    }
    else
    {
        printf("\n\tStack is not Empty!");
    }
}

void push(int x) {
    node *p,*q;
    p = list;
    if(p == NULL) {
        p = create();
        p->info = x;
        p->next = NULL;
        list = p;
    }
    else {
        q = create();
        q->info = x;
        q->next = p;
        list = q; 
    }
}

int pop()
 {
    node *p;
    int z;
     p = list;
     if(p == NULL) {
        printf("\n\tStack Underflows...");
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
        return z;
     }
 }

 void display() {
    node *p;
    p = list;
    while(p != NULL) {
        printf("\n%d",p->info);
        p = p->next;
    }
 }