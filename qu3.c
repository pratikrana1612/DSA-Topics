//Roll no:2242
//Name:Rana Pratik

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp;

int count()
{
    int counter = 1;
    struct node *temp;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}
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
void AfterparticularPos()
{
    int pos;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (head == NULL)
    {
        printf("Enter data:");
        scanf("%d", &newnode->data);
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        int i = 1;
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("\n PLEASE ENTER VALID POISITON");
            return;
        }
        else
        {
            printf("Enter data:");
            scanf("%d", &newnode->data);
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
void display()
{
    if (head == 0)
    {
        printf("Linklist is empty");
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp != 0)
        {
            printf("\n %d", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice = 1;
    // clrscr();
    while (choice)
    {
        create();
        printf("Enter choice(0/1):");
        scanf("%d", &choice);
    }
    while (1)
    {
        printf("\n 1.AfterparticularPos");
        printf("\n 2.display");
        printf("\n 3.exit");
        printf("\n Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AfterparticularPos();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        }
    }
    // getch();
}