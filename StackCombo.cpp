#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
// #include <process.h>
#include <string.h>
#define max 100
struct stack
{
    int item[max], top;
};

void first();
void second();
void Stack();
void Reverse();
void INPOST();
void INPRE();
void create(stack *);
void isempty(stack *);
void isfull(stack *);
void push(stack *, int);
int pop(stack *);
void display(stack *);

// void main()
int main()
{
    // clrscr();
    int ch, z, n;
    printf("\nEnter your choice:");
    printf("\n1:First \n2:Second \n3:Exit   ");
    scanf("%d", &ch);
    while (ch != 3)
    {
        switch (ch)
        {
        case 1:
            first();
            break;
        case 2:
            second();
            break;
        case 3:
            exit(121);
        }
    }
    // getch();
    return 0;
}

void first()
{
    int one;
    printf("\nEnter your choice:");
    printf("\n1:Stack \n2:Reverse \n3:Main \n4:Exit   ");
    scanf("%d", &one);
    switch (one)
    {
    case 1:
        Stack();
        break;
    case 2:
        Reverse();
        break;
    case 3:
        main();
        break;
    case 4:
        exit(121);
    }
}

void Stack()
{
    int ch, z, n;
    stack *p, a;
    p = &a;
    do
    {
        printf("\nEnter your choice:");
        printf("\n1:create \n2:isempty \n3:isfull \n4:push \n5:pop\n6:display \n7:Main \n8:Exit    ");
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
            main();
        case 8:
            exit(12);
        }
    } while (ch != 8);
}

void Reverse()
{
    int i = 0, j = 0;
    char str[50], rev[50];
    stack *p, a;
    p = &a;
    create(p);
    printf("\nEnter any String:");
    scanf("%s", &str);
    while (str[i] != '\0')
    {
        push(p, str[i]);
        i++;
    }

    while (p->top != -1)
    {
        rev[j] = pop(p);
        j++;
    }

    rev[j] = '\0';

    printf("\nReversed string:%s", rev);
}

void second()
{
    int two;
    printf("\nEnter your choice:");
    printf("\n1:INPOST \n2:INPRE \n3:Main \n4:Exit   ");
    scanf("%d", &two);
    switch (two)
    {
    case 1:
        INPOST();
        break;
    case 2:
        INPRE();
        break;
    case 3:
        main();
        break;
    case 4:
        exit(121);
    }
}

void INPOST()
{
    // printf("\nINPOST Exp");
    int i = 0, j = 0;
    char in[50], post[50], ch;
    stack *p, q;
    p = &q;
    create(p);
    printf("\nEnter any Infix Exp:");
    scanf("%s", &in);
    while (in[i] != '\0')
    {
        if (in[i] == '+' || in[i] == '/' || in[i] == '*' || in[i] == '-' || in[i] == '(' || in[i] == '$')
        {
            push(p, in[i]);
        }
        else if (in[i] == ')')
        {
            while (p->item[p->top] != '(')
            {
                ch = pop(p);
                if (ch != '(')
                {
                    post[j] = ch;
                    j++;
                }
            }
            pop(p);
        }
        else
        {
            post[j] = in[i];
            j++;
        }
        i++;
    }

    if (p->top != -1)
    {
        while (p->top != -1)
        {
            ch = pop(p);
            if (ch != '(')
            {
                post[j] = ch;
                j++;
            }
        }
    }

    printf("\nPostfix Exp:%s", post);
}
void INPRE()
{
    printf("\nINPRE Exp");
    int i = 0, j = 0;
    char in[50], pre[50], ch;
    stack *ops, *oprnd, a, b;
    ops = &a;
    oprnd = &b;
    create(ops);
    create(oprnd);
    printf("\nEnter any Infix Exp:");
    scanf("%s", &in);
    strrev(in);

    while (in[i] != '\0')
    {
        if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == ')')
        {
            push(ops, in[i]);
        }
        else if (in[i] == '(')
        {
            while (ops->top != -1)
            {
                ch = pop(ops);
                if (ch != ')')
                {
                    push(oprnd, ch);
                }
            }
        }
        else
        {
            push(oprnd, in[i]);
        }
        i++;
    }

    if (ops->top != -1)
    {
        while (ops->top != -1)
        {
            ch = pop(ops);
            if (ch != ')')
            {
                push(oprnd, ch);
            }
        }
    }

    while (oprnd->top != -1)
    {
        pre[j] = pop(oprnd);
        j++;
    }
    printf("\nPostfix Exp:%s", pre);
}

// FUNCTION DEFINITION

void create(stack *p)
{
    p->top = -1;
    printf("\nStack is created");
}
void isempty(stack *p)
{
    if (p->top == -1)
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
    if (p->top == max - 1)
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
    if (p->top == max - 1)
    {
        printf("\nStack overflow...");
    }
    else
    {
        ++p->top;
        p->item[p->top] = n;
    }
}

int pop(stack *p)
{
    if (p->top == -1)
    {
        printf("\nstack underflow...");
    }
    else
    {
        return (p->item[p->top--]);
    }
}

void display(stack *p)
{
    for (int i = p->top; i >= 0; i--)
    {
        printf("\n%d", p->item[i]);
    }
}
