#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int timerand( int a)
{
	srand((time(0))+110);
	//printf_s("��BOSS �y���ˮ` %d \n", rand()%a+1 );
	return rand() % a + 1;
}