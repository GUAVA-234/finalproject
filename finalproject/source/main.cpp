#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"../include/user.h"
//��Ʈw
int difficulty = 0;
struct player
{
	int HP, attackrate, healrate;
	// ��q  �������v	�v�����v
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
		printf_s("�п������\n");
		printf_s("(1)²��(2)���q(3)�x��\n");
		scanf_s("%d", &difficulty);
	}

	int boss = game(difficulty);
	//BOSS��q
	while (boss != 0 && play1.HP != 0 && play2.HP != 0 && play3.HP != 0)
	{
		printf_s("BOSS��q %d\n", boss);
		printf_s("player1��q %d   player2��q %d   player3��q %d\n", play1.HP, play2.HP, play3.HP);
		printf_s("%d\n", counter1 % 1);
		if (counter1 % 1 == 0)
		{
			int a = 0;
			printf_s("player1�^�X\n");
			printf_s("1���� 2�v��\n");
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
			printf_s("player2�^�X\n");
			printf_s("1���� 2�v��\n");
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
			printf_s("player3�^�X\n");
			printf_s("1���� 2�v��\n");
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
	//�D�C���j��
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//����1~15���ü�
	return 0;
}
