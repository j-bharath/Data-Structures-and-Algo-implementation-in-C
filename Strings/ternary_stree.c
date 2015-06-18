#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
	char data;
	int isword;
	struct tree *left;
	struct tree *right;
	struct tree *equal;
};

typedef struct tree tree;

tree *insert(tree *root,char *word)
{
	if(!root)
	{
		root=(tree*)malloc(sizeof(struct tree));
		root->left=0;root->right=0;root->equal=0;
		root->isword=0;
		root->data=*word;
	}
	if(*word<root->data)
	root->left=insert(root->left,word);
	else if(*word==root->data)
	{
		if(*(word+1))
		root->equal=insert(root->equal,word+1);
		else
		root->isword=1;
	}
	else
	root->right=insert(root->right,word);
	return root;
}

int search(tree *root,char *word)
{
	if(!root)
	return -1;
	if(*word<root->data)
	search(root->left,word);
	else if(*word>root->data)
	search(root->right,word);
	else
	{
		if(root->isword && *(word+1)==0)
		return 1;
		search(root->equal,word+1);
	}
}

int main()
{
	tree *root=0;
	root=insert(root,"bharath");
	root=insert(root,"yashasvi");
	printf("%d",search(root,"bharath"));
	return 0;
}
