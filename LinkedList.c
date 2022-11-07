#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// struct Node *head;
// 传引用方法实现 ，指向指针的指针
void insertAtPosition(struct Node **head, int data, int n)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = *(head);
        *(head) = temp1;
        return;
    }
    struct Node *temp2 = *(head);
    for (int i = 0; i < n - 2; i++)
        temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
}
// 删除 特定位置 的元素
void deleteAtPosition(struct Node **head, int n)
{
    struct Node *temp1 = *head;
    if (n == 1)
    {
        *head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < n - 2; i++)
        temp1 = temp1->next;

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
// roof 反转链表 迭代
void reverse(struct Node **head)
{
    struct Node *prev, *current, *next;
    prev = NULL;
    current = *head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
// Recursion 反转链表
// 递归的思想相对迭代思想，稍微有点难以理解，处理的技巧是：不要跳进递归，而是利用明确的定义来实现算法逻辑。
struct Node *reverseByRecursion(struct Node *head)
{

    if (head->next == NULL)
    {
        return head;
    }
    struct Node *last = reverseByRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}
// 递归逆序打印
void printByRecursion(struct Node *p)
{
    if (p == NULL)
    {
        putchar('\n');
        return;
    }
    // printf("%d ", p->data); 先为正序
    printByRecursion(p->next);
    printf("%d ", p->data);
}
void print(struct Node *head)
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
    insertAtPosition(&head, 1, 1);
    insertAtPosition(&head, 2, 2);
    insertAtPosition(&head, 5, 1);
    insertAtPosition(&head, 4, 2);
    insertAtPosition(&head, 6, 3);
    print(head);
    deleteAtPosition(&head, 3);
    print(head);
    head = reverseByRecursion(head);
    print(head);
    printByRecursion(head);
    return 0;
}
