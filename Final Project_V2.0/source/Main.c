#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bossMaxHealth;

typedef struct
{
	int health;
	int attack;
	int heal;
	int action_interval;
	int next_action_turn;
} Player;

typedef struct 
{
	int health;
} Boss;

void initializePlayer(Player *player, int health, int attack, int heal, int action_interval) 
{
	player->health = health;
	player->attack = attack;
	player->heal = heal;
	player->action_interval = action_interval;
	player->next_action_turn = 1;
}

void initializeBoss(Boss *boss, int health)
{
	boss->health = health;
}

int getRandom(int min, int max) 
{
	return min + rand() % (max - min + 1);
}

void displayHealthBar(int currentHealth, int maxHealth)
{
	int barWidth = 20;
	int healthUnits = (currentHealth * barWidth) / maxHealth;

	printf("[");
	for (int i = 0; i < barWidth; i++) 
	{
		if (i < healthUnits) 
		{
			printf("█");
		}
		else 
		{
			printf(" ");
		}
	}
	printf("] %d/%d\n", currentHealth, maxHealth);
}

void performAction(Player *player, Boss *boss, int turn,int number)
{
	if (turn >= player->next_action_turn) 
	{
		printf("玩家行動 (1-攻擊, 2-治療): ");
		int choice;
		scanf("%d", &choice);

		if (choice == 1)
		{
			int damage = getRandom(0, player->attack);
			printf("玩家 %d 攻擊 %d 點傷害!\n",number, damage);
			boss->health -= damage;
			printf("Boss 血量: ");
			displayHealthBar(boss->health, bossMaxHealth);// 更新Boss血量條
			printf("\n");
		}
		else
		{
			int heal = getRandom(0, player->heal);
			printf("玩家 %d 恢復 %d 點生命!\n",number ,heal);
			player->health += heal;
			if (player->health > 100) player->health = 100;
			displayHealthBar(player->health, 100); // 更新玩家血量條
			printf("\n");
		}

		player->next_action_turn += player->action_interval;
	}
}

void bossAction(Player players[], int playerCount, Boss *boss) 
{
	int target = getRandom(0, playerCount - 1);
	int damage = getRandom(10, 30);
	printf("BOSS攻擊玩家 %d 造成 %d 點傷害!\n", target + 1, damage);
	players[target].health -= damage;
	printf("玩家 %d 血量: ", target + 1);
	displayHealthBar(players[target].health, 100); // 更新被攻擊玩家的血量條
}

int main() 
{
	srand(time(NULL));

	Player players[3];
	Boss boss;
	int difficulty;

	printf("   ==========================\n");
	printf("   ∥                        ∥\n");
	printf("   ∥        陽壽打怪        ∥\n");
	printf("   ∥                        ∥\n");
	printf("   ==========================\n");

	
	printf("請選擇難度 (1-簡單, 2-普通, 3-困難): ");
	scanf("%d", &difficulty);
	bossMaxHealth = (difficulty == 1) ? 300 : (difficulty == 2) ? 500 : 1000;
	initializeBoss(&boss, bossMaxHealth);

	initializePlayer(&players[0], 100, 10, 20, 1); // Player A
	initializePlayer(&players[1], 100, 20, 40, 2); // Player B
	initializePlayer(&players[2], 100, 30, 60, 3); // Player C

	int turn = 1;
	while (boss.health > 0) {
		printf("\n\n回合 %d\n", turn);
		printf("玩家 1 血量: ");
		displayHealthBar(players[0].health, 100);
		printf("玩家 2 血量: ");
		displayHealthBar(players[1].health, 100);
		printf("玩家 3 血量: ");
		displayHealthBar(players[2].health, 100);
		printf("\n");

		for (int i = 0; i < 3; i++) {
			if (players[i].health > 0) {
				performAction(&players[i], &boss, turn, i+1);
				if (boss.health <= 0) {
					printf("所有玩家死亡。Boss勝利！\n");
					return 0;
				}
			}
		}

		bossAction(players, 3, &boss);
		for (int i = 0; i < 3; i++) {
			if (players[i].health <= 0) {
				printf("玩家 %d 死了!\n", i + 1);
			}
		}

		int allPlayersDead = 1;
		for (int i = 0; i < 3; i++) {
			if (players[i].health > 0) {
				allPlayersDead = 0;
				break;
			}
		}

		if (allPlayersDead) {
			printf("所有玩家都死亡了! BOSS贏了!\n");
			return 0;
		}

		turn++;
	}

	return 0;
}
