#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>

//������
void game()
{
	char qipan[HANG][LIE] = { 0 };
	//��ʼ������
	char ret;
	chushihua(qipan,HANG,LIE);
	//��ӡ����
	dayin(qipan, HANG, LIE);
	while(1)
	{
		playermove(qipan, HANG, LIE);
		//�ж���Ӯ
		ret = whowin(qipan, HANG, LIE);
		if (ret != 'C')//����C��ʾ����
		{
			break;
		}
		dayin(qipan, HANG, LIE);
		computermove(qipan, HANG, LIE);
		//�ж���Ӯ
		ret = whowin(qipan, HANG, LIE);
		if (ret != 'C')//����C��ʾ����
		{
			break;
		}
		dayin(qipan, HANG, LIE);
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("��ʼ��Ϸ\n");
			printf("������");
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������\n");
			break;
		}
	} while (input);
	return 0;
}