#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"../include/user.h"
//函數庫
int difficulty = 0;
int counter1, counter2, counter3 = 0;
struct player
{
	int HP, attackrate, healrate;
	// 血量  攻擊倍率	治療倍率
};	player play1, play2, play3;
int randomAttackDamage() {
	// 隨機生成攻擊傷害
	return rand() % 20 + 10; // 傷害在10到30之間
}
void bossAttackOnePlayer(player& p, int playerNumber) {
	if (p.HP > 0) {
		int damage = randomAttackDamage();
		p.HP -= damage;
		printf("BOSS 對玩家 %d 造成 %d 點傷害！\n", playerNumber, damage);
		if (p.HP <= 0) {
			printf("玩家 %d 已被打敗！\n", playerNumber);
		}
	}
}

int main(void)
{	
	srand(time(NULL));
	play1.HP = 100;
	play2.HP = 100;
	play3.HP = 100;
	play1.attackrate = 10;
	play2.attackrate = 15;
	play3.attackrate = 20;
	play1.healrate = 20;
	play2.healrate = 30;
	play3.healrate = 40;
	while(difficulty != 1 && difficulty !=2 && difficulty!=3)
	{ 
	printf_s("請選擇難度\n");
	printf_s("(1)簡單(2)普通(3)困難\n");
	scanf_s("%d", &difficulty);
	}

	int boss = game(difficulty);
	//BOSS血量
	
	while (boss > 1 && (play1.HP != 0 || play2.HP != 0 || play3.HP !=0))
	{
		printf_s("第 %d 回合 \n ", counter1 + 1);		
		int playerToAttack = rand() % 3 + 1; // 隨機選擇一個玩家進行攻擊
		if (playerToAttack == 1) {
			bossAttackOnePlayer(play1, 1);
		}
		else if (playerToAttack == 2) {
			bossAttackOnePlayer(play2, 2);
		}
		else if (playerToAttack == 3) {
			bossAttackOnePlayer(play3, 3);
		}
		if (play1.HP < 0)play1.HP = 0;
		if (play2.HP < 0)play2.HP = 0;
		if (play3.HP < 0)play3.HP = 0;
		if ((counter1 % 1 == 0) && (play1.HP!=0))
		{
			int a = 0;
			int b = 0;
			printf_s("player1回合\n");
			printf_s("1攻擊 2治療\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				b = timerand(play1.attackrate);
				boss = boss - b;
				printf_s("玩家1攻擊 BOSS 造成 %d !\n", b);
				break;
			case 2:
				b = timerand(play1.healrate);
				play1.HP = play1.HP + b;
				printf_s("玩家1回復%d\n", b);
				break;
			}
		}
		if ((counter1 % 2 == 0) && (play2.HP != 0))
		{
			int a = 0;
			int b = 0;
			printf_s("player2回合\n");
			printf_s("1攻擊 2治療\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				b = timerand(play2.attackrate);
				boss = boss - b;
				printf_s("玩家2攻擊 BOSS 造成 %d !\n", b);
				break;
			case 2:
				b = timerand(play2.healrate);
				play2.HP = play2.HP + b;
				printf_s("玩家2回復%d\n",b);
				break;
			}
		}
		if ((counter1 % 3 == 0) && (play3.HP != 0))
		{
			int a = 0;
			int b = 0;
			printf_s("玩家3回合\n");
			printf_s("1攻擊 2治療\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				b = timerand(play3.attackrate);
				boss = boss - b;
				printf_s("玩家3攻擊 BOSS 造成 %d !\n", b);
				break;
			case 2:
				b = timerand(play3.healrate);
				play3.HP = play3.HP + b;
				printf_s("玩家3回復%d\n", b);
				break;
			}
		}
		//play2.HP = 0;
	//	printf_s("%d\n", play2.HP);
		counter1 += 1;
		counter2 += 1;
		counter3 += 1;

		
		if (boss > 1) {
			printf_s("\n\n\nBOSS血量 %d\n", boss);
			printf_s("player1血量 %d   player2血量 %d   player3血量 %d\n", play1.HP, play2.HP, play3.HP);
		}
		else
		{
			printf_s("恭喜過關");
		}
	}

	//主遊戲迴圈
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//產生1~15的亂數
	return 0;
}
