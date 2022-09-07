#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left,*right;
};

struct node *getNode()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct node *root, struct node *new)
{
	char ch;
	printf("\n1.Left\n2.Right\n");
	ch=getch();
	if(ch == 'r')
	{
		if(root->right == NULL)
			root->right = new;
		else
			insert(root->right,new);
	}
	else
	{
		
		if(root->left == NULL)
			root->left = new;
		else
			insert(root->left,new);
	}
}
	

void preorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		printf("%d ",ptr->info);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void inorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->left);
		printf("%d ",ptr->info);
		inorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->info);
	}
}

void main()
{
	int ch;
	char che;
	struct node *root,*new;
	root = NULL;
	clrscr();
	while(1)
	{

		printf("\n1.Create\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\nEnter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				root = NULL;
				do
				{
					new = getNode();
					printf("\nEnter element");
					scanf("%d",&new->info);
					if(root == NULL)
						root = new;
					else
						insert(root,new);
					printf("\n<Y/y> for more node");
					che=getch();
				}
				while(che == 'y');
				clrscr();
				break;
			case 2:
				if(root == NULL)
					printf("\nTree is Empty");
				else
				preorder(root);
				break;
			case 3:
				if(root == NULL)
					printf("\nTree is Empty");
				else
				inorder(root);
				break;
			case 4:
				if(root == NULL)
					printf("\nTree is Empty");
				else
				postorder(root);
				break;
			case 5:
				exit(0);
			default: 
				printf("Invalid Choice");
		}
	}
}


		