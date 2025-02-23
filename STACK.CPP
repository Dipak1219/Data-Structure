#include <stdio.h>
// #include <conio.h>
#include <process.h>
#include <stdlib.h>
#define max 5
struct stack
{
    int item[max];
    int top;
};

void create(stack *);
void isempty(stack *);
void isfull(stack *);
void push(stack *, int);
int pop(stack *);
void display(stack *);

int main()
{
    // clrscr();
    int ch, z, n;
    stack *p, a;
    p = &a;
    printf("\nEnter your choice:");
    printf("\n1:create \n2:isempty \n3:isfull \4:push \5:pop\n6:display \n7:Exit   ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        create(p);
        break;
    case 2:
        isempty(p);
        break;
    case 3:
        isfull(p);
        break;
    case 4:
        printf("\nEnter a number to insert:");
            scanf("%d", &n);
        push(p, n);
        break;
    case 5:
        z = pop(p);
        printf("\nRemoved value:%d", z);
        break;
    case 6:
        display(p);
        break;
    case 7:
        exit(123);
    }
    // getch();
    return 0;
}

void create(stack*p)
{
    p->top = -1;
    printf("\nStack is created");
}
void isempty(stack *p)
{
    if(p->top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\n Stack is not empty");
    }
}

void isfull(stack *p)
{
    if(p->top==max-1)
    {
        printf("\nStack is Full");
    }
    else
    {
        printf("\n Stack is not Full");
    }
}


void push(stack *p, int n)
{
    if(p->top==max-1) {
        printf("\nStack overflow...");
    }
    else
    {
        ++p->top;
        p->item[p->top]=n;
    }
}

int pop(stack *p)
{
    if(p->top==-1)
    {
        printf("\nstack underflow...");
    }
    else
    {
        return(p->item[p->top--]);
    }
}

void display(stack *p)
{
    for(int i=p->top; i>=0; i--) {
        printf("\n%d",p->item[i]);
    }
}
