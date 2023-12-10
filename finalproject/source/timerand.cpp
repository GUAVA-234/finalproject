#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int timerand()
{
	srand((time(0))+110);
	printf_s("%d", rand()%15+1 );

	return 0;
}