#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};


int search(int arr[], int start, int end, int value);
struct node* newnode(int data);
int preIndex=0,n=0,k;
int a[7]={0};

struct node *  btree(int in[], int pre[],int instart, int inend)
{
	
	if(instart>inend)
	{
		return NULL;
	}

	struct node * tnode = newnode(pre[preIndex++]);
	if(instart == inend)
	{
		return tnode;
	}

	int inIndex = search(in, instart, inend, tnode->data);
	tnode->left  = btree(in,pre,instart,inIndex-1);
	tnode->right = btree(in,pre,inIndex+1,inend);

	return tnode;
}

int search(int arr[],int start, int end, int value)
{
	int i;
	for(i=start; i<=end ;i++)
	{
		if(arr[i] ==value)
		{
			return i;
		}

	}
	return 0;
}

struct node * newnode(int data)
{

    struct node * node=(struct node *)malloc(sizeof(struct node));
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return (node);
}

int printk(struct node * node)
{
	
	if(node== NULL)
	{
		return 0 ;
	}

	printk(node->left);
	a[n]=node->data;n++;
	printk(node->right);
	return 0;

}



int main()
{
	int in[]={7,10,11,12,13,21,27};
	int pre[]={12,10,7,11,21,13,27};
	struct node * root= btree(in, pre,0,6);
	printf("Enter the k th value ");
	scanf("%d",&k);
	printk(root);
	printf("%d",a[k-1]);
	
}


