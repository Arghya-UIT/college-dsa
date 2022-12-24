#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int max, *data, front, back, index;
};

void insert(struct queue **s)
{
    struct queue *ptr = *s;
    if (ptr->front != ptr->max)
    {
        printf("enter an integer\n");
        scanf("%d", &ptr->data[ptr->front]);
        printf("%d is inserted\n", ptr->data[ptr->front]);
        ptr->front++;
    }
    else
    {
        printf("queue is full\n");
    }
}
void deleate(struct queue **s)
{
    struct queue *ptr = *s;
    if (ptr->back == ptr->front)
    {
        printf("queue is empty \n");
    }
    else
    {
        printf("%d is removed\n", ptr->data[ptr->back]);
        ptr->back++;
    }
}
void print(struct queue *ptr)
{
    ptr->index = ptr->back;
    if (ptr->index == ptr->front)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue elements are :\n");
        while (ptr->index != ptr->front)
        {
            printf("%d\n", ptr->data[ptr->index]);
            ptr->index++;
        }
    }
}

int main()
{
    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    printf("emter maximum size of queue\n");
    scanf("%d", &head->max);
    head->data = (int *)malloc(head->max * sizeof(int));
    head->front = 0;
    head->back = 0;
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
            insert(&head);
            break;
        case 2:
            deleate(&head);
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