#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};

typedef struct BST bst;

bst* insert(bst *root,int data)
{
	if(!root)
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
	}
	else if(data>root->data)
	root->right=insert(root->right,data);
	else if(data<root->data)
	root->left=insert(root->left,data);
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

bst *findmin(bst *root)
{
	if(!root)
	return root;
	while(root->left)
	root=root->left;
	return root;
}

bst *findmax(bst *root)
{
	if(!root)
	return root;
	while(root->right)
	root=root->right;
	return root;
}

bst *delete(bst *root,int key)
{
	if(!root)
	printf("node not present\n");
	else if(root->data>key)
	root->left=delete(root->left,key);
	else if(root->data<key)
	root->right=delete(root->right,key);
	else
	{
		if(root->left && root->right)
		{
			bst *temp;
			temp=findmax(root->left);
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

bst *lca(bst *root,int a,int b)
{
	if(!root)
	{
		printf("no lca\n");
		return root;
	}
	if(((a<=root->data) && (b>=root->data))||((a>=root->data) && (b<=root->data)))
	return root;
	else if((a<root->data) && (b<root->data))
	return(lca(root->left,a,b));
	else
	return(lca(root->right,a,b));
}

int isbst(bst *root,int min,int max)
{
	if(!root)
	return 1;
	else
	return(root->data>min && root->data<max && isbst(root->left,min,root->data) && isbst(root->right,root->data,max));
}

void printdll(bst *dll)
{
	bst *list;
	printf("%d-->",dll->data);
	for(list=dll->right;list!=dll;list=list->right)
	printf("%d-->",list->data);
}

bst *append(bst *a,bst *b)
{
	bst *alast,*blast;
	if(!a)
	return b;
	if(!b)
	return a;
	alast=a->left;
	blast=b->left;
	alast->right=b;
	b->left=alast;
	blast->right=a;
	a->left=blast;
	return a;
}

bst *dll(bst *root)
{
	bst *alist,*blist;
	if(!root)
	return 0;
	alist=dll(root->left);
	blist=dll(root->right);
	root->left=root;
	root->right=root;
	alist=append(alist,root);
	alist=append(alist,blist);
	return alist;
}
int main()
{
	bst *root;
	int selection,data,key,a,b;
	printf("enter 1->insertion, 2->deletion, 3->inorder,4->lca,5->checking for bst,6->create Linkedlist\n");
	while(1)
	{
		printf("enter selection\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				/*printf("enter data\n");
				scanf("%d",&data);*/
				root=insert(root,6);
				root=insert(root,4);
				root=insert(root,4);
				root=insert(root,5);
				root=insert(root,3);
				root=insert(root,2);
				root=insert(root,10);
				root=insert(root,14);
				root=insert(root,8);
				root=insert(root,11);
				root=insert(root,9);
				root=insert(root,12);
				break;
			case 2:
				printf("enter key to delete\n");
				scanf("%d",&key);
				root=delete(root,key);
				break;
			case 3:
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("enter a,b\n");
				scanf("%d%d",&a,&b);
				if(lca(root,a,b))
				printf("lca=%d\n",lca(root,a,b)->data);
				break;
			case 5:
				if(isbst(root,INT_MIN,INT_MAX))
				printf("is a bst\n");
				else 
				printf("not a bst\n");
				break;
			case 6:
				printdll(dll(root));
				printf("\n");
				break;
			default:
				printf("invalid choice\n");
				exit(1);
				break;
		}
	}
	return 0;
}
