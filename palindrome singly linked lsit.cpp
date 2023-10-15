#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node{
	int info;
	struct node* next;
};
typedef struct node node;
void insert(node** head,int v)
{
	node* temp=NULL;
	temp=(node*)malloc(sizeof(node));
	temp->info=v;
	temp->next=NULL;
	node* temp2;
	if(*head==NULL)
	{
		(*head)=temp;
		temp2=temp;
	}
	else
	{
	
		temp2->next=temp;
		temp2=temp;
		
	}
}
int oddinfo(node* head)
{
	int co=0;
	if((head)==NULL)
	{
		co=0;
	}
	else
	{
		while(head!=NULL)
		{
			if((head->info)%2!=0)
			{
				co++;
			}
			head=head->next;
		}
	}
	return co;
}
void display(node* head)
{
	node* temp=head;
	if(head==NULL)
	{
		printf("Noting to print");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d  ",temp->info);
			temp=temp->next;
		}
	}
	printf("\n");
}
int main()
{
    node* head=NULL;
    insert(&head,1);
    insert(&head,7);
    insert(&head,8);
    insert(&head,7);
    insert(&head,1);
    display(head);
    int c=oddinfo(head);
    printf("no. of odd infos are %d",c);

}	
