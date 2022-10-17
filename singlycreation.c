#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode;

void create()
{

    struct node *temp;
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("\n enter data:");
        scanf("%d", &newnode->data);

        if (head == 0)
        {
            head = temp = newnode;
            newnode->next = 0;
        }
        else
        {
           temp->next=newnode;
           newnode->next=0;
           temp=newnode;
        }

        printf("\n Do you want to continue(1/0):");
        scanf("%d", &choice);
    }
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

void main()
{
    clrscr();
    create();
    display();
    getch();
}