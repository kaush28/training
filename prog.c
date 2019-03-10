#include<stdio.h>
main()
{
	printf("good morning\n");
	f1();
}
f1()
{
	printf("hello\n");
	f2();
	printf("returning to main\n");
}
f2()
{
	printf("welcome\n");
	printf("back to f1\n");
}
