#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *creation(struct node **ptr)
{
    struct node *p, *q, *r;
    printf("enter size of link list ");
    int n;
    scanf("%d", &n);
    printf("enter elements\n");
    p = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = NULL;
    q = p;
    for (int i = 0; i < n - 1; i++)
    {
        r = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &r->data);
        r->next = NULL;
        q->next = r;
        q = r;
    }
    *ptr = p;
    return *ptr;
}
struct node *insertion(struct node **ptr)
{
    struct node *t, *f;
    t = (struct node *)malloc(sizeof(struct node));
    printf("enter the index where want to insert");
    int n, i;
    scanf("%d", &n);
    printf("enter the elment");
    scanf("%d", &t->data);
    if (n == 0)
    {
        t->next = *ptr;
        return t;
    }
    else
    {
        f = *ptr;
        for (i = 0; i < n - 1; i++)
        {
            f = f->next;
        }
        t->next = f->next;
        f->next = t;
        return *ptr;
    }
}
struct node *deletation(struct node **ptr)
{
    printf("enter the value want to deleate");
    int i;
    scanf("%d", &i);
    struct node *x, *y;
    y = *ptr;
    if (i == y->data)
    {
        *ptr = y->next;
        free(y);
        return *ptr;
    }
    else
    {
        while (y->next->data != i)
        {
            y = y->next;
        }
        x = y->next;
        y->next = y->next->next;
        free(x);
        return *ptr;
    }
}
void travarse(struct node *ptr)
{
    struct node *a = ptr;
    printf("output :\n");
    if (a == NULL)
    {
        printf("linklist is mpty");
    }
    while (a != NULL)
    {
        printf("%d\n", a->data);
        a = a->next;
    }
}
void reverse(struct node **head_ref)
{
    struct node *current = *head_ref;
    struct node *next;
    while (current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        next->next = (*head_ref);
        *head_ref = next;
    }
}
struct node *concatination(struct node **p)
{
    struct node *ss;
    printf("enter elements of soecond link list\n");
    struct node *q = creation(&ss);
    struct node *r, *x = *p;
    if (*p == NULL)
    {
        *p = q;
    }
    else
    {
        r = x;
        while (r->next != NULL)
        {
            r = r->next;
        }
        r->next = q;
    }
    return *p;
}
int main()
{
    struct node *top, *z, *x;
    printf("write the index number you want to perfornm the action \n1. CREATION \n2. INSERTION \n3. DELETION \n4. PRINT \n5. REVERSE \n6. CONCATENATION OF LIST \n");
    int a = 1;
    while (a)
    {
        printf("choose the option ");
        int ind;
        scanf("%d", &ind);
        switch (ind)
        {
        case 1:
            creation(&top);
            break;
        case 2:
            insertion(&top);
            break;
        case 3:
            deletation(&top);
            break;
        case 4:
            travarse(top);
            break;
        case 5:
            reverse(&top);
            break;
        case 6:
            concatination(&top);
            break;
        default:
            printf("invalid option");
            break;
        }
    }
}