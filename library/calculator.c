#include<stdio.h>
#include<dlfcn.h>
int sum(int,int);
int difference(int,int);
int product(int,int);
int division(int,int);
main()
{
void *handle;
int (*p)(int,int);
int a,b,result,choice;
printf("enter the value of a: ");
scanf("%d",&a);
printf("enter the value of b: ");
scanf("%d",&b);
printf("\n1:sum\n2:difference\n3:product\n4:division\n");
printf("enter the choice: ");
scanf("%d",&choice);
if(choice==1)
//result=sum(a,b);
{
handle=dlopen("./libDynamic.so",RTLD_LAZY);
p=dlsym(handle,"sum");
result=(*p)(a,b);
dlclose(handle);
}
else if(choice==2)
//result=difference(a,b);
{
handle=dlopen("./libDynamic.so",RTLD_LAZY);
p=dlsym(handle,"difference");
result=(*p)(a,b);
dlclose(handle);
}
else if(choice==3)
//result=product(a,b);
{
handle=dlopen("./libDynamic.so",RTLD_LAZY);
p=dlsym(handle,"product");
result=(*p)(a,b);
dlclose(handle);
}
else if(choice==4)
//result=division(a,b);
{
handle=dlopen("./libDynamic.so",RTLD_LAZY);
p=dlsym(handle,"division");
result=(*p)(a,b);
dlclose(handle);
}
else
printf("inalid option");
printf("\n%d\n",result);
}
