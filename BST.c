#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create(int data);
void insert();
void inOrder(struct node *root);
void preOrder(struct node *root);
void postOrder(struct node *root);
int getData();

void main()
{
    char userActive = 'y';
    int userChoice;
    while (userActive == 'y' || userActive == 'Y')
    {
        printf("1.insert \n\n");
        printf("2.inOrder \n");
        printf("3.preOrder \n");
        printf("4.postOrder \n");
        printf("5.Exit\n");

        printf("Enter choice:");
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            insert();
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            preOrder(root);
            break;
        case 4:
            postOrder(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
            break;
        }

        printf("\n___________\n Do you want to continue?");
        fflush(stdin);
        scanf("%c", &userActive);
    }
}

int getData()
{
    int data;
    printf("Enter data:");
    scanf("%d", &data);
    return data;
} 

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert()
{
    
    int data;
    data = getData();
    struct node *newnode = create(data);
    struct node *prev, *temp;

    if (newnode != NULL)
    {

        if (root == NULL)
        {
            root = newnode;
            printf("****Newnode is created with %d****", data);
            return;
        }
        else
        {
            prev = NULL;
            temp = root;
            while (temp != NULL)
            {
                prev = temp;
                if (data > temp->data)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }

            if (data > prev->data)
            {
                prev->right = newnode;
            }
            else
            {
                prev->left = newnode;
            }
            printf("****Newnode is created with %d****", data);
        }
    }
}


void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf(" %d ", root->data);
    inOrder(root->right);
}

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->data);
}

