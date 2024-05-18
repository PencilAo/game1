#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>

//三子棋
void game()
{
	char qipan[HANG][LIE] = { 0 };
	//初始化棋盘
	char ret;
	chushihua(qipan,HANG,LIE);
	//打印数据
	dayin(qipan, HANG, LIE);
	while(1)
	{
		playermove(qipan, HANG, LIE);
		//判断输赢
		ret = whowin(qipan, HANG, LIE);
		if (ret != 'C')//返回C表示继续
		{
			break;
		}
		dayin(qipan, HANG, LIE);
		computermove(qipan, HANG, LIE);
		//判断输赢
		ret = whowin(qipan, HANG, LIE);
		if (ret != 'C')//返回C表示继续
		{
			break;
		}
		dayin(qipan, HANG, LIE);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	dayin(qipan, HANG, LIE);
}
void menu()
{
	printf("****************************\n");
	printf("***********1.play***********\n");
	printf("***********0.exit***********\n");
	printf("****************************\n");
}
int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("开始游戏\n");
			printf("三子棋");
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("重新输入\n");
			break;
		}
	} while (input);
	return 0;
}