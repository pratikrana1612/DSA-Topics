#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void beginInsert();
void lastInsert();
void randomInsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int count();

struct node *head, *temp;
void main()
{
    int choice;
    while (1)
    {
        printf("\n 1.beginInsert");
        printf("\n 2.lastInsert");
        printf("\n 3.randomInsert");
        printf("\n 4.begin_delete");
        printf("\n 5.last_delete");
        printf("\n 6.randomdelete");
        printf("\n 7.display");
        printf("\n 8.search");
        printf("\n 9.exit");
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
            randomInsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            exit(0);
        default:
            printf("Enter valid choice");
        }
    }
}

int count()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void beginInsert()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = newnode;
        newnode->next = 0;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void lastInsert()
{
    // struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);

    if (head == 0)
    {
        newnode->next = 0;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = 0;
    }
}

void randomInsert()
{
    struct node *newnode;
    int pos, i = 1;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        newnode->next = 0;
        head = newnode;
    }
    else
    {
        printf("Enter Position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("Enter valid position");
        }
        else
        {
            temp = head;
            while (i < pos - 1) // pos-1 for particular position and pos only for after position
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void begin_delete()
{
    if (head == 0)
    {
        printf("Linklist is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void last_delete()
{
    if (head == 0)
    {
        printf("Linklist is empty");
    }
    else if (head->next == 0)
    {
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
        free(temp);
    }
}

void random_delete()
{
    int pos, i = 1;
    if (head == 0)
    {
        printf("Linklist is empty");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("Enter valid position");
        }
        else
        {
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
            free(temp->next);
        }
    }
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

void search()
{
    int item, flag = 0, i = 1;
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Enter data you want to search in the linklist: ");
        scanf("%d", &item);
        while (temp != 0)
        {
            if (temp->data == item)
            {
                printf("your item is at %d position", i);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            temp = temp->next;
        }

        if (flag == 1)
        {
            printf("Element is not in the linked list");
        }
    }
}