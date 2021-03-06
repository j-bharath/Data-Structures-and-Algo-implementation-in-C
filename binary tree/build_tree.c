#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int preindex;
struct Btree
{
	int data;
	struct Btree *left;
	struct Btree *right;
};

typedef struct Btree btree;

int find(int inorder[],int start,int end,int key)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(inorder[i]==key)
		return i;
	}
}

btree *buildTree(int inorder[],int preorder[],int start,int end)
{
	btree *temp;
	int inindex=0;
	if(start>end)
	return 0;
	temp=(btree*)malloc(sizeof(struct Btree));
	if(!temp)
	{
		printf("no space\n");
		exit(1);
	}
	temp->data=preorder[preindex++];
	if(start==end)
	return temp;
	inindex=find(inorder,start,end,temp->data);
	temp->left=buildTree(inorder,preorder,start,inindex-1);
	temp->right=buildTree(inorder,preorder,inindex+1,end);
	return temp;
}

void preorderprint(btree *root)
{
	if(root)
	{
		printf("%d\t",root->data);
		preorderprint(root->left);
		preorderprint(root->right);	
	}
}

int main()
{
	int inorder[]={4,2,5,1,6,3};
	int preorder[]={1,2,4,5,3,6};
	btree *root;
	preindex=0;
	root=buildTree(inorder,preorder,0,5);
	preorderprint(root);
	return 0;
}
