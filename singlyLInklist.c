#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void display();
struct node
{
    int data;
    struct node *next;
};

struct node *temp, *head;
void main()
{
    int choice = 1;
    while (choice)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            newnode->next = 0;
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter choice(1/0)");
        scanf("%d", &choice);
    }
    display();
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    }
}