#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

// Stack structure
struct stack
{
    char arr[SIZE];
    int top;
};

// Initialize stack
void s_init(struct stack *st)
{
    st->top = -1;
}

// Check whether stack is empty
int s_is_empty(struct stack *st)
{
    return st->top == -1;
}

// Check whether stack is full
int s_is_full(struct stack *st)
{
    return st->top == SIZE - 1;
}

// Push element into stack
void s_push(char ch, struct stack *st)
{
    if (s_is_full(st))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->arr[++st->top] = ch;
    }
}

// Pop element from stack
char s_pop(struct stack *st)
{
    if (s_is_empty(st))
    {
        return '\0';
    }

    return st->arr[st->top--];
}

// Peek top element
char s_peek(struct stack *st)
{
    if (s_is_empty(st))
    {
        return '\0';
    }

    return st->arr[st->top];
}

// Check whether character is operand
int is_operand(char ch)
{
    return ((ch >= '0' && ch <= '9') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'));
}

// Find operator priority
int priority(char ch)
{
    switch (ch)
    {
        case '$':
            return 10;

        case '*':
        case '/':
        case '%':
            return 9;

        case '+':
        case '-':
            return 8;

        case '(':
        case ')':
        default:
            return 0;
    }
}

// Infix to postfix conversion
void infix_to_postfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;
    struct stack st;

    s_init(&st);

    for (i = 0; infix[i] != '\0'; i++)
    {
        // If operand, add directly to postfix
        if (is_operand(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        // If opening bracket, push it
        else if (infix[i] == '(')
        {
            s_push('(', &st);
        }

        // If closing bracket
        else if (infix[i] == ')')
        {
            while (!s_is_empty(&st) && s_peek(&st) != '(')
            {
                postfix[j++] = s_pop(&st);
            }

            // Remove '('
            if (!s_is_empty(&st))
            {
                s_pop(&st);
            }
        }

        // If operator
        else
        {
            while (!s_is_empty(&st) &&
                   s_peek(&st) != '(' &&
                   priority(s_peek(&st)) >= priority(infix[i]))
            {
                postfix[j++] = s_pop(&st);
            }

            s_push(infix[i], &st);
        }
    }

    // Pop remaining operators
    while (!s_is_empty(&st))
    {
        postfix[j++] = s_pop(&st);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%19s", infix);

    printf("Infix   : %s\n", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix : %s\n", postfix);

    return 0;
}