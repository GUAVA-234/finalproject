#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
int randomAttackDamage() {
	// 隨機生成攻擊傷害
	return rand() % 20 + 10; // 傷害在10到30之間
}