#pragma once
#define HANG 3
#define LIE 3

//三子棋
//初始化棋盘
void chushihua(char qipan[HANG][LIE], int hang, int lie);

//打印数据
void dayin(char qipan[HANG][LIE], int hang, int lie);

//玩家下棋
void playermove(char qipan[HANG][LIE], int hang, int lie);

//电脑下棋
//电脑随机下棋(找空白的地方)
void computermove(char qipan[HANG][LIE], int hang, int lie);

//玩家赢 - '*'
//电脑赢 - '#'
//平局 - 'Q'
//继续 - 'C'
char whowin(char qipan[HANG][LIE], int hang, int lie);









