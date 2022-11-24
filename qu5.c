#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void display();
struct node
{
	int data;
	struct node *next;
};

struct node *temp, *head;

void create()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d", &newnode->data);
	if (head == 0)
	{
		head = temp = newnode;
	}
	else
	{
		temp->next = newnode;
		temp = newnode;
	}
	newnode->next = 0;
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
	if (head == NULL)
	{
		printf("Linklist is underflow");
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
	int pos;
	if (head == NULL)
	{
		printf("Linklist is underflow");
	}
	else
	{
		printf("Enter Position:");
		scanf("%d", &pos);
		if (pos > count())
		{
			printf("ENTER VALID POSITION");
			return;
		}
		else if (pos == 1)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		else
		{
			int i = 1;
			struct node *temp, *prev;
			temp = head;
			prev = temp;
			while (i < pos)
			{
				prev = temp;
				temp = temp->next;
				i++;
			}
			prev->next = temp->next;
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