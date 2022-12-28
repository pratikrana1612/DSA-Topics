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

struct node *head, *tail, *temp;

void create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->prev = tail;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    newnode->next = head;
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        temp=head;
        while(temp->next=head)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
         printf(" %d ",temp->data);
    }
}
int count()
{
    int counter = 1;
    struct node *temp;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}
void insertPaticluarpos()
{
    int pos, i;
    if (head == NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        printf("Enter pos:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("\n \n ENTER VALID POSITION");
            return;
        }
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("\n Enter data:");
        scanf("%d", &newnode->data);
        if(pos==1)
        {
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        else
        {
            i = 1;
            temp = head;
            while (i < pos - 1)
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
void main()
{
    int choice = 1;
    // clrscr();
    while (choice)
    {
        create();
        printf("\n Do you want to continue(0/1):");
        scanf("%d", &choice);
    }
    while (1)
    {
        printf(" \n 1.insertPaticluarpos");
        printf(" \n 2.display");
        printf(" \n 3.exit");
        printf(" \n Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertPaticluarpos();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
            break;
        }
    }
}