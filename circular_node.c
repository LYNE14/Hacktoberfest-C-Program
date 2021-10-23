#include<stdio.h>
#include<stdlib.h>

struct cnode
{
	int data;
	struct cnode *next;
}*head;

	void create_list(int A[], int n)
{   
    struct cnode *temp, *last; int i;
    
	head= (struct cnode*)malloc(sizeof(struct cnode));
	head->data=A[0];
	head->next=NULL;
	last=head;
	for(i=1;i<n;i++)
	{   temp= (struct cnode*)malloc(sizeof(struct cnode));
		temp->data=A[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}
	last->next=head;
}
void check_empty()
{
	if(head==NULL)
	{
		printf("NULL");
	}
}

void print()
{   struct cnode *temp= (struct cnode*)malloc(sizeof(struct cnode ));
	temp=head;
		printf("\n the linked list: \n");
		printf("%d ->", temp->data);
		temp=temp->next;
	while (temp!=head)
	{ 
		printf("%d -> ", temp->data);
		temp=temp->next;
	}
}
int main()
{  int i,n;
    printf("enter the number of elements :");
    scanf("%d", &n);
    int A[n];
    printf("enter the elements: \n");
    
	for( i=0;i<n;i++)
	  scanf("%d", &A[i]);
	  
	create_list (A,n);
	print();
}
