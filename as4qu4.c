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
        while(temp!=tail)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
         printf(" %d ",temp->data);
    }
}

void begin_delete()
{
    if(head==NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=tail;
        free(temp);
    }
}

void last_delete()
{
    if(head==NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
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
        printf("\n 1.begin_delete");
        printf("\n 2.last_delete");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            begin_delete();
            break;
        case 2:
            last_delete();
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