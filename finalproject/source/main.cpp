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
int counter1, counter2, counter3 = 0;
int main(void)
{
	play1.HP = 100;
	play2.HP = 100;
	play3.HP = 100;
	play1.attackrate = 10;
	play2.attackrate = 15;
	play3.attackrate = 20;
	play1.healrate = 5;
	play2.healrate = 7;
	play3.healrate = 10;
	while (difficulty != 1 && difficulty != 2 && difficulty != 3)
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
		printf_s("player1血量 %d   player2血量 %d   player3血量 %d\n", play1.HP, play2.HP, play3.HP);
		printf_s("%d\n", counter1 % 1);
		if (counter1 % 1 == 0)
		{
			int a = 0;
			printf_s("player1回合\n");
			printf_s("1攻擊 2治療\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				boss = boss - timerand(play1.attackrate);
				break;
			case 2:
				play1.HP = play1.HP + timerand(play1.healrate);
				break;
			}
		}
		if (counter1 % 2 == 0)
		{
			int a = 0;
			printf_s("player2回合\n");
			printf_s("1攻擊 2治療\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				boss = boss - timerand(play2.attackrate);
				break;
			case 2:
				play2.HP = play2.HP + timerand(play2.healrate);
				break;
			}
		}
		if (counter1 % 3 == 0)
		{
			int a = 0;
			printf_s("player3回合\n");
			printf_s("1攻擊 2治療\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				boss = boss - timerand(play3.attackrate);
				break;
			case 2:
				play3.HP = play3.HP + timerand(play3.healrate);
				break;
			}
		}
		//play2.HP = 0;
	//	printf_s("%d\n", play2.HP);
		counter1 += 1;
		counter2 += 1;
		counter3 += 1;
	}
	//主遊戲迴圈
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//產生1~15的亂數
	return 0;
}
