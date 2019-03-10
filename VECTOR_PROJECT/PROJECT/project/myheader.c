#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student{
	                int roll;
			char name[20];
			float mark;	
			struct student *link;
		      }NODE;

