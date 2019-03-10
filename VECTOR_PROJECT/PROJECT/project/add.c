#include"myheader.c"
NODE *add(NODE *head)
{
NODE *nu,*temp=head;
nu=calloc(1,sizeof(NODE));

printf("Enter roll:");
scanf("%d",&(nu->roll));
printf("Enter name:");
scanf(" %s",nu->name);
printf("Enter mark:\n");
scanf("%f",&(nu->mark));
if(head==NULL)
{ 
 head=nu;
}
else
{
nu->link=0;
temp=head;
while(temp->link)
 temp=temp->link;
temp->link=nu;
}
return head;
}
