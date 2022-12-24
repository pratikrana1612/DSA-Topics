#include <stdio.h>
#include <stdlib.h>

// structure of a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *temp;

// globally initialized root pointer
struct node *root = NULL;

// function prototyping
struct node *create_node(int);
void insert(int);
struct node *delete (struct node *, int);
void inorder(struct node *);
void postorder();
void preorder();
struct node *smallest_node(struct node *);
struct node *largest_node(struct node *);
int get_data();

int main()
{
    int userChoice;
    int userActive = 'Y';
    int data;
   struct node* result = NULL;

    while (userActive == 'Y' || userActive == 'y')
    {
	printf("\n\n------- Binary Search Tree ------\n");
	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n\n3. GET LARGER NODE DATA ");
	printf("\n\n4. GET SMALLER NODE DATA ");
	printf("\n\n5. Inorder ");
	printf("\n6. Post Order ");
	printf("\n7. Pre Oder ");
	printf("\n8. Exit");

	printf("\n\nEnter Your Choice: ");
	scanf("%d", &userChoice);
	printf("\n");

	switch(userChoice)
	{
	    case 1:
		data = get_data();
		insert(data);
		break;

	    case 2:
		data = get_data();
		root = delete(root, data);
		break;

	    case 3:
	       result = largest_node(root);
		if (result != NULL)
		{
		   printf("\n Largest data: %d\n", result->data);
		}
		break;

	     case 4:
	       result = smallest_node(root);
		if (result != NULL)
		{
		   printf("\n smallest data: %d\n", result->data);
		}
		break;

	    case 5:

		inorder(root);
		break;

	    case 6:
		postorder(root);
		break;

	    case 7:
		preorder(root);
		break;

	    case 8:
		printf("\n\nProgram was terminated\n");
		break;

	    default:
		printf("\n\tInvalid Choice\n");
		break;
	}

	printf("\n__________\nDo you want to continue? ");
	fflush(stdin);
	scanf(" %c", &userActive);
    }

    return 0;
}

// creates a new node
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// inserts the data in the BST
void insert(int data)
{
    struct node *new_node = create_node(data);
     struct node *temp = root;
     struct node *prev = NULL;
    if (new_node != NULL)
    {
	// if the root is empty then make a new node as the root node
	if (root == NULL)
	{
	    root = new_node;
	    printf("\n* node having data %d was inserted\n", data);
	    return;
	}
	  else {
		temp = root;


       //	traverse through the BST to get the correct position for insertion
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

	// found the last node where the new node should insert
	if (data > prev->data)
	{
	    prev->right = new_node;
	}
	else
	{
	    prev->left = new_node;
	}

	printf("\n* node having data %d was inserted\n", data);
    }
}  }

// deletes the given key node from the BST
struct node *delete (struct node *root, int key)
{  // struct node *temp;
    if (root == NULL)
    {
	return root;
    }
    if (key < root->data)
    {
       //	root->left =
	 delete (root->left, key);
    }
    else if (key > root->data)
    {
       //	root->right =
	 delete (root->right, key);
    }
    else
    {
	if (root->left == NULL)
	{
	     temp = root->right;
	    free(root);
	    return temp;
	}
	else if (root->right == NULL)
	{
	    struct node *temp = root->left;
	    free(root);
	    return temp;
	}
		temp = largest_node(root->left);
		root->data = temp->data;
		root->left = delete (root->left, temp->data);
	 }
    return root;
}

 struct node *smallest_node(struct node *root)
   {
       struct node *curr = root;

	 while (curr !=NULL && curr->left !=NULL)
	   {
	      curr = curr->left;
	   }
	     return curr;
    }

  struct node *largest_node(struct node *root)
   {
       struct node *curr = root;

	 while (curr !=NULL && curr->right !=NULL)
	   {
	      curr = curr->right;
	   }
	     return curr;
    }


// inorder traversal of the BST
void inorder(struct node *root)
{
    if (root == NULL)
    {
	return;
    }
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}

// preorder traversal of the BST
void preorder(struct node *root)
{
    if (root == NULL)
    {
	return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// postorder travsersal of the BST
void postorder(struct node *root)
{
    if (root == NULL)
    {
	return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// getting data from the user
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}