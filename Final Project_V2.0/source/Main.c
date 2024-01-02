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
			printf("�i");
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
		printf("���a��� (1-����, 2-�v��): ");
		int choice;
		scanf("%d", &choice);

		if (choice == 1)
		{
			int damage = getRandom(0, player->attack);
			printf("���a %d ���� %d �I�ˮ`!\n",number, damage);
			boss->health -= damage;
			printf("Boss ��q: ");
			displayHealthBar(boss->health, bossMaxHealth);// ��sBoss��q��
			printf("\n");
		}
		else
		{
			int heal = getRandom(0, player->heal);
			printf("���a %d ��_ %d �I�ͩR!\n",number ,heal);
			player->health += heal;
			if (player->health > 100) player->health = 100;
			displayHealthBar(player->health, 100); // ��s���a��q��
			printf("\n");
		}

		player->next_action_turn += player->action_interval;
	}
}

void bossAction(Player players[], int playerCount, Boss *boss) 
{
	int target = getRandom(0, playerCount - 1);
	int damage = getRandom(10, 30);
	printf("BOSS�������a %d �y�� %d �I�ˮ`!\n", target + 1, damage);
	players[target].health -= damage;
	printf("���a %d ��q: ", target + 1);
	displayHealthBar(players[target].health, 100); // ��s�Q�������a����q��
}

int main() 
{
	srand(time(NULL));

	Player players[3];
	Boss boss;
	int difficulty;

	printf("   ==========================\n");
	printf("   ��                        ��\n");
	printf("   ��        ���إ���        ��\n");
	printf("   ��                        ��\n");
	printf("   ==========================\n");

	
	printf("�п������ (1-²��, 2-���q, 3-�x��): ");
	scanf("%d", &difficulty);
	bossMaxHealth = (difficulty == 1) ? 300 : (difficulty == 2) ? 500 : 1000;
	initializeBoss(&boss, bossMaxHealth);

	initializePlayer(&players[0], 100, 10, 20, 1); // Player A
	initializePlayer(&players[1], 100, 20, 40, 2); // Player B
	initializePlayer(&players[2], 100, 30, 60, 3); // Player C

	int turn = 1;
	while (boss.health > 0) {
		printf("\n\n�^�X %d\n", turn);
		printf("���a 1 ��q: ");
		displayHealthBar(players[0].health, 100);
		printf("���a 2 ��q: ");
		displayHealthBar(players[1].health, 100);
		printf("���a 3 ��q: ");
		displayHealthBar(players[2].health, 100);
		printf("\n");

		for (int i = 0; i < 3; i++) {
			if (players[i].health > 0) {
				performAction(&players[i], &boss, turn, i+1);
				if (boss.health <= 0) {
					printf("�Ҧ����a���`�CBoss�ӧQ�I\n");
					return 0;
				}
			}
		}

		bossAction(players, 3, &boss);
		for (int i = 0; i < 3; i++) {
			if (players[i].health <= 0) {
				printf("���a %d ���F!\n", i + 1);
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
			printf("�Ҧ����a�����`�F! BOSSĹ�F!\n");
			return 0;
		}

		turn++;
	}

	return 0;
}
