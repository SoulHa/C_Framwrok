#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameCompany1.h"


/*面向接口工程整体实现流程*/
/*
1.实现甲方接口，所有函数指针全都声明，并且将整个游戏框架搭建
2.乙方实现所有函数
3.乙方与甲方对接
4.运行整个项目
*/

/*编程思路：
1. 抽象游戏中玩家结构体设计
2. 框架接口设计
	2.1. 初始化游戏
	2.2. 核心战斗功能
	2.3. 查看玩家信息
	2.4. 结束游戏
3. 游戏厂商入围
	3.1. 游戏厂商1
	3.2. 游戏厂商2
4.框架接口分文件编写
*/

//初始化游戏 //参数1 人物指针 参数2 玩家姓名
typedef void(*INIT_GAME)(void** player, char* name);
//核心战斗 如果胜利 返回1 失败返回0 参数1 玩家 参数2 副本难度
typedef int(*FIGHT_GAME)(void* player, int gameDiff);
//查看玩家信息
typedef void(*PRINT_GAME)(void* player);
//离开游戏
typedef void(*EXIT_GAME)(void* player);

//甲方功能实现
void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame)
{
	//初始化游戏
	void* player = NULL;
	printf("请输入玩家的姓名：");
	char buf[1024];
	scanf("%s", buf);
	init(&player, buf);
	int diff = -1;
	while (1)
	{
		getchar();
		system("cls");  //清屏
		//战斗
		printf("请选择游戏难度:");
		printf("1. 简单");
		printf("2. 中等");
		printf("3. 困难");
		scanf("%d", &diff);
		getchar();
		int ret = fight(player, diff);
		if (ret == 0)
		{
			printf("游戏失败\n");
			break;
		}
		else
		{
			printf("恭喜胜利\n");
			//查看玩家当前状态
			printf("玩家当前状态为：\n");
			printfGame(player);
		}
	}
	//退出程序
	exitGame(player);
}
int main() 
{
	srand((unsigned int)time(NULL));
	//playGame();
	playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_GAME_COMPANY1, EXIT_GAME_COMPANY1);

	return 0;
}