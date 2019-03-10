#include<stdio.h>
//////////////////////////////////////
void topper(int (*p)[5])
{
int total=0,i,j,temp;
int s[20]={0};
for(i=0;i<10;i++)
{
for(j=0;j<5;j++)
{
s[i]=s[i]+p[i][j];
}
}
printf("\n");
for(i=0;i<10;i++)
{
printf("%d,",s[i]);
}
temp=s[0];
for(i=0;i<10;i++)
{
if(temp<s[i])
temp=s[i];
}
printf("\nthe highest marks is stored by: ");
for(i=0;i<10;i++)
{
if(s[i]==temp)
printf("s[%d]",i);
}
printf("\n");
}
/////////////////////////////////////////////
void subject(int (*p)[5])
{
int i,j,sub[10]={0},total=0,temp;
for(i=0;i<5;i++)
{
for(j=0;j<10;j++)
{
sub[i]=sub[i]+p[i][j];
}
}
for(i=0;i<5;i++)
{
printf("%d,",sub[i]);
}
temp=sub[0];
for(i=0;i<5;i++)
{
if(temp>sub[i])
temp=sub[i];
}
printf("\nthe lowest marks is stored in: ");
for(i=0;i<5;i++)
{
if(sub[i]==temp)
printf("sub[%d]",i);
}
printf("\n");
}
////////////////////////////////////////////////////
void highest(int (*p)[5])
{
int i,j,temp;
temp=p[0][0];
for(i=0;i<10;i++)
{
for(j=0;j<5;j++)
{
if(temp<p[i][j])
temp=p[i][j];
}
}
printf("the highest marks is scored by: \n");
for(i=0;i<10;i++)
{
for(j=0;j<5;j++)
{
if(temp==p[i][j])
printf("subject=%d , student=%d\n",j,i);
}
}
}
///////////////////////////////////////////////////
main()
{
int marks[10][5];
int i,j;
srand(getpid());
for(i=0;i<10;i++)
{
for(j=0;j<5;j++)
{
marks[i][j]=rand()%101;
}
}
for(i=0;i<10;i++,printf("\n"))
{
for(j=0;j<5;j++)
{
printf("%5d",marks[i][j]);
}
}
topper(marks);
subject(marks);
highest(marks);
}
