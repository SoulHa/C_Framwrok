#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//玩家结构体
struct Player
{
	char name[64];
	int level;
	int exp;
};

//初始化游戏 //参数1 人物指针 参数2 玩家姓名
 void INIT_GAME_COMPANY1(void** player, char* name);
//核心战斗 如果胜利 返回1 失败返回0 参数1 玩家 参数2 副本难度
int FIGHT_GAME_COMPANY1(void* player, int gameDiff);
//查看玩家信息
 void PRINT_GAME_COMPANY1(void* player);
//离开游戏
 void EXIT_GAME_COMPANY1(void* player);

 //判断玩家是否胜利
 int isWin(int winRate, int diff);