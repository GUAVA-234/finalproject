#include<stdio.h>
int boss;
int game(int difficulty)
{	
	switch (difficulty)
	{
	case 1:
		boss = 300;
			break;
	case 2:
		boss = 500;
			break;
	case 3: 
		boss = 1000;
		break;
	}
	return boss;
}