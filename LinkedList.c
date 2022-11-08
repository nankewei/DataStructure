#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// struct Node *head;
// head insert
// // 传引用方法实现 ，指向指针的指针
void Insert(struct Node **head, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->next = *head;
    *head = temp;
}
void Print(struct Node *head)
{
    // struct Node *temp = head;
    printf("List is:");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    putchar('\n');
}

int main()
{
    struct Node *head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(&head,x);
        Print(head);
    }
    return 0;
}
