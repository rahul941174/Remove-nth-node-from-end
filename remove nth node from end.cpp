#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int info;
	struct node* next;
};
typedef struct node node;
void removeNthFromEnd(node** head, int n){
       node* temp=*head;
       int size=1;
       while(temp->next!=NULL)
       {
           temp=temp->next;
           size++;
       }
       temp=*head;
       n=size-n;
       for(int i=0;i<n-1;i++)
       {
           temp=temp->next;
       }
       node* temp2=temp->next;
        temp->next=temp2->next;
       temp2->next=NULL;
       free(temp2);
}
void insert(node** head,int v)
{
	node*temp=NULL;
	temp=(node*)malloc(sizeof(node));
	temp->info=v;
	int k=temp->info;
	temp->next=NULL;
	if(*head==NULL||k<(*head)->info)
	{
		temp->next=(*head);
		(*head)=temp;
	}
	else
	{
		node* temp1=(*head);
		while(temp1->next!=NULL&&k>(temp1->next->info))
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
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
    insert(&head,4);
    insert(&head,8);
     insert(&head,7);
    insert(&head,2);
    display(head);
  	removeNthFromEnd(&head,3);
  	display(head);
}	
