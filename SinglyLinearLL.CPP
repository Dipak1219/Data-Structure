#include <stdio.h>
#include<stdlib.h>
// #include <conio.h>
// #include <process.h>
// #include <alloc.h>

struct node
{
    int info;
    node *next;
} *list;

node* create();
void ins_beg(int);
void ins_end(int);
void ins_bet(int,int);
int rem_beg();
int rem_end();
int rem_bet(int);
void display();
void reverse();
void count();
void search(int);

int main()
{
    // clrscr();

    int ch, z, x,af,srch;
    do
    {
        printf("\nEnter your choice:");
        printf("\n1:Insert Begin \n2:Insert End \n3:Insert Between \n4:Remove Begin \n5:Remove End \n6:Remove Between \n7:Reverse \n8:count \n9:Search \n10:Display \n11:Exit    ");
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
	    scanf("%d", &srch);
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

node* create()
{
    node *z;
    z =(node*)malloc(sizeof(node));
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
	p->next = NULL;
	list = p;
    }
    else
    {
	q = create();
	q->info = x;
	q->next = p;
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
	p->next = NULL;
        list = p;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        q = create();
        q->info = x;
        q->next = NULL;
        p->next = q;
    }
}

void ins_bet(int af, int x)
{
    node *p, *q;
    p = list;
    if (p == NULL || p->next == NULL)
    {
        printf("\nInsert between is not possible:");
    }
    else
    {
        while (p->next != NULL)
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
    int z;
    node *p;
    p = list;

    if (p == NULL)
    {
        printf("\n LL is Empty...");
    }
    else if (p->next == NULL)
    {
        z = p->info;
        list = NULL;
        free(p);
        return (z);
    }
    else
    {
        z = p->info;
	list = p->next;
        free(p);
        return (z);
    }
}

int rem_end()
{
    int z;
    node *p, *temp;
    p = list;

    if (p == NULL)
    {
        printf("\n LL is Empty...");
    }
    else if (p->next == NULL)
    {
        z = p->info;
        list = NULL;
	free(p);
        return (z);
    }
    else
    {
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        temp = p->next;
        z = temp->info;
        p->next = NULL;
        free(temp);
        return (z);
    }
}

int rem_bet(int af)
{
    int z;
    node *p, *temp;
    p = list;

    if (p == NULL)
    {
        printf("\n LL is Empty...");
    }
    else if (p->next == NULL || p->next->next == NULL)
    {
        printf("\nRemove Between is not possible...");
    }
    else
    {
        while (p->next != NULL)
        {
            if (p->info == af)
            {
                temp = p->next;
                z = temp->info;
                p->next = temp->next;
		free(temp);
                return (z);
            }
            p = p->next;
        }
    }
}

void display()
{
    node *p;
    p=list;
    while (p != NULL)
    {
	printf("\t%d", p->info);
	p = p->next;
    }
}

void count()
{
    node *p;
    p=list;
    int cnt=0;
    while(p != NULL)
    {
        cnt++;
	p=p->next;
    }

    printf("\nTotal nodes:%d",cnt);
}


void search(int srch)
{
    int t = 0;
    node *p;
    p=list;
    while(p != NULL)
    {
        if(p->info == srch)
        {
            t=1;
            break;
        }
        p=p->next;
    }
    if(t == 1)
    {
        printf("\nNode is found");
    }
    else
    {
        printf("\nNode is not found");
    }
}

void reverse()
{
    node *t1,*t2,*t3=NULL;
    t1 = list;
    while(t1 != NULL)
    {
        t2 = t1->next;
        t1->next = t3;
        t3 = t1;
        t1 = t2;
    }
    list=t3;
}
