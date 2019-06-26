#include "gameCompany1.h"
#include <string.h>

void INIT_GAME_COMPANY1(void** player, char* name)
{
	struct Player* player1 = malloc(sizeof(struct Player));
	if (NULL == player1)
	{
		return;
	}
	*player = player1;
	strcpy(((struct Player*)(player))->name, name);
}

int FIGHT_GAME_COMPANY1(void* player, int gameDiff)
{
	struct Player* player1 = player;
	int addExp = 0;
	switch (gameDiff)
	{
	case 1:
		addExp = isWin(90, 1);
		break;
	case 2:
		addExp = isWin(50, 2);
		break;
	case 3:
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}
	player1->exp += addExp;
	player1->level = player1->exp / 10;
	if (addExp == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

void PRINT_GAME_COMPANY1(void* player)
{
	struct Player* player1 = player;
	printf("玩家<%s>-----当前等级<%d>-----当前经验<%d>\n", player1->name, player1->level, player1->exp);
}

void EXIT_GAME_COMPANY1(void* player)
{
	if (player == NULL)
	{
		return;
	}
	free(player);
	player = NULL;
}

int isWin(int winRate, int diff)
{
	int random = rand() % 100 + 1;
	if (random <= winRate)
	{
		return diff * 10;
	}
	else
	{
		return 0;
	}
}
