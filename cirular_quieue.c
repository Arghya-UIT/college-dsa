#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int max, *data, front, back;
};

void insert(struct queue *p)
{

    if ((p->front + 1) % p->max == p->back)
    {
        printf("Queue is full\n");
    }
    else
    {
        int a;
        printf("enter an intiger\n");
        scanf("%d", &a);
        if (p->back == -1 && p->front == -1)
        {
            p->front = 0;
            p->back = 0;
            p->data[p->front] = a;
            printf("%d is added\n", a);
        }
        else
        {
            p->front = (p->front + 1) % p->max;
            p->data[p->front] = a;
            printf("%d is added\n", a);
        }
    }
}
void deleate(struct queue *p)
{
    if (p->front == -1 && p->back == -1)
    {
        printf("Queue is empty\n");
    }
    else if (p->front == p->back)
    {

        printf("%d is deleted.\n", p->data[p->back]);
        p->front = -1;
        p->back = -1;
    }
    else
    {
        printf("%d is deleted.\n", p->data[p->back]);
        p->back = (p->back + 1) % p->max;
    }
}
void print(struct queue *p)
{
    if (p->front == -1 && p->back == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Now your queue elements are:\n");
        printf("%d\n", p->data[p->back]);
        int i = (p->back + 1) % p->max;
        while (i != (p->front + 1) % p->max)
        {
            printf("%d \n", p->data[i]);
            i = (i + 1) % p->max;
        }
    }
}

int main()
{
    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    printf("emter maximum size of queue\n");
    scanf("%d", &head->max);
    head->data = (int *)malloc(head->max * sizeof(int));
    head->front = -1;
    head->back = -1;
    printf("1. insert element in queue\n2. deleate element from queue\n3. print elements of queue\n");
    int a = 1;
    while (a)
    {
        printf("\nselect a option\n");
        int ind;
        scanf("%d", &ind);
        switch (ind)
        {
        case 1:
            insert(head);
            break;
        case 2:
            deleate(head);
            break;
        case 3:
            print(head);
            break;

        default:
            break;
        }
    }
    return 0;
}