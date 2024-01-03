#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bossMaxHealth;// Boss �̤j��q

typedef struct
{
	int health;// ���a��q
	int attack;// ���a�����O
	int heal;  // ���a��_�q
	int action_interval;// ���a��ʶ��j
	int next_action_turn;// ���a�U����ʦ^�X
} Player;

typedef struct
{
	int health;
} Boss;
// ��l�ƪ��a�ݩ�
void initializePlayer(Player *player, int health, int attack, int heal, int action_interval)
{
	player->health = health;
	player->attack = attack;
	player->heal = heal;
	player->action_interval = action_interval;
	player->next_action_turn = 1;
}
// ��l�� Boss �ݩ�
void initializeBoss(Boss *boss, int health)
{
	boss->health = health;
}

int getRandom(int min, int max)
{
	return min + rand() % (max - min + 1);// ���o���w�d�򤺪��H����
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
			printf("\033[37m�i\033[37m");
		}
		else
		{
			printf(" ");
		}
	}
	printf("] %d/%d\n", currentHealth, maxHealth);
}
// ��ܪ��a�� Boss ����q���]����^
void displayHealthBarRED(int currentHealth, int maxHealth)
{
	int barWidth = 20;
	int healthUnits = (currentHealth * barWidth) / maxHealth;

	printf("[");
	for (int i = 0; i < barWidth; i++)
	{
		if (i < healthUnits)
		{
			printf("\033[31m�i\033[37m");// ������ܦ�q
		}
		else
		{
			printf(" ");
		}
	}
	printf("] %d/%d\n", currentHealth, maxHealth); //��ܷ�e��q�γ̤j��q
}
// ��ܪ��a����q���]���^
void displayHealthBarGREEN(int currentHealth, int maxHealth)
{
	int barWidth = 20;
	int healthUnits = (currentHealth * barWidth) / maxHealth;

	printf("[");
	for (int i = 0; i < barWidth; i++)
	{
		if (i < healthUnits)
		{
			printf("\033[32m�i\033[37m");// ����ܦ�q
		}
		else
		{
			printf(" ");
		}
	}
	printf("] %d/%d\n", currentHealth, maxHealth);// ��ܷ�e��q�γ̤j��q
}
// ���a��������Ϊv���ʧ@
void performAction(Player *player, Boss *boss, int turn, int number)
{
	if (turn >= player->next_action_turn)
	{
		printf("���a %d ��� (1-����, 2-�v��): ", number);
		int choice;
		scanf("%d", &choice);

		if (choice == 1)
		{
			int damage = getRandom(0, player->attack);
			printf("���a %d ���� %d �I�ˮ`!\n", number, damage);
			boss->health -= damage;
			printf("Boss ��q: ");
			displayHealthBarRED(boss->health, bossMaxHealth);// ��sBoss��q��
			printf("\n");
		}
		else
		{
			int heal = getRandom(0, player->heal);
			printf("���a %d ��_ %d �I�ͩR!\n", number, heal);
			player->health += heal;
			if (player->health > 100) player->health = 100;
			displayHealthBarGREEN(player->health, 100); // ��s���a��q��
			printf("\n");
		}

		player->next_action_turn += player->action_interval;
	}
}
// Boss ��������ʧ@
void bossAction(Player players[], int playerCount)
{

	int target = getRandom(0, playerCount - 1);
	int damage = getRandom(10, 30);
	if (players[target].health != 0)
	{
		printf("BOSS�������a %d �y�� %d �I�ˮ`!\n", target + 1, damage);
		players[target].health -= damage;
		if (players[target].health < 0)
		{
			players[target].health = 0;
		}
		printf("���a %d ��q: ", target + 1);
		displayHealthBarRED(players[target].health, 100); // ��s�Q�������a����q��
	}
	else
	{
		return bossAction(players, playerCount);// �p�G�Q���������a�w���`�A���s��ܥؼЪ��a
	}
}

int main()
{
	srand(time(NULL));

	Player players[3];
	Boss boss;
	int difficulty;
	// �C�����D�����׿��
	printf("   ==========================\n");
	printf("   ��                        ��\n");
	printf("   ��        ���إ���        ��\n");
	printf("   ��                        ��\n");
	printf("   ==========================\n");


	printf("�п������ (1-²��, 2-���q, 3-�x��): ");
	scanf("%d", &difficulty);
	printf("\n\n");
	bossMaxHealth = (difficulty == 1) ? 300 : (difficulty == 2) ? 500 : 1000;
	initializeBoss(&boss, bossMaxHealth);// ��l�� Boss ��q

	initializePlayer(&players[0], 100, 10, 20, 1); // Player A
	initializePlayer(&players[1], 100, 20, 40, 2); // Player B
	initializePlayer(&players[2], 100, 30, 60, 3); // Player C

	int turn = 1;
	while (boss.health > 0)// �C���i�椤
	{
		printf("�^�X %d\n", turn);
		printf("���a 1 ��q: ");
		displayHealthBar(players[0].health, 100);
		printf("���a 2 ��q: ");
		displayHealthBar(players[1].health, 100);
		printf("���a 3 ��q: ");
		displayHealthBar(players[2].health, 100);
		printf("Boss ��q:   ");
		displayHealthBar(boss.health, bossMaxHealth);

		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			if (players[i].health > 0)
			{
				performAction(&players[i], &boss, turn, i + 1);
				if (boss.health <= 0)
				{
					printf("BOSS���F ���a�ӧQ�I\n");
					return 0;
				}
			}
		}

		bossAction(players, 3);
		for (int i = 0; i < 3; i++)
		{
			if (players[i].health <= 0)
			{
				printf("���a %d ���F!\n", i + 1);
			}
		}

		int allPlayersDead = 1;
		for (int i = 0; i < 3; i++)
		{
			if (players[i].health > 0)
			{
				allPlayersDead = 0;
				break;
			}
		}

		if (allPlayersDead)
		{
			printf("%d\n", allPlayersDead);
			printf("�Ҧ����a�����`�F! BOSSĹ�F!\n");
			return 0;
		}

		turn++;

		printf("\n");
		system("pause");
		system("cls");
	}


	return 0;
}