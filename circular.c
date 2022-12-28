#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *tail, *temp;
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
        newnode->prev = tail;
        head = tail = newnode;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        // head->next=newnode;
        // newnode->prev=head;
        // newnode->next=
    }
    newnode->next = head;
}
void beginInsert()
{
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else
    {
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void lastInsert()
{
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else
    {
        newnode->prev = temp;
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
    }
}
int counter()
{
    temp = head;
    int count = 1;
    while (temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void paticular_radom_insert()
{
    int pos;
    struct node *newnode = creation();
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = head;
        newnode->prev = tail;
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > counter())
        {
            printf("\n \n ENTER VALID POSITION");
            return;
        }
        else if (pos == 1)
        {
            newnode->next = head;
            newnode->prev = tail;
            head->prev = newnode;
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
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("linked list is underflow");
    }
    else
    {
        temp = head;
        while (temp != tail)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
        printf(" %d ", temp->data);
    }
}
void begin_delete()
{
    if (head == NULL)
    {
        printf("linked list is empty");
    }

    else
    {
        temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}
void last_delete()
{
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    else if (head->next == head)
    {
        temp = head;
        head = tail = 0;
        free(temp);
        return;
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

void random_delete()
{
    int i = 1, pos;
    if (head == NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > counter())
        {
            printf("ENTER VALID POISTOIN");
            return;
        }
        else if (pos == 1)
        {
            temp = head;
            if (temp->next == head)
            {
                temp = head;
                head = tail = 0;
                free(temp);
                return;
            }
            else
            {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
        }
        else
        {
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
        printf("\n 3.paticularinesert");
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
            paticular_radom_insert();
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