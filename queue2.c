#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void enqueue();
int dequeue();
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
    if(rear==n-1)
    {
        printf("Queue is overflow");
    }
    else
    {
        printf("Enter item:");
        scanf("%d",&item);
        if(rear==-1 && front==-1)
        {
            front=0;
            rear=0;
            queue[rear]=item;
        }
        else{
            rear++;
            queue[rear]=item;
         }
    } 
}

int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is underflow");
    }
    else
    {
       printf("%d is element is deleted",queue[front]);
        if(rear==front)
        {
            rear=front=-1;
        }
        else{
            front++;
        }
    }
}

void display()
{
      if(front==-1 && rear==-1)
    {
        printf("queue is underflow");
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            printf("\n %d",queue[i]);
        }
    }
}