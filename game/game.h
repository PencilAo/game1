#pragma once
#define HANG 3
#define LIE 3

//������
//��ʼ������
void chushihua(char qipan[HANG][LIE], int hang, int lie);

//��ӡ����
void dayin(char qipan[HANG][LIE], int hang, int lie);

//�������
void playermove(char qipan[HANG][LIE], int hang, int lie);

//��������
//�����������(�ҿհ׵ĵط�)
void computermove(char qipan[HANG][LIE], int hang, int lie);

//���Ӯ - '*'
//����Ӯ - '#'
//ƽ�� - 'Q'
//���� - 'C'
char whowin(char qipan[HANG][LIE], int hang, int lie);









