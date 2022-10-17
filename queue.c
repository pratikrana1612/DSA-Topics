#include<stdio.h>
#include<conio.h>

    int n=5;
    int a[5];
    int front =-1;
    int rear =-1;
void add(int x)
{
    if(rear == n-1)
    {
        printf("Queue is overflow");
    }
    else
    {
        if(front == -1 && rear == -1)
        {
            front=0;
            rear=0;
            a[rear] = x;
        }
        else{
            rear++;
            a[rear] =x;
        }
    }
}

int dequeue()
{
   if(front == -1 && rear == -1)
   {
        printf("Queue is underflow");
   }
   else if(front == rear)
   {
        front=-1;
        rear=-1;
   }
   else{
        int temp = a[front];
        front ++;
        return temp;
   }
}
void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is underflow");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d",a[i]);
        }
    }
}
void breakLine()
{
    printf("\n");
}
void main()
{

    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    display();
    breakLine();
    printf("%d",dequeue());
        breakLine();
    printf("%d",dequeue());
        breakLine();
    printf("%d",dequeue());
        breakLine();
    printf("%d",dequeue());
     display();
}
