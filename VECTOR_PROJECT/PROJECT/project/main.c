#include"myheader.c"
NODE*add(NODE*);
NODE*mod(NODE*);
NODE*rev(NODE*);
NODE* updatelist(NODE* head);
main()
{
NODE *head=0;
char choice;
head=updatelist(head);
	while(1)
	{
	printf("\n***Menu***\n");
	printf("a:add\np:print\nd:del\ns:save\nm:mod\nf:search\nv:rev\nr:return\n");
	printf("Enter ur choice\n");
	scanf(" %c",&choice);
	
	switch(choice)
	{
	case 'a':head=add(head);
		 break;
	case 'p':print(head);
		 break;
	case 'd':del(head);
		 break;
	case 'm':head=mod(head);break;
	case 'f':search(head);break;
	case 'v':head=rev(head);break;
	case 'r':save(head);return;
	/*case 's':head=updatelist(head);
		 break;*/
	default:printf("Invalid choice\n");
	

 	}	
}
}

NODE* updatelist(NODE* head)
{
NODE v;
FILE*fp;
NODE*nu,*temp;
fp=fopen("ST.DAT","r");
while((fread(&v,sizeof(NODE)-4,1,fp))==1)
{
	nu=calloc(1,sizeof(NODE));
	memcpy(nu,&v,sizeof(NODE)-4);	
	if(head==0)
	{
	head=nu;
	temp=nu;
	}
	else
	{
	temp->link=nu;
	temp=nu;
	}
}
fclose(fp);
return head;
}

