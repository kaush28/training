#include"myheader.c"
void print(NODE *p)
{
	//extern NODE* head;
	NODE*temp=p;
if(p==NULL)
{
	printf("List is Empty\n");
	return;
}
  while(temp)
  {
  printf("%d %s %0.2f\n",temp->roll,temp->name,temp->mark);
  temp=temp->link;
  }
}
