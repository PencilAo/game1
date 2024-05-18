#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//������
void chushihua(char qipan[HANG][LIE], int hang, int lie)
{
	int i, j;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			qipan[i][j] = ' ';
		}
	}//�����̳�ʼ������ÿ��λ�÷Ÿ��ո�
}
//��һ���汾 ����
//void dayin(char qipan[HANG][LIE], int hang, int lie)
//{
//	int i;
//	for (i = 0; i < hang; i++)
//	{
//		//��ӡ����
//		printf("| %c | %c | %c |\n", qipan[i][0], qipan[i][1], qipan[i][2]);
//		if(i<hang-1)
//		{
//			printf("|---|---|---|\n");
//			}
//	}
//}
//�ڶ����汾 ��
void dayin(char qipan[HANG][LIE], int hang, int lie)
{
	int i;
	for (i = 0; i < hang; i++)
	{
		int j;
		for (j = 0; j < lie; j++)
		{
			//��ӡ����
			printf(" %c ", qipan[i][j]);
			if (j < lie - 1 )
			{
				//��ӡ��ֱ�ָ��У����һ�в���ӡ
				printf("|");
			}
		}
		printf("\n");
		//printf("| %c | %c | %c |\n");
		// 
		// 
		//��ӡˮƽ�ָ��У����һ�в���ӡ
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
	printf("����������");
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
				printf("���걻ռ��,��������\n");
				break;
			}
		}
		else
		{
			printf("��������\n");
			break;
		}
	}
}
void computermove(char qipan[HANG][LIE], int hang, int lie)
{
	printf("��������\n");
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
//���˷���1
//��������0
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
	//�ж���
	int i,j,m;
	for (i = 0; i < hang; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
	}
	//�ж���
	for (j = 0; j < lie; j++)
	{
		if (qipan[0][j] == qipan[1][j] && qipan[1][j] == qipan[2][j] && qipan[0][j] != ' ')
			return qipan[0][j];
	}
	//�ж϶Խ���
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[0][0] != ' ')
	{
		return qipan[0][0];
	}
	if (qipan[0][2] == qipan[1][1] && qipan[1][1] == qipan[2][0] && qipan[0][2] != ' ')
	{
		return qipan[0][2];
	}
	//������⻹û��Ӯ�����������Ѿ����ˣ����ƽ��
	if (isfull(qipan, hang, lie))
	{
		return 'Q';
	}
	return 'C';
}





