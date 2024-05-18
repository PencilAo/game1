#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//三子棋
void chushihua(char qipan[HANG][LIE], int hang, int lie)
{
	int i, j;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			qipan[i][j] = ' ';
		}
	}//将棋盘初始化，即每个位置放个空格
}
//第一个版本 不好
//void dayin(char qipan[HANG][LIE], int hang, int lie)
//{
//	int i;
//	for (i = 0; i < hang; i++)
//	{
//		//打印数据
//		printf("| %c | %c | %c |\n", qipan[i][0], qipan[i][1], qipan[i][2]);
//		if(i<hang-1)
//		{
//			printf("|---|---|---|\n");
//			}
//	}
//}
//第二个版本 好
void dayin(char qipan[HANG][LIE], int hang, int lie)
{
	int i;
	for (i = 0; i < hang; i++)
	{
		int j;
		for (j = 0; j < lie; j++)
		{
			//打印数据
			printf(" %c ", qipan[i][j]);
			if (j < lie - 1 )
			{
				//打印竖直分割列，最后一列不打印
				printf("|");
			}
		}
		printf("\n");
		//printf("| %c | %c | %c |\n");
		// 
		// 
		//打印水平分割行，最后一列不打印
		// 
		// 
		//printf("|---|---|---|\n");
		if (i < hang - 1)
		{ 
			for (j = 0; j < lie; j++)
			{
				printf("---");
				if (j < lie - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void playermove(char qipan[HANG][LIE], int hang, int lie)
{
	int x, y;
	printf("请输入坐标");
	scanf("%d %d", &x, &y);
	while (1)
	{
		if (x >= 0 && x <= hang && y >= 0 && y <= lie)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用,不能下棋\n");
				break;
			}
		}
		else
		{
			printf("重新输入\n");
			break;
		}
	}
}
void computermove(char qipan[HANG][LIE], int hang, int lie)
{
	printf("电脑下棋\n");
	int x;
	int y;
	while (1)
	{
		x = rand() % hang;//0~hang
		y = rand() % lie;//0~lie
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = '#';
			break;
		}
	}
}
//满了返回1
//不满返回0
int isfull(char qipan[HANG][LIE], int hang, int lie)
{
	int i, j;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char whowin(char qipan[HANG][LIE], int hang, int lie)
{
	//判断行
	int i,j,m;
	for (i = 0; i < hang; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
	}
	//判断列
	for (j = 0; j < lie; j++)
	{
		if (qipan[0][j] == qipan[1][j] && qipan[1][j] == qipan[2][j] && qipan[0][j] != ' ')
			return qipan[0][j];
	}
	//判断对角线
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[0][0] != ' ')
	{
		return qipan[0][0];
	}
	if (qipan[0][2] == qipan[1][1] && qipan[1][1] == qipan[2][0] && qipan[0][2] != ' ')
	{
		return qipan[0][2];
	}
	//如果到这还没人赢，而且棋盘已经满了，则就平局
	if (isfull(qipan, hang, lie))
	{
		return 'Q';
	}
	return 'C';
}





