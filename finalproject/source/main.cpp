#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"../include/user.h"
//��Ʈw
int difficulty = 0;
int counter1, counter2, counter3 = 0;
struct player
{
	int HP, attackrate, healrate;
	// ��q  �������v	�v�����v
};	player play1, play2, play3;
int randomAttackDamage() {
	// �H���ͦ������ˮ`
	return rand() % 20 + 10; // �ˮ`�b10��30����
}
void bossAttackOnePlayer(player& p, int playerNumber) {
	if (p.HP > 0) {
		int damage = randomAttackDamage();
		p.HP -= damage;
		printf("BOSS �缾�a %d �y�� %d �I�ˮ`�I\n", playerNumber, damage);
		if (p.HP <= 0) {
			printf("���a %d �w�Q���ѡI\n", playerNumber);
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
	printf_s("�п������\n");
	printf_s("(1)²��(2)���q(3)�x��\n");
	scanf_s("%d", &difficulty);
	}

	int boss = game(difficulty);
	//BOSS��q
	
	while (boss > 1 && (play1.HP != 0 || play2.HP != 0 || play3.HP !=0))
	{
		printf_s("�� %d �^�X \n ", counter1 + 1);		
		int playerToAttack = rand() % 3 + 1; // �H����ܤ@�Ӫ��a�i�����
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
			printf_s("player1�^�X\n");
			printf_s("1���� 2�v��\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				b = timerand(play1.attackrate);
				boss = boss - b;
				printf_s("���a1���� BOSS �y�� %d !\n", b);
				break;
			case 2:
				b = timerand(play1.healrate);
				play1.HP = play1.HP + b;
				printf_s("���a1�^�_%d\n", b);
				break;
			}
		}
		if ((counter1 % 2 == 0) && (play2.HP != 0))
		{
			int a = 0;
			int b = 0;
			printf_s("player2�^�X\n");
			printf_s("1���� 2�v��\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				b = timerand(play2.attackrate);
				boss = boss - b;
				printf_s("���a2���� BOSS �y�� %d !\n", b);
				break;
			case 2:
				b = timerand(play2.healrate);
				play2.HP = play2.HP + b;
				printf_s("���a2�^�_%d\n",b);
				break;
			}
		}
		if ((counter1 % 3 == 0) && (play3.HP != 0))
		{
			int a = 0;
			int b = 0;
			printf_s("���a3�^�X\n");
			printf_s("1���� 2�v��\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
				b = timerand(play3.attackrate);
				boss = boss - b;
				printf_s("���a3���� BOSS �y�� %d !\n", b);
				break;
			case 2:
				b = timerand(play3.healrate);
				play3.HP = play3.HP + b;
				printf_s("���a3�^�_%d\n", b);
				break;
			}
		}
		//play2.HP = 0;
	//	printf_s("%d\n", play2.HP);
		counter1 += 1;
		counter2 += 1;
		counter3 += 1;

		
		if (boss > 1) {
			printf_s("\n\n\nBOSS��q %d\n", boss);
			printf_s("player1��q %d   player2��q %d   player3��q %d\n", play1.HP, play2.HP, play3.HP);
		}
		else
		{
			printf_s("���߹L��");
		}
	}

	//�D�C���j��
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//����1~15���ü�
	return 0;
}
