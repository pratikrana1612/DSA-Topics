// Roll no:2242
// Name:Rana Pratik

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

void create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->prev = tail;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    newnode->next = head;
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linklist is empty");
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

int count()
{
    int counter = 1;
    struct node *temp;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}
void deletePaticularpos()
{
    int i, pos;
    if (head == NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("ENTER VALID POISTOIN");
        }
        else if(pos==1)
        {
            temp=head;
            head=head->next;
            head->prev=tail;
            free(temp);
        }
        else
        {
            i = 1;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
        }
    }
}
void main()
{
    int choice = 1;
    // clrscr();
    while (choice)
    {
        create();
        printf("\n Do you want to continue(0/1):");
        scanf("%d", &choice);
    }

    while (1)
    {
        printf("\n 1.deletePaticularpos");
        printf("\n 2.display");
        printf("\n 3.exit");
        printf("\n Enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deletePaticularpos();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
            break;
        }
    }
}