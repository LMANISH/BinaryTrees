#include<stdio.h>
#include<stdlib.h>
 
struct node 
{
    int data;
    struct node * left;
    struct node * right;
};
 
struct node* newnode(int data);

int preIndex=0;

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

struct node * newnode(int data)
{

  struct node * node=(struct node *)malloc(sizeof(struct node));
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;

  return (node);
}

int maxDepth(struct node * node) 
{
   if (node==NULL) 
       return -1;
   else
   {
       
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
 

struct node * newNode(int data) 
{
    struct node * node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
   
    return(node);
}
   
int main()
{
  int in[]={7,10,11,12,13,21,27};
  int pre[]={12,10,7,11,21,13,27};
  struct node * root= btree(in, pre,0,6);
  maxDepth(root);
  printf("Hight of tree is %d\n", maxDepth(root));
  return 0;
}