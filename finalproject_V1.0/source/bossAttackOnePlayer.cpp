#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bossAttackOnePlayer(player& p) {
	// BOSS ��Y�@���a�i�����
	int damage = randomAttackDamage(); // �p��ˮ`
	p.HP -= damage;
	printf("BOSS ��?�y�� %d ??�`�I\n", damage);
}