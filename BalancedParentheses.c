#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int data;
    struct Stack *link;
};
struct Stack *top = NULL;
void Push(int x)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    // printf("Push number is %d\n", x);
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop()
{
    if (top == NULL)
        return;
    struct Stack *temp = top;
    top = top->link;
    // printf("Now pop the number %d\n", temp->data);
    free(temp);
}
int Top()
{
    return top->data;
}
int IsEmpty()
{
    return top == NULL ? 1 : 0;
}
void Print()
{
    struct Stack *temp = top;
    if (top == NULL)
        return;
    printf("stack : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    putchar('\n');
}
int IsPair(char c)
{
    if (c == '}' && Top() == '{')
        return 1;
    else if (c == ']' && Top() == '[')
        return 1;
    else if (c == ')' && Top() == '(')
        return 1;
    else
        return 0;
}
int CheckBalancedParentheses(char *exp)
{
    int n = strlen(exp);

    for (int i = 0; i <= n; i++)
    {
        if (*(exp + i) == '{' || *(exp + i) == '[' || *(exp + i) == '(')
        {
            Push(*(exp + i));
        }
        else if (*(exp + i) == '}' || *(exp + i) == ']' || *(exp + i) == ')')
        {
            if (IsEmpty() || (IsPair(*(exp + i)) != 1))
            {
                return 0;
            }
            else
            {
                Pop();
            }
        }
    }
    return IsEmpty() ? 1 : 0;
}
int main()
{
    char input[100];
    printf("please enter an expression:");
    scanf("%s", input);
    int n = CheckBalancedParentheses(input);
    if (n)
        printf("Parentheses is pair.\n");
    else
        printf("Parentheses is not pair!\n");
    return 0;
}
