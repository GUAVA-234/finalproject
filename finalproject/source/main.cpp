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

int main(void)
{	
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
	while (boss != 0 && play1.HP != 0 && play2.HP != 0 && play3.HP != 0)
	{
		printf_s("BOSS��q %d\n", boss);
		
		//play2.HP = 0;
	//	printf_s("%d\n", play2.HP);
		
	}
	//�D�C���j��
	/*int a = 0;
	scanf_s("%d", &a);
	timerand(a);*/
	//����1~15���ü�
	return 0;
}
