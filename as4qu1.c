#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next; 
};

struct node *head,*tail;
void create()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter data:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=tail=newnode;
        newnode->prev=tail;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
        newnode->next=NULL;
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
        while(temp!=NULL)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
}


void main()
{
    int choice=1;
    // clrscr();
    while(choice)
    {
        create();
        display();
        printf("\n Do you want to continue(0/1):");
        scanf("%d",&choice);
    }
}