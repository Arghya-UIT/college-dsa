#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct stack
{
    int top;
    int *arr;
};
void push(struct stack *ptr, int ch)
{
    ptr->arr[++ptr->top] = ch;
}
int  pop(struct stack *ptr)
{
    return ptr->arr[ptr->top--];
}

int postEval(char *ch)
{
    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    p->arr = (int *)malloc(strlen(ch) * sizeof(int));
    p->top = -1;
    for (int i = 0; ch[i]; ++i)
    {
        if (ch[i] >= '0' && ch[i] <= '9')
        {
            push(p, ch[i] - '0');
        }
        else
        {
            int val1 = pop(p);
            int val2 = pop(p);
            switch (ch[i])
            {
            case '+':
                push(p, val2 + val1);
                break;
            case '-':
                push(p, val2 - val1);
                break;
            case '*':
                push(p, val2 * val1);
                break;
            case '/':
                push(p, val2 / val1);
                break;
            // case '^':
            //     // double c=(double)val1;
            //     // double b=(double)val2;
            //     double a = (pow(val2, val1));
            //     push(p, a);
            //     break;
            }
        }
    }
    return pop(p);
}

int main()
{
    printf("%d", postEval("2319**+9-"));
    return 0;
}