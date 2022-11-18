//Roll no:2242
//Name:Rana Pratik

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp;
void beginInsert()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter data:");
    scanf("%d",&newnode->data);

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void lastInsert()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter data:");
    scanf("%d",&newnode->data);

    if(head==NULL)
    {
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL)
            {
                temp=temp->next;
            }
        temp->next=newnode;
    }
        newnode->next=NULL;
}
void display()
{
     if (head == 0)
    {
        printf("Linklist is empty");
    }
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
    int choice;
    clrscr();
    while(1)
    {
        printf("\n 1.beginInsert");
        printf("\n 2.lastInsert");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n Enter choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                beginInsert();
                break;
            case 2:
                lastInsert();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
    }
    getch();
}