#include<stdio.h>
#include<stdlib.h>
struct tree
{
int data;
struct tree *left,*right;	
};
void insert(struct tree **node,int data)
{
struct tree *nu;
if(*node==NULL)
{
nu=malloc(sizeof(struct tree));
nu->left=NULL;
nu->right=NULL;
nu->data=data;
*node=nu;
}
else if((data)<((*node)->data))
{
insert(&((*node)->left),data);
}
else if((data)>((*node)->data))
{
insert(&((*node)->right),data);
}
}
void preorder(struct tree *node)
{
if(node==NULL)
return;
else
{
printf("%d,",node->data);
preorder(node->left);
preorder(node->right);
}
}
void inorder(struct tree *node)
{
if(node==NULL)
return;
else
{
inorder(node->left);
printf("%d,",node->data);
inorder(node->right);
}
}
void postorder(struct tree *node)
{
if(node==NULL)
return;
else
{
postorder(node->left);
postorder(node->right);
printf("%d,",node->data);
}
}
struct tree *search(struct tree *node,int v)
{
struct tree *temp;
if(node==NULL)
return NULL;
else if(v<node->data)
	search(node->left,v);
else if(v>node->data)
	search(node->right,v);
else
return node;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct tree *findmin(struct tree *node)
{
if(node==NULL)
return NULL;
else if(node->left)
return findmin(node->left);
else
return node;
}
//////////////////////////////////////////////////////////
struct tree *delete(struct tree *node,int v)
{
struct tree *temp;
if(node==NULL)
printf("data not found.\n");
else if(v<node->data)
	delete(node->left,v);
else if(v>node->data)
	delete(node->right,v);
else if(node->left && node->right)
{
temp=findmin(node->right);
node->data=temp->data;
node->right=delete(node->right,node->data);
}
else
temp=node;
if(node->left==NULL)
{
node=node->right;
free(temp);
}
else if(node->right==NULL)
{
node=node->left;
free(temp);
}
return node;
}
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
main()
{
int choice,data,v;
struct tree *root=NULL;
struct tree *temp;
while(1)
{
printf("*****menu*****\n");
printf("1:insert\n2:preorder\n3:postorder\n4:inorder\n5:search\n6:delete\n");
printf("enter ur option: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
	printf("enter the data: ");
	scanf("%d",&data);
	insert(&root,data);
	break;
case 2:
	preorder(root);
	break;
case 3:
	postorder(root);
	break;
case 4:
	inorder(root);
	break;
case 5:
	printf("enter the data to search: ");
	scanf("%d",&v);
	temp=search(root,v);
	if(temp==NULL)
	printf("data not found.\n");
	else
	printf("data found at %u",temp);
	break;
case 6:
	printf("enter the data to delete:");
	scanf("%d",&v);
	root=delete(root,v);
	break;
default:
	printf("invalid option.\n");
}
}
}
