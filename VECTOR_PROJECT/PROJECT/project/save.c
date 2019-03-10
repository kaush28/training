#include"myheader.c"
void save(NODE*head)
{
NODE *temp=head;
FILE *fp;
fp=fopen("ST.DAT","w");
while(temp)
{
fwrite(temp,sizeof(NODE)-sizeof(NODE*),1,fp);
printf("%d %s %f\n",temp->roll,temp->name,temp->mark);
temp=temp->link;
}
fclose(fp);
}
