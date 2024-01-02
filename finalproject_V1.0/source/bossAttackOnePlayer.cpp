#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bossAttackOnePlayer(player& p) {
	// BOSS 對某一玩家進行攻擊
	int damage = randomAttackDamage(); // 計算傷害
	p.HP -= damage;
	printf("BOSS 攻?造成 %d ??害！\n", damage);
}