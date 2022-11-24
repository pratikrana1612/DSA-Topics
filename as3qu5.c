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
struct node *temp, *head;

void create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = temp = newnode;
        newnode->prev = NULL;
    }
    else
    {
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }
    newnode->next = NULL;
}

int count()
{
    struct node *temp;
    int count = 1;
    if (head == NULL)
    {
        printf("Linklist is underflow");
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}
void display()
{
    struct node *temp;
    if (head == 0)
    {
        printf("Linklist is empty");
    }
    temp = head;
    while (temp != 0)
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    }
}
void DeleteparticularPos()
{
    int pos, i;
    if (head == NULL)
    {
        printf("linklist is empty");
    }
    else
    {
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos > count())
        {
            printf("ENTER VALID POSITION");
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
    clrscr();
    while (choice)
    {
        create();
        printf("\n Enter choice(0/1):");
        scanf("%d", &choice);
    }

    while (1)
    {
        printf("\n 1.DeleteparticularPos");
        printf("\n 2.Display");
        printf("\n 3.exit");
        printf("\n Enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            DeleteparticularPos();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }
}