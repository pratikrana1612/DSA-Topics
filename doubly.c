#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *temp;

struct node *creation()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    return newnode;
}
void create()
{
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = temp = newnode;
        newnode->prev = 0;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    newnode->next = 0;
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("linkedlist is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}
void beginInsert()
{
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = newnode;
        newnode->next = 0;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    newnode->prev = 0;
}
void lastInsert()
{
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = newnode;
        newnode->next = 0;
        newnode->prev = 0;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = 0;
    }
}
int counter()
{
    int count = 1;
    struct node *temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void afterrandomInsert()
{
    int pos;
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = newnode;
        newnode->next = 0;
        newnode->prev = 0;
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > counter())
        {
            printf("ENTER VALID POSITION");
        }
        else if(pos==counter())
        {
            lastInsert();
        }
        else
        {
            int i = 1;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            newnode->next->prev = newnode;
            temp->next = newnode;
        }
    }
}
void paticularrandomInsert()
{
    int pos;
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = newnode;
        newnode->next = 0;
        newnode->prev = 0;
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > counter())
        {
            printf("ENTER VALID POSITION");
        }
        else if (pos == 1)
        {
            // beginInsert();
            head->prev = newnode;
            newnode->next = head;
            newnode->prev = 0;
            head = newnode;
        }
        else
        {
            int i = 1;
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            newnode->next->prev = newnode;
            temp->next = newnode;
        }
    }
}

void begin_delete()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        temp = head;
        printf("%d is deleted", temp->data);
        head = head->next;
        free(temp);
    }
}
void last_delete()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
       else if (head->next == NULL)
    {
        printf("%d is deleted", head->data);
        head = 0;
        free(head);
    }
    else
    {
        struct node *prev;
        prev = temp = head;
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = 0;
        printf("%d element is deleted", temp->data);
        free(temp);
    }
}
void random_delete()
{
    int pos;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > counter())
        {
            printf("INVALID POSITION");
        }
        else if(pos==1)
        {
            temp=head;
            if(temp->next=NULL)
            {
                head=0;
            }
            else
            {
                head=head->next;
                head->prev=0;
            }
            free(temp);
        }
        else
        {
            int i = 1;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}
void search()
{
    if (head == NULL)
    {
        printf("linkedlist is underflow");
    }
    else
    {
        int item;
        printf("Enter element you want to seach:");
        scanf("%d", &item);
        temp = head;
        int i = 1, flag = 1;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                printf("\n%d is the position of element", i);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            temp = temp->next;
            i++;
        }
        if (flag)
        {
            printf("Element is not found in the linkedlist");
        }
    }
}
void main()
{
    int choice = 1;
    while (choice)
    {
        create();
        display();
        printf("Enter choice(0/1):");
        scanf("%d", &choice);
    }
    while (1)
    {
        printf("\n 1.beginInsert");
        printf("\n 2.lastInsert");
        printf("\n 3.afterrandomInsert");
        printf("\n 4.paticularrandomInsert");
        printf("\n 5.begin_delete");
        printf("\n 6.last_delete");
        printf("\n 7.randomdelete");
        printf("\n 8.display");
        printf("\n 9.search");
        printf("\n 10.exit");
        printf("\n Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            beginInsert();
            break;
        case 2:
            lastInsert();
            break;
        case 3:
            afterrandomInsert();
            break;
        case 4:
            paticularrandomInsert();
            break;
        case 5:
            begin_delete();
            break;
        case 6:
            last_delete();
            break;
        case 7:
            random_delete();
            break;
        case 8:
            display();
            break;
        case 9:
            search();
            break;
        case 10:
            exit(0);
        default:
            printf("Enter valid choice");
        }
    }
}