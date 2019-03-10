#include<stdio.h>
main()
{
int a=1,c;
//printf("c=%d\n",a++);
//printf("c=%d\n",a++ + a++);
//printf("c=%d\n",a++ +a++ +a++ +a++);
//printf("c=%d\n",++a);
//printf("c=%d",++a + ++a);
//printf("c=%d\n",++a + ++a + ++a + ++a);
//printf("c=%d\n",a++ + ++a);
//printf("c=%d\n",++a + a++);
//printf("c=%d\n",a++ + ++a + a++ + ++a);
c=++a + a++ + ++a + a++;
printf("c=%d\n",c);
//printf("%d\n",c);

}


