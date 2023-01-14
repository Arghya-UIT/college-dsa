#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void push(struct stack *ptr, char ch)
{
    ptr->top++;
    ptr->arr[ptr->top] = ch;
}

char pop(struct stack *ptr)
{
    if (!isEmpty(ptr))
        return ptr->arr[ptr->top--];
    return '$';
}

char *infix_postfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc((sp->size + 1) * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push(sp, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(sp) && stackTop(sp) != '(')
            {
                postfix[j] = pop(sp);
                j++;
            }
            pop(sp);
        }
        else
        {
            while (!isEmpty(sp) && precedence(stackTop(sp)) >= precedence(infix[i]))
            {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
        }
        i++;
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[1000];
    printf("Enter infix expression: ");
    fgets(infix, 1000, stdin);
    infix[strcspn(infix, "\r\n")] = 0; // remove trailing newline character
    printf("Postfix expression: %s\n", infix_postfix(infix));
    return 0;
}
