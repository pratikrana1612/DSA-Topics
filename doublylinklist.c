#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void create();
void display();

struct node *newnode,*temp,*head;
void create()
{
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=temp=newnode;
            newnode->next=0;
            newnode->prev=0;
        }
        else
        {
            newnode->prev=temp;
            newnode->next=0;
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter choice (0/1):");
        scanf("%d",&choice);
    }
}

void display()
{
    if(head==0)
    {
        printf("linked list is empty");
    }
    else{
        temp=head;
        while(temp!=0)
        {
            printf("\n %d",temp->data);
            temp=temp->next;
        }

    }
}
void main()
{
    create();
    display();
}