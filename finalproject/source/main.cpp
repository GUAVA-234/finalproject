#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"../include/user.h"
int difficulty = 0;
struct play
{
	int HP, attackrate, healrate;
};
int main(void)
{	
	play play1;
	while(difficulty != 1 && difficulty !=2 && difficulty!=3)
	{ 
	printf_s("�п������\n");
	printf_s("(1)²��(2)���q(3)�x��\n");
	scanf_s("%d", &difficulty);
	}
	int boss;
	boss = game(difficulty);
	/*while (boss!=0&&play.HP!=0)
	{
		
	}*/
	play1.HP;
	timerand();
	return 0;
}
