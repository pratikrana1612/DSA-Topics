// Roll no:2242
// Name:Rana Pratik

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *temp, *head;

void create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = temp = newnode;
        newnode->prev = NULL;
    }
    else
    {
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }
    newnode->next = NULL;
}

int count()
{
    int count = 1;
    struct node *temp;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void AfterparticularPos()
{
    int pos;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (head == NULL)
    {
        printf("Linklist is underflow");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("ENTER VALID POSITION");
            return;
        }
        else
        {
            printf("Enter data:");
            scanf("%d", &newnode->data);
            int i = 1;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            newnode->next->prev = newnode;
            temp->next = newnode;
        }
    }
}

void particularPos()
{
    int i, pos;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Linklist is underflow");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("ENTER VALID POSITION");
            return;
        }
        else if (pos == 1)
        {
            printf("Enter data:");
            scanf("%d", &newnode->data);
            newnode->prev = NULL;
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else
        {
            i = 1;
            temp = head;
            printf("Enter data:");
            scanf("%d", &newnode->data);
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            newnode->next->prev = newnode;
            temp->next = newnode;
        }
    }
}

void display()
{
    struct node *temp;
    if (head == 0)
    {
        printf("Linklist is empty");
    }
    temp = head;
    while (temp != 0)
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int choice = 1;
    clrscr();
    while (choice)
    {
        create();
        printf("Enter choice(0/1):");
        scanf("%d", &choice);
    }
    while (1)
    {
        printf("\n 1.AfterparticularPos");
        printf("\n 2.particularPos");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AfterparticularPos();
            break;
        case 2:
            particularPos();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}