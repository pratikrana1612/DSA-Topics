#include<stdio.h>
#include<stdlib.h>



void push();
int pop();
void display();
void reverse();


int stack[20];
int top=-1,n;
void  main()
{
    int choice;
    printf("Enter maximum size of the stack:");
    scanf("%d",&n);

    while(1)
    {
        printf(" \n 1.Push");
        printf(" \n 2.Pop");
        printf(" \n 3.Display");
        printf(" \n 4.Reverse");
        printf(" \n 5.Exit");
        
        printf("\n Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter valid choice");
        }
    }
}

void push()
{
    if(top==n-1)
    {
        printf("Stack is overflow");
    }
    else{
        int item;
        printf("\n Enter item:");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is underflow");
    }
    else
    {
        int temp=stack[top];
        printf("%d is deleted",temp);
        top--;
        return temp;
    }
}

void display()
{
     if(top==-1)
    {
        printf("Stack is underflow");
    }
    else{
         for(int i=top;i>=0;i--)
    {
        printf("%d \n",stack[i]);
    }
    }
   
}

void reverse()
{
     if(top==-1)
    {
        printf("Stack is underflow");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d \n",stack[i]);
        }
    }
}