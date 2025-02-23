#include <stdlib.h>
#include <stdio.h>

struct node
{
    node *left;
    int info;
    node *right;
} *root;

node *create();
void insert(int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void search(int);
int count_total(node *);
int count_leaf(node *);
void del(int);
void del_leaf(node *, node *);
void del_one(node *, node *);
void del_two(node *);

int main()
{
    int ch, n, srch, z, d;
    do
    {
        printf("\nEnter your choice:\n1:Insert \n2:Preorder \n3:Inorder \n4:Postorder \n5:Search \n6:Count Leaf \n7:Count Total \n8:Delete \n9:Exit      ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to insert:");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("\nEnter value to search:");
            scanf("%d", &srch);
            search(srch);
            break;
        case 6:
            z = count_leaf(root);
            printf("\nLeaf Node:%d", z);
            break;
        case 7:
            z = count_total(root);
            printf("\nTotal Node count:%d", z);
            break;
        case 8:
            printf("\nEnter Element to delete:");
            scanf("%d", &d);
            del(d);
            break;
        case 9:
            exit(1219);
        }
    } while (ch != 9);

    return 0;
}

node *create()
{
    node *z;
    z = (node *)malloc(sizeof(node));
    return z;
}

int count_leaf(node *p)
{
    if (p == NULL)
    {
        return (0);
    }
    else if (p->left == NULL && p->right == NULL)
    {
        printf("\t%d", p->info);
        return (1);
    }
    else
    {
        return (count_leaf(p->left) + count_leaf(p->right));
    }
}

int count_total(node *p)
{
    if (p == NULL)
    {
        return (0);
    }
    else if (p->left == NULL && p->right == NULL)
    {
        return (1);
    }
    else
    {
        return (count_total(p->left) + count_total(p->right) + 1);
    }
}

void search(int srch)
{
    int f = 0;
    node *p;
    p = root;

    while (p != NULL)
    {

        if (srch == p->info)
        {
            f = 1;
            break;
        }
        else if (srch < p->info)
        {
            p = p->left;
        }
        else
        {
            if (srch > p->info)
            {
                p = p->right;
            }
        }
    }
    if (f == 1)
    {
        printf("\nNode is found!");
    }
    else
    {
        printf("\nNode is not found!");
    }
}

void insert(int x)
{
    node *p, *temp;

    p = create();
    p->left = NULL;
    p->info = x;
    p->right = NULL;

    if (root == NULL)
    {
        root = p;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            if (p->info < temp->info)
            {
                if (temp->left == NULL)
                {
                    temp->left = p;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (p->info > temp->info)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = p;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void preorder(node *p)
{
    if (p != NULL)
    {
        printf("\t%d", p->info);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("\t%d", p->info);
        inorder(p->right);
    }
}

void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("\t%d", p->info);
    }
}

void del(int d)
{
    int f = 0;
    node *p, *temp;
    temp = root;

    while (temp != NULL)
    {
        if (d == temp->info)
        {
            f = 1;
            break;
        }
        else if (d < temp->info)
        {
            p = temp;
            temp = temp->left;
        }
        else if (d > temp->info)
        {
            p = temp;
            temp = temp->right;
        }
    }
    if (f == 1)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            del_leaf(p, temp);
        }
        else if (temp->left != NULL && temp->right != NULL)
        {
            del_two(temp);
        }
        else
        {
            del_one(p, temp);
        }
    }
    else
    {
        printf("\nNode is not found!");
    }
}

void del_leaf(node *p, node *c)
{
    if (c == p->left)
    {
        p->left = NULL;
    }
    else if (c == p->right)
    {
        p->right = NULL;
    }
    free(c);
    printf("\nNode is deleted by del_leaf()");
}

void del_one(node *p, node *c)
{
    if (c == p->left)
    {
        if (c->left != NULL)
        {
            p->left = c->left;
        }
        else
        {
            p->left = c->right;
        }
    }
    else if (c == p->right)
    {
        if (c->right != NULL)
        {
            p->right = c->right;
        }
        else
        {
            p->right = c->left;
        }
    }
    free(c);
    printf("\nNode is deleted by del_one()");
}

void del_two(node *c)
{
    node *p = NULL, *lft;
    int f = 0;

    lft = c->left;

    while (lft->right != NULL)
    {
        p = lft;
        lft = lft->right;
    }

    c->info = lft->info;

    if (p == NULL)
    {
        p = c;
    }

    if (lft->left == NULL && lft->right == NULL)
    {
        del_leaf(p, lft);
    }
    else
    {
        del_one(p, lft);
    }
}