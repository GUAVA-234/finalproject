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
	while(difficulty != 1 && difficulty !=2 && difficulty!=3)
	{ 
	printf_s("�п������\n");
	printf_s("(1)²��(2)���q(3)�x��\n");
	scanf_s("%d", &difficulty);
	}

	int boss = game(difficulty);
	//BOSS��q
	printf_s("BOSS��q %d\n", boss);
	while (boss > 0 && (play1.HP > 0 || play2.HP > 0 || play3.HP > 0))
	{
		
		//play2.HP = 0;
	//	printf_s("%d\n", play2.HP);
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
		
	}

	//�D�C���j��
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//����1~15���ü�
	return 0;
}
