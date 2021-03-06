#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};

typedef struct BST bst;

bst *insert(bst *root,int data)
{
	if(root==0)
	{
		root=(bst*)malloc(sizeof(struct BST));
		if(!root)
		{
			printf("no space\n");
			exit(1);
		}
		root->data=data;
		root->left=0;
		root->right=0;
		return root;
	}
	if(data < root->data)
	root->left=insert(root->left,data);
	else if(data > root->data)
	root->right=insert(root->right,data);
	return root;
}

void inorder(bst *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void preorder(bst *root)
{
	if(root)
	{
		printf("%d\t",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

bst *min(bst *root)
{
	if(!root)
	return root;
	while(root->left)
	root=root->left;
	return root;
}

bst *max(bst *root)
{
	if(!root)
	return root;
	while(root->right)
	root=root->right;
	return root;
}

bst *delete(bst *root,int data)
{
	if(!root)
	printf("node not present\n");
	else if(data<root->data)
	root->left=delete(root->left,data);
	else if(data>root->data)
	root->right=delete(root->right,data);
	else
	{
		if(root->right && root->left)
		{
			bst *temp;
			temp=max(root->left);
			root->data=temp->data;
			root->left=delete(root->left,root->data);
		}
		else
		{
			bst *temp;
			temp=root;
			if(!root->left)
			root=root->right;
			else if(!root->right)
			root=root->left;
			free(temp);
		}
	}
	return root;
}

bst *lca(bst *root,int alpha,int beta)
{
	if(!root)
	{
		printf("no lca\n");
		return 0;
	}
	else if(alpha<root->data && beta<root->data)
	return(lca(root->left,alpha,beta));
	else if(alpha>root->data && beta>root->data)
	return(lca(root->right,alpha,beta));
	else if((alpha<root->data &&beta>root->data)||(alpha<root->data &&beta>root->data))
	return root;
}

bst *append(bst *a,bst *b)
{
	//bst *alist,*blist;
	if(!a)
	return b;
	if(!b)
	return a;
	a->right=b;
	b->left=a;
	a->left=b;
	b->right=a;
	return a;
}

bst *dll(bst *root)
{
	bst *alist,*blist;
	if(!root)
	return 0;
	alist=dll(root->left);
	blist=dll(root->right);
	root->right=root;
	root->left=root;
	alist=append(alist,root);
	alist=append(alist,blist);
	return alist;
}

void printList(bst *head)
{
	bst *temp;
	printf("%d-->",head->data);
	for(temp=head->right;temp!=head;temp=temp->right)
	printf("%d-->",temp->data);
}


int main()
{
	bst *root,*temp,*dllist;
	int selection,data,alpha,beta;
	printf("enter 1->insert,2->delete,3->inorder,4->to form dll\n");
	while(1)
	{
		//preorder(root);
		printf("\nenter ur selection\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				printf("enter data to be inserted\n");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2:
				printf("enter data to be deleted\n");
				scanf("%d",&data);
				root=delete(root,data);
				break;
			case 3:
				printf("enter alpha and beta\n");
				scanf("%d %d",&alpha,&beta);
				temp=lca(root,alpha,beta);
				printf("lca = %d",temp->data);
				/*dllist=dll(root);
				printList(dllist);*/
				break;
			/*case 4:
				
				break;*/
			default:
				printf("invalid choice\n");
				exit(1);
				break;
		}
	}
	return 0;
}
