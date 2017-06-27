#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node * adr;
};

struct node * head=NULL;
struct node * Insert(int x)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	struct node * temp1=(struct node *)malloc(sizeof(struct node));

	temp->data = x;
	temp->adr=head;
	head= temp;  
return 0;
}

int Reverse()
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	struct node * temp1=(struct node *)malloc(sizeof(struct node));
	if(temp->adr == NULL)
	{
		head=temp;
		return 0;	
	}
	temp=temp->adr;
	Reverse();
	struct node * temp1 = temp->adr;
	temp1->adr=temp;
	temp->adr=NULL;
	return 0;
}

int Print()
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	printf("%d",temp->data);
	temp=temp->adr;
	Print();
	return 0;
}

int main()
{
	int num,i,data;
	printf("Enter no of elements");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("Enter the element");
		scanf("%d",&data);
		Insert(data);
	}
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	Reverse();
	Print();
}