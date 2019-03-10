#include"myheader.c"
int pos=1;
void search(NODE* head,int r)
{
NODE* temp=head;
printf("Enter roll to be searched:\n");
scanf("%d",&r);
while(temp)
{ 
	if(temp->roll==r)
	{
	printf("Roll %d found at %d",r,pos);
	break;
	}
	temp=temp->link;
	pos++;
	if(temp==NULL)
	{
	printf("Roll not found in the list\n");
	}
}
}

