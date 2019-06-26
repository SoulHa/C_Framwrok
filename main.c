#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameCompany1.h"


/*����ӿڹ�������ʵ������*/
/*
1.ʵ�ּ׷��ӿڣ����к���ָ��ȫ�����������ҽ�������Ϸ��ܴ
2.�ҷ�ʵ�����к���
3.�ҷ���׷��Խ�
4.����������Ŀ
*/

/*���˼·��
1. ������Ϸ����ҽṹ�����
2. ��ܽӿ����
	2.1. ��ʼ����Ϸ
	2.2. ����ս������
	2.3. �鿴�����Ϣ
	2.4. ������Ϸ
3. ��Ϸ������Χ
	3.1. ��Ϸ����1
	3.2. ��Ϸ����2
4.��ܽӿڷ��ļ���д
*/

//��ʼ����Ϸ //����1 ����ָ�� ����2 �������
typedef void(*INIT_GAME)(void** player, char* name);
//����ս�� ���ʤ�� ����1 ʧ�ܷ���0 ����1 ��� ����2 �����Ѷ�
typedef int(*FIGHT_GAME)(void* player, int gameDiff);
//�鿴�����Ϣ
typedef void(*PRINT_GAME)(void* player);
//�뿪��Ϸ
typedef void(*EXIT_GAME)(void* player);

//�׷�����ʵ��
void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame)
{
	//��ʼ����Ϸ
	void* player = NULL;
	printf("��������ҵ�������");
	char buf[1024];
	scanf("%s", buf);
	init(&player, buf);
	int diff = -1;
	while (1)
	{
		getchar();
		system("cls");  //����
		//ս��
		printf("��ѡ����Ϸ�Ѷ�:");
		printf("1. ��");
		printf("2. �е�");
		printf("3. ����");
		scanf("%d", &diff);
		getchar();
		int ret = fight(player, diff);
		if (ret == 0)
		{
			printf("��Ϸʧ��\n");
			break;
		}
		else
		{
			printf("��ϲʤ��\n");
			//�鿴��ҵ�ǰ״̬
			printf("��ҵ�ǰ״̬Ϊ��\n");
			printfGame(player);
		}
	}
	//�˳�����
	exitGame(player);
}
int main() 
{
	srand((unsigned int)time(NULL));
	//playGame();
	playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_GAME_COMPANY1, EXIT_GAME_COMPANY1);

	return 0;
}