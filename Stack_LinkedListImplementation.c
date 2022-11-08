// Stack - Array based implementation.
// Creating a stack of integers.
#include <stdio.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    printf("Push number is %d\n", x);
    A[++top] = x;
}
void Pop()
{
    if (top == -1)
    {
        printf("Error: No element to pop\n");
        return;
    }
    printf("Now pop the number %d\n", A[top]);
    top--;
}
int Top()
{
    return A[top];
}
int IsEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}
void Print()
{
    printf("stack : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    putchar('\n');
}
int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    return 0;
}
