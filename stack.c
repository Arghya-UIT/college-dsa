#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    struct node *t;
    t = ptr;
    if (ptr == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    printf("Your linked list elements are: \n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    ptr = t;
}
void pushstack(struct node **ptr, int a)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->next = *ptr;
    *ptr = n;
    printf("%d is pushed in\n", a);
}
int popstack(struct node **ptr)
{
    if (*ptr == NULL)
        printf("stack is empty\n");
    else
    {
        struct node *x;
        x = *ptr;
        *ptr = (*ptr)->next;
        int a = x->data;
        free(x);
        printf("%d is removed from the stack\n", a);
        return a;
    }
}
int main()
{
    struct node *top = NULL;
    int n, i, x, a = 1;
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    while (a)
    {
        printf("Choose any option");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Which number you want to add\n");
            scanf("%d", &x);
            pushstack(&top, x);
            break;

        case 2:
            popstack(&top);
            break;
        case 3:
            traversal(top);
            break;
        }
    }
}