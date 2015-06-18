#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TONUM(c) ((int)c-(int)'a');

struct trie
{
	int value;//0->not word,1->end of word
	struct trie *children[26];	
};

typedef struct trie trie;

trie *create_trie()
{
	trie *root;
	int i;
	root=(trie*)malloc(sizeof(struct trie));
	if(!root)
	{
		printf("no space\n");
		exit(1);
	}
	root->value=0;
	for(i=0;i<26;i++)
	{
		root->children[i]=0;
	}
	return root;
}

void insert(trie *root,char word[])
{
	trie *temp;
	int level,index,length;
	temp=root;
	length=strlen(word);
	for(level=0;level<length;level++)
	{
		index=TONUM(word[level]);
		if(!temp->children[index])
		{
			temp->children[index]=create_trie();
		}
		temp=temp->children[index];
	}
	temp->value=1;
}

int search(trie *root,char key[])
{
	trie *temp;
	int index,level,length;
	length=strlen(key);
	temp=root;
	for(level=0;level<length;level++)
	{
		index=TONUM(key[level]);
		if(!temp->children[index])
		return 0;
		temp=temp->children[index];
	}
	return temp->value;
}


int main()
{
	trie *root=0;
	root=create_trie();
	insert(root,"the");
	insert(root,"a");
	insert(root,"their");
	insert(root,"there");
	insert(root,"answer");
	insert(root,"any");
	insert(root,"bye");
	insert(root,"by");
	if(search(root,"these"))
	printf("present\n");
	else
	printf("not present\n");
	return 0;
}
