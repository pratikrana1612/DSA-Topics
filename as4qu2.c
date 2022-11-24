#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *tail;

void begin_insert()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = NULL;
        newnode->prev = tail;
    }
    else
    {
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void last_insert()
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
    newnode->next = NULL;
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int choice;
    // clrscr();
    while(1)
    {
        printf("\n 1.begin_insert");
        printf("\n 2.last_insert");
        printf("\n 3.display");
        printf("\n 4.exit");

        printf("\n Enter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                begin_insert();
                break;
            case 2:
                last_insert();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter valid choice");
                break;
        }
    }
}