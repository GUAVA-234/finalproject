#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"../include/user.h"
//函數庫
int difficulty = 0;
struct player
{
	int HP, attackrate, healrate;
	// 血量  攻擊倍率	治療倍率
};	player play1, play2, play3;

int main(void)
{	
	play1.HP = 100;
	play2.HP = 100;
	play3.HP = 100;
	while(difficulty != 1 && difficulty !=2 && difficulty!=3)
	{ 
	printf_s("請選擇難度\n");
	printf_s("(1)簡單(2)普通(3)困難\n");
	scanf_s("%d", &difficulty);
	}

	int boss = game(difficulty);
	//BOSS血量
	while (boss != 0 && play1.HP != 0 && play2.HP != 0 && play3.HP != 0)
	{
		printf_s("BOSS血量 %d\n", boss);
		
		//play2.HP = 0;
	//	printf_s("%d\n", play2.HP);
		
	}
	//主遊戲迴圈
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//產生1~15的亂數
	return 0;
}
