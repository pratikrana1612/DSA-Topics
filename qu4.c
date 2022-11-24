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

void beginDelete()
{
    if(head==NULL)
    {
        printf("Linklist is underflow");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}

void lastDelete()
{
    if(head==NULL)
    {
        printf("Linklist is underflow");
    }
    else{
        struct node *prev;
        temp=head;
        while(temp->next!=0)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=0;
        free(temp);   
    }
}

void main()
{
    int choice=1;
     clrscr();
    while(choice)
    {
        create();
        printf("\n Enter choice(0/1):");
        scanf("%d",&choice);
    }

    while(1)
    {
        printf("\n 1.beginDelete");
        printf("\n 2.lastDelete");
        printf("\n 3.Display");
        printf("\n 4.exit");
        printf("\n Enter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                beginDelete();
                break;
            case 2:
                lastDelete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0); 
        }
    }
}