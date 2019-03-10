#include"myheader.c"
NODE* rev(NODE* head)
{
int r;
NODE *prev,*temp,*next;
prev=NULL;
temp=head;
printf("Enter roll no.of which data to br reversed:\n");
scanf("%d",&r);
while(temp)
{
	next=temp->link;
	temp->link=prev;
	prev=temp;
	temp=next;
}
head=prev;
return head;
}
