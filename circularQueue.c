#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void enqueue();
void dequeue();
void display();

int queue[20];
int n,front=-1,rear=-1;

void main()
{
     printf("Enter maxsize of queue:");
    scanf("%d",&n);
    int choice;
    while(1)
    {
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.display");
        printf("\n4.exit");

        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Choice is invalid");
        }
    }
}

void enqueue()
{
    int item;
    if(((rear+1)%n)==front)
    {
        printf("Queue is overflow");
    }
    else
    {
        printf("Enter Item:");
        scanf("%d",&item);
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            queue[rear]=item;
        }   
        else{
            rear=(rear+1)%n;
            queue[rear]=item;
        } 
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is underflow");
    }
    else
    {
        printf("%d item is deleted:",queue[front]);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%n;
        }
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is underflow");
    }
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf(" \n %d",queue[i]);
            i=(i+1)%n;
        }
        printf(" \n %d",queue[i]);
    }
}