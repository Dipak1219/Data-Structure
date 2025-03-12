#include <stdlib.h>
#include <stdio.h>

struct edge
{
    int dest;
    struct edge *right;
};
struct node
{
    node *next;
    int data;
    edge *adj;
} *start;

void ins_ver(int);
void ins_edge(int, int);
void search(int);
void dis_ver();
void find_adj(int);

int main()
{

    int ch, v, srch, sc, d, x;

    do
    {
        printf("\n---------------------------------------Menu---------------------------------------------------\n");
        printf("\n1:Insert Vertex \n2:Search \n3:Display Vertex \n4:insert Edge \n5:Find Adjacency \n6:Exit \t\t");
        printf("\nEnter your choice:");
        printf("\n---------------------------------------Thanks-------------------------------------------------\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Vertex to insert:");
            scanf("%d", &v);
            ins_ver(v);
            break;
        case 2:
            printf("\nEnter value to search:");
            scanf("%d", &srch);
            search(srch);
            break;
        case 3:
            dis_ver();
            break;
        case 4:
            printf("\nEnter source vertex:");
            scanf("%d", &sc);
            printf("\nEnter destination vertex:");
            scanf("%d", &d);
            ins_edge(sc, d);
            break;
        case 5:
            printf("\nEnter Node to find it's adjacent vertices:");
            scanf("%d", &x);
            find_adj(x);
            break;

        case 6:
            exit(1219);
        }
    } while (ch != 10);

    return 0;
}

void ins_ver(int v)
{
    node *p, *temp;

    p = (node *)malloc(sizeof(node));
    p->next = NULL;
    p->data = v;
    p->adj = NULL;

    if (start == NULL)
    {
        start = p;
    }
    else
    {
        temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }

    printf("\nVertex successfully inserted!");
}

void search(int srch)
{
    node *temp;
    int f = 0;

    temp = start;

    while (temp != NULL)
    {
        if (srch == temp->data)
        {
            f = 1;
            break;
        }
        temp = temp->next;
    }

    if (f == 1)
        printf("\nNode is Found!");
    else
        printf("\nNode is not Found!");
}

void dis_ver()
{
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}

void ins_edge(int sc, int d)
{
    node *p, *q;
    int a = 0, b = 0;
    p = q = start;
    while (p != NULL)
    {
        if (sc == p->data)
        {
            a = 1;
            break;
        }
        p = p->next;
    }

    while (q != NULL)
    {
        if (d == q->data)
        {
            b = 1;
            break;
        }
        q = q->next;
    }

    if (a == 1 && b == 1)
    {
        edge *e;
        e = (edge *)malloc(sizeof(edge));
        e->dest = d;
        e->right = NULL;

        if (p->adj == NULL)
        {
            p->adj = e;
        }
        else
        {
            edge *t;
            t = p->adj;
            while (t->right != NULL)
            {
                t = t->right;
            }
            t->right = e;
        }
    }
    else
    {
        printf("\nInvalid Edge!");
    }
}

void find_adj(int x)
{
    node *p;
    int a = 0;
    p = start;
    while (p != NULL)
    {
        if (x == p->data)
        {
            a = 1;
            break;
        }
        p = p->next;
    }

    if (a == 1)
    {
        if (p->adj == NULL)
        {
            printf("\nNo adjacent vertices...");
        }
        else
        {
            edge *t = p->adj;
            while (t != NULL)
            {
                printf("\t%d", t->dest);
                t = t->right;
            }
        }
    }
    else
    {
        printf("\nNode is not Found!");
    }
}