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
};	
	player play1,play2;
int main(void)
{	
	while(difficulty != 1 && difficulty !=2 && difficulty!=3)
	{ 
	printf_s("�п������\n");
	printf_s("(1)²��(2)���q(3)�x��\n");
	scanf_s("%d", &difficulty);
	}
	int boss = game(difficulty);
	//BOSS��q
	/*while (boss!=0&&play.HP!=0)
	{
		
	}*/
	//�D�C���j��
	timerand();
	//����1~15���ü�
	return 0;
}
