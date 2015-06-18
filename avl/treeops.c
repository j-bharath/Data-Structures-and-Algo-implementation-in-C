#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AVL
{
	int data;
	struct AVL *left;
	struct AVL *right;
	int ht;
};

typedef struct AVL avl;

int height(avl *node)
{
	if(!node)
	return -1;
	return(node->ht);
}

int max(int a,int b)
{
	return(a>b?a:b);
}

avl *llshift(avl *x)
{
	avl *temp;
	temp=x->left;
	x->left=temp->right;
	temp->right=x;
	x->ht=max(height(x->left),height(x->right))+1;
	temp->ht=max(x->ht,height(temp->left))+1;
	return temp;
}

avl *rrshift(avl *x)
{
	avl *temp;
	temp=x->right;
	x->right=temp->left;
	temp->left=x;
	x->ht=max(height(x->left),height(x->right))+1;
	temp->ht=max(x->ht,height(x->right)+1);
	return temp;
}

avl *lrshift(avl *x)
{
	x->left=rrshift(x->left);
	return(llshift(x));
}

avl *rlshift(avl *x)
{
	x->right=llshift(x->right);
	return(rrshift(x));
}

avl *insert(avl *root,int data)
{
	if(!root)
	{
		root=(avl*)malloc(sizeof(struct AVL));
		if(!root)
		{
			printf("no space\n");
			exit(1);
		}
		root->data=data;
		root->left=root->right=0;
		root->ht=0;
	}
	else if(data<root->data)
	{
		root->left=insert(root->left,data);
		if(height(root->left)-height(root->right)==2)
		{
			if(data<root->left->data)
			root=llshift(root);
			else
			root=lrshift(root);
		}
	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);
		if(height(root->right)-height(root->left)==2)
		{
			if(data>root->right->data)
			root=rrshift(root);
			else
			root=rlshift(root);
		}
	}
	root->ht=max(height(root->left),height(root->right))+1;
	printf("ht=%d,root=%d\n",root->ht,root->data);
	return root;
}

void inorder(avl *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void preorder(avl *root)
{
	if(root)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	avl *root;
	root=insert(root,4);
	root=insert(root,2);
	root=insert(root,7);
	root=insert(root,6);
	root=insert(root,8);
	preorder(root);
	printf("\n");
	root=insert(root,5);
	preorder(root);
	printf("\n");
	return 0;
}
