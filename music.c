#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Data
{
	char name[20],address[200],email[100],phone[11],SIN[10];
	int age;
	char gender; 
	double SavingBal, CheckBal;
};

typedef struct Data data;

struct Client
{
	data *account;
	struct Client *next;
};

typedef struct Client client;

void addClient(client **head)
{
	data *temp;
	client *person;
	int i;
	temp=(data*)malloc(sizeof(struct Data));
	person=(client *)malloc(sizeof(struct Client));
	if(!temp || !person)
	{
		printf("no space\n");
		exit(1);
	}
	printf("enter first name\n");
	scanf("%s",temp->name);
	printf("enter address with _ for spaces or else program goes nuts and press enter\n");
	scanf("%s",temp->address);
	/*printf("enter email, phone and SIN\n");
	scanf("%s%s%s",temp->email,temp->phone,temp->SIN);
	printf("enter age and gender");
	scanf("%d%c",&age,&gender);
	temp->SavingBal=0;temp->CheckBal=0;*/
	person->account=temp;
	person->next=*head;
	*head=person;
}

void deleteClient(client **head)
{
	char line[100];
	client *temp,*curr;
	printf("enter address of the client to delete\n");
	scanf("%s",line);
	temp=*head;
	while(!temp)
	{
		if(strcmp(temp->account->address,line)==0)
		{
			curr=temp;
			temp->
		}
	}
}


void printList(client *head)
{
	client *temp;
	if(!head)
	{
		printf("no information\n");
		return;
	}
	temp=head;
	while(temp)
	{
		printf("name:%s\n",temp->account->name);
		puts(temp->account->address);
		printf("\n");
		temp=temp->next;
	}
}

int main()
{
	client *head=0;
	int selection;
	printf("enter 1->insert,2->delete,3->print,4->to exit when done\n");
	while(1)
	{
		printf("enter ur selection\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				addClient(&head);
				break;
			case 2:
				deleteClient(&head);
				break;
			case 3:
				printList(head);
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("invalid choice\n");
				break;
		}
		
	}
	return 0;
}
