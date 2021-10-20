#include "grapics.h"

void drawVer(int x, int y, int length)//세로선을 만든다
{
	gotoxy(x, y);
	setcolor(BLACK);
	for (int i = 0; i < length; i++)
	{
		printf(DOT);//두칸을 출력
		//가로가 세로에 비해 2칸 더 차지한다
		gotoxy(x, ++y);//x는 고정
	}
}

void drawHor(int x, int y, int length)//가로선을 만든다
{
	gotoxy(x, y);
	setcolor(BLACK);
	for (int i = 0; i < length; i++)
	{
		printf(DOT);
	}
}

void drawCore(int x, int y)
{
	setcolor(RETCOLOR(x, y));
	x = RETX(x);
	y = RETY(y);
	for (int i = 0; i < 14; i++)
	{
		gotoxy(x, y + i);
		printf("                            ");
	}
}

void drawBorder(int x, int y, char color)
{
	x = RETX(x);
	y = RETY(y);
	setcolor(color);
	gotoxy(x, y);
	printf("                            ");
	for (int i = 0; i < 13; i++)
	{
		gotoxy(x, y + i);
		printf(DOT);
		gotoxy(x + 26, y + i);
		printf(DOT);
	}
	gotoxy(x, y + 13);
	printf("                            ");
}

