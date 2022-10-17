#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void insert_begin();
void insert_last();
void insert_pos();
void delete_begin();
void delete_last();
void delete_pos();
void search();
void binary_search();
void sorting();
void display();


int a[20],n;

void main()
{
    int choice;
    printf("Enter maximum size of the array:");
    scanf("%d",&n);


    printf("\n Enter elements:");
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        scanf("%d",&a[i]);
    }
    while(1)
    {
        printf("\n 1.Insert Begin");
        printf("\n 2.Insert Last");
        printf("\n 3.Insert Position");
        printf("\n 4.Delete Begin");
        printf("\n 5.Delete Last");
        printf("\n 6.Delete Position");
        printf("\n 7.search");
        printf("\n 8.Binary search");
        printf("\n 9.Sorting");
        printf("\n 10.display");
        printf("\n 11.exit");

        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
                        
                
                case 1:
                 insert_begin();
                 break;
                
                case 2:
                 insert_last();
                 break;
                
                case 3:
                 insert_pos();
                 break;
                
                case 4:
                 delete_begin();
                 break;
                
                case 5:
                 delete_last();
                 break;
                
                case 6:
                 delete_pos();
                 break;
                
                case 7:
                 search();
                 break;
                
                case 8:
                 binary_search();
                 break;
                
                case 9:
                 sorting();
                 break;

                case 10:
                    display();
                    break;            

                case 11:
                    exit(0);
                    break;            
        }
    }
}

void insert_begin()
{
    int item;
    printf("enter element:");
    scanf("%d",&item);
    n++;
    for(int i=n;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=item;
}

void insert_last()
{
    int item;
    printf("enter element:");
    scanf("%d",&item);

    a[n]=item;
    n++;
}

void insert_pos()
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("Enter valid position");
    }
    else
    {
        int item;
        printf("enter element:");
        scanf("%d",&item);

        for(int i=n;i<=pos;i--)
        {
            a[i]=a[i-1];
        }
        a[pos]=item;
    }
}

void delete_begin()
{
    for(int i=0;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
}

void delete_last()
{
    n--;
}


void delete_pos()
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("Enter valid position");
    }
    else
    {
        for(int i=pos;i<n;i++)
        {
            a[i]=a[i+1];
        }
        n--;
    }
}

void display()
{
    for(int i=0;i<n;i++)
    { 
        printf("%d:%d\n",i,a[i]);
    }
}

void search()
{
    int item,i;
    printf("Enter element you want to search in the array:");
    scanf("%d",&item);

    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("Your element is %dth position:");
            break;
        }
    }
    if(i==n)
    {
        printf("Your element is not in the array");
    }
}

void binary_search()
{
     int item,i,beg,end,mid;
    printf("Enter element you want to search in the array:");
    scanf("%d",&item);

    beg=0;
    end=n-1;
    mid=(beg+end)/2;
    while(beg<=end && a[mid]!=item)
    {
        mid=(beg+end)/2;
        if(item>a[mid])
        {
            beg=mid+1;
        }
        else if(item<a[mid])
        {
            end=mid-1;
        }
        else if(item==a[mid])
        {
           printf("Your element is %dth position",mid);
            break;
        }
    }
    if(beg>end)
    {
        printf("Your elemet is not in the array");
    }
}

void sorting()
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}