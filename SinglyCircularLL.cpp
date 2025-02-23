#include <stdio.h>
// #include <conio.h>
// #include <process.h>
#include <stdlib.h>
// #include <alloc.h>

struct node
{
    node *next;
    int info;

} *list;

node *create();
void ins_beg(int);
void ins_end(int);
void ins_bet(int, int);
int rem_beg();
int rem_end();
int rem_bet(int);
void search(int);
void display();
void count();
void reverse();

int main()
{
    // clrscr();
    int ch, x, z, af, srch;
    do
    {
        printf("\nEnter your choice:\n");
        printf("\n1:Insert Begin \n\n2:Insert End \n\n3:Insert Between \n\n4:Remove Begin \n\n5:Remove End \n\n6:Remove Between \n\n7:Reverse \n\n8:count \n\n9:Search \n\n10:Display \n\n11:Exit    ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter any number to insert:");
            scanf("%d", &x);
            ins_beg(x);
            break;
        case 2:
            printf("\nEnter any number to insert:");
            scanf("%d", &x);
            ins_end(x);
            break;
        case 3:
            printf("\nAfter which node?");
            scanf("%d", &af);
            printf("\nEnter any number to insert:");
            scanf("%d", &x);
            ins_bet(af, x);
            break;
        case 4:
            z = rem_beg();
            printf("\nRemoved node:%d", z);
            break;
        case 5:
            z = rem_end();
            printf("\nRemoved node:%d", z);
            break;
        case 6:
            printf("\nAfter which node?");
            scanf("%d", &af);
            z = rem_bet(af);
            printf("\nRemoved node:%d", z);
            break;
        case 7:
            reverse();
            break;
        case 8:
            count();
            break;
        case 9:
            printf("\nEnter node to search:");
            scanf("\n%d", &srch);
            search(srch);
            break;
        case 10:
            display();
            break;
        case 11:
            exit(121);
        }
    } while (ch != 11);
    // getch();
    return 0;
}

node *create()
{
    node *z;
    z = (node *)malloc(sizeof(node));
    return z;
}

void ins_beg(int x)
{
    node *p, *q;
    p = list;
    if (p == NULL)
    {
        p = create();
        p->info = x;
        p->next = p;
        list = p;
    }
    else
    {
        while (p->next != list)
        {
            p = p->next;
        }
        q = create();
        q->info = x;
        q->next = p->next;
        p->next = q;
        list = q;
    }
}
void ins_end(int x)
{
    node *p, *q;
    p = list;
    if (p == NULL)
    {
        p = create();
        p->info = x;
        p->next = p;
        list = p;
    }
    else
    {
        while (p->next != list)
        {
            p = p->next;
        }
        q = create();
        q->info = x;
        q->next = p->next;
        p->next = q;
    }
}

void ins_bet(int af, int x)
{
    node *p, *q;
    p = list;
    if (p == NULL || p->next == p)
    {
        printf("\nInsert between is not possible!");
    }
    else
    {
        while (p->next != list)
        {
            if (p->info == af)
            {
                q = create();
                q->info = x;
                q->next = p->next;
                p->next = q;
            }
            p = p->next;
        }
    }
}

int rem_beg()
{
    node *p, *q;
    int z;
    p = list;
    if (p == NULL)
    {
        printf("\nL L is Empty");
    }
    else if (p->next == p)
    {
        z = p->info;
        free(p);
        list = NULL;
        return (z);
    }
    else
    {
        while (p->next != list)
        {
            p = p->next;
        }
        q = p->next;
        z = q->info;
        p->next = q->next;
        list = q->next;
        free(q);
        return (z);
    }
}

int rem_end()
{
    node *p, *q;
    int z;
    p = list;
    if (p == NULL)
    {
        printf("\nL L is Empty");
    }
    else if (p->next == p)
    {
        z = p->info;
        free(p);
        list = NULL;
        return (z);
    }
    else
    {
        while (p->next->next != list)
        {
            p = p->next;
        }
        q = p->next;
        z = q->info;
        p->next = q->next;
        free(q);
        return (z);
    }
}

int rem_bet(int af)
{
    node *p, *q;
    int z;
    p = list;
    if (p == NULL)
    {
        printf("\nL L is Empty");
    }
    else if (p->next == p || p->next->next == p)
    {
        printf("\nRemove between is not possible!");
    }
    else
    {
        while (p->next != list)
        {
            if (p->info == af)
            {
                q = p->next;
                z = q->info;
                p->next = q->next;
                free(q);
                return (z);
            }
            p = p->next;
        }
    }
}

void display()
{
    node *p;
    p = list;
    do
    {
        printf("\t%d", p->info);
        p = p->next;
    } while (p != list);
}

void count()
{
    int cnt = 0;
    node *p;
    p = list;
    do
    {
        cnt++;
        p = p->next;
    } while (p != list);
    printf("\n%d", cnt);
}

void search(int srch)
{
    int t = 0;
    node *p;
    p = list;
    do
    {
        if (p->info == srch)
        {
            t = 1;
            break;
        }
        p = p->next;
    } while (p != list);

    if (t == 1)
    {
        printf("\nNode was found!");
    }
    else
    {
        printf("\nNode was not found!");
    }
}

void reverse()
{
    node *t1, *t2, *t3 = list;
    t1 = list;
    do
    {
        t2 = t1->next;
        t1->next = t3;
        t3 = t1;
        t1 = t2;
    } while (t1 != list);
    list = t3;
    t1->next = t3;
}
