//Roll no:2242
//Name:Rana Pratik

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
void create()
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
        temp->next = newnode;
        temp = newnode;
    }
    newnode->next = 0;
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
void main()
{
    // clrscr();
    int choice = 1;
    while (choice)
    {
        create();
        display();
        printf("\n Enter choice(1/0)");
        scanf("%d", &choice);
    }
    // getch();
}