#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int timerand( int a)
{
	srand((time(0))+110);
	//printf_s("%d", rand()%a+1 );
	return a ;
}