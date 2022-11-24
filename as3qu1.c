//Roll no:2242
//Name:Rana Pratik

#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *temp,*head;


void create()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=temp=newnode;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
    }
    newnode->next=NULL;
}
void display()
{
    struct node *temp;
    if (head == 0)
    {
        printf("Linklist is empty");
        return;
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
     clrscr();
    int choice = 1;
    while (choice)
    {
        create();
        display();
        printf("\n Enter choice(1/0):");
        scanf("%d", &choice);
    }
      getch();
}