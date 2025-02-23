#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
// #include <process.h>
// #include <alloc.h>

struct node
{
    node *prev;
    int info;
    node *next;
} *list;

node *create();
void ins_beg(int);
void ins_end(int);
void ins_bet(int, int);
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
    int ch, z, x, af, srch;
    do
    {
        printf("\nEnter your choice:\n");
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

// Function to create a new node
node *create()
{
    node *z;
    z = (node *)malloc(sizeof(node)); // Allocate memory for a new node
    return z;
}

// Function to insert a node at the beginning
void ins_beg(int x)
{
    node *p, *q;
    p = list;      // Point to the start of the list
    if (p == NULL) // If the list is empty
    {
        p = create();   // Create the first node
        p->prev = NULL; // No previous node
        p->info = x;    // Set the info field
        p->next = NULL; // No next node
        list = p;       // Update the start of the list
    }
    else // If the list is not empty
    {
        q = create();   // Create a new node
        q->info = x;    // Set the info field
        q->next = p;    // Point to the old first node
        q->prev = NULL; // No previous node
        p->prev = q;    // Update the old first node's prev pointer
        list = q;       // Update the start of the list
    }
}

// Function to insert a node at the end
void ins_end(int x)
{
    node *p, *q;
    p = list;      // Point to the start of the list
    if (p == NULL) // If the list is empty
    {
        p = create();   // Create the first node
        p->prev = NULL; // No previous node
        p->info = x;    // Set the info field
        p->next = NULL; // No next node
        list = p;       // Update the start of the list
    }
    else // If the list is not empty
    {
        while (p->next != NULL) // Traverse to the end of the list
        {
            p = p->next; // Move to the next node
        }
        q = create();   // Create a new node
        q->prev = p;    // Point to the old last node
        q->info = x;    // Set the info field
        q->next = NULL; // No next node
        p->next = q;    // Update the old last node's next pointer
    }
}

// Function to insert a node after a specified node
void ins_bet(int af, int x)
{
    node *p, *q;
    p = list;                         // Point to the start of the list
    if (p == NULL || p->next == NULL) // Check if insertion between nodes is possible
    {
        printf("\nInsert between is not possible");
    }
    else
    {
        while (p->next != NULL)
        {
            if (p->info == af) // Find the specified node
            {
                q = create();      // Create a new node
                q->prev = p;       // Point to the found node
                q->info = x;       // Set the info field
                q->next = p->next; // Point to the next node
                p->next->prev = q; // Update the next node's prev pointer
                p->next = q;       // Update the found node's next pointer
            }
            p = p->next; // Move to the next node
        }
    }
}

// Function to remove a node from the beginning
int rem_beg()
{
    int z;
    node *p;
    p = list;      // Point to the start of the list
    if (p == NULL) // If the list is empty
    {
        printf("\nL L is Empty");
    }
    else if (p->next == NULL) // If there is only one node
    {
        z = p->info; // Store the info field
        list = NULL; // Update the start of the list
        free(p);     // Free the node
        return (z);
    }
    else
    {
        z = p->info;          // Store the info field
        list = p->next;       // Update the start of the list
        p->next->prev = NULL; // Update the prev pointer of the new first node
        free(p);              // Free the node
        return (z);
    }
}

// Function to remove a node from the end
int rem_end()
{
    int z;
    node *p, *temp;
    p = list;      // Point to the start of the list
    if (p == NULL) // If the list is empty
    {
        printf("\nL L is Empty");
    }
    else if (p->next == NULL) // If there is only one node
    {
        z = p->info; // Store the info field
        list = NULL; // Update the start of the list
        free(p);     // Free the node
        return (z);
    }
    else
    {
        while (p->next->next != NULL) // Traverse to the second last node
        {
            p = p->next; // Move to the next node
        }
        temp = p->next; // Point to the last node
        z = temp->info; // Store the info field
        p->next = NULL; // Update the second last node's next pointer
        free(temp);     // Free the last node
        return (z);
    }
}

// Function to remove a node after a specified node
int rem_bet(int af)
{
    int z;
    node *p, *temp;
    p = list;      // Point to the start of the list
    if (p == NULL) // If the list is empty
    {
        printf("\nL L is Empty");
    }
    else if (p->next == NULL || (p->next->next == NULL && p->prev == NULL)) // Check if removal between nodes is possible
    {
        printf("\nRemove Between is not possible!");
    }
    else
    {
        while (p->next != NULL)
        {
            if (p->info == af) // Find the specified node
            {
                temp = p->next;       // Point to the node to be removed
                z = temp->info;       // Store the info field
                p->next = temp->next; // Update the found node's next pointer
                if (temp->next != NULL)
                    temp->next->prev = p; // Update the next node's prev pointer
                free(temp);               // Free the node to be removed
                return (z);
            }
            p = p->next; // Move to the next node
        }
    }
    return -1; // Return -1 if the node was not found
}

// Function to display all nodes in the list
void display()
{
    node *p;
    p = list; // Point to the start of the list
    while (p != NULL)
    {
        printf("\t%d", p->info); // Print the info field of each node
        p = p->next;             // Move to the next node
    }
}

// Function to search for a node with a specific value
void search(int srch)
{
    node *p;
    p = list;         // Point to the start of the list
    int t = 0, n = 0; // Flag to indicate if the node was found
    while (p != NULL)
    {
        n = n + 1;
        if (p->info == srch) // If the node is found
        {
            t = 1;
            break;
        }
        p = p->next; // Move to the next node
    }
    if (t == 1)
    {
        printf("\nNode was Found at %d number", n); // Node found
    }
    else
    {
        printf("\nNode was not Found!"); // Node not found
    }
}

// Function to count the number of nodes in the list
void count()
{
    node *p;
    p = list;    // Point to the start of the list
    int cnt = 0; // Counter for the number of nodes
    while (p != NULL)
    {
        cnt++;       // Increment the counter
        p = p->next; // Move to the next node
    }
    printf("\nTotal Nodes:%d", cnt); // Print the total number of nodes
}

// Function to reverse the list
void reverse()
{
    node *t1, *t2, *t3 = NULL;
    t1 = list; // Point to the start of the list
    while (t1 != NULL)
    {
        t2 = t1->next; // Store the next node
        t1->next = t3; // Reverse the next pointer
        t1->prev = t2; // Reverse the prev pointer
        t3 = t1;       // Move the pointer
        t1 = t2;       // Move to the next node
    }
    list = t3; // Update the start of the list
}
