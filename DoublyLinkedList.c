#include <stdio.h>
#include <stdlib.h>

struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *prev;
    struct doublyLinkedList *next;
};
struct doublyLinkedList *head;

struct doublyLinkedList *GetNewNode(int x)
{
    struct doublyLinkedList *newNode = (struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x)
{
    struct doublyLinkedList *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(int x)
{
    struct doublyLinkedList *newNode = GetNewNode(x);
    struct doublyLinkedList *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
}
void Print(struct doublyLinkedList *head)
{
    struct doublyLinkedList *temp = head;
    printf("List is :");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    putchar('\n');
}
void ReversePrint(struct doublyLinkedList *head)
{
    struct doublyLinkedList *temp = head;
    printf("ReverseList is :");
    if (temp == NULL)
        return;
    // to the end
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    putchar('\n');
}

int main()
{
    head = NULL;
    InsertAtHead(2);
    Print(head);
    ReversePrint(head);
    InsertAtHead(4);
    Print(head);
    ReversePrint(head);
    InsertAtHead(3);
    Print(head);
    ReversePrint(head);
    InsertAtTail(6);
    InsertAtTail(7);
    InsertAtTail(8);
    Print(head);
    ReversePrint(head);
    return 0;
}
