#include"myheader.c"
NODE*del(NODE*head)
{
int r;
NODE*temp,*pre;
if(head==NULL)
{
printf("List is empty..\n");
return head;
}
printf("Enter rol to del..\n");
scanf("%d",&r);
temp=head;
while(temp)
{
 if(temp->roll!=r)
{
 pre=temp;
 temp=temp->link;
}
else
break;
}
if(temp==NULL)
{
printf("rol not found..\n");
return head;
}
if(temp==head)
{ 
head=head->link;
free(temp);
printf("Deletion successful...\n");
}
else
{
pre->link=temp->link;
free(temp);
printf("Deletion successful..\n");
}
return head;
}
