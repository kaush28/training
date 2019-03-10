#include"myheader.c"
NODE* mod(NODE* head)
{
int r;
printf("Enter roll no. in which data to be modified:\n");
scanf("%d",&r);
getchar();
NODE* temp=head;
while(temp)
{
	if(temp->roll==r)
	{
	printf("Name to be replaced:\n");
	scanf("%s",temp->name);
	printf("Enter marks to modify:\n");
	scanf("%f",&(temp->mark));
	break;
	}
	temp=temp->link;	
	if(temp==NULL)
	{
	printf("Roll not found");
	}
}
return head;
}

