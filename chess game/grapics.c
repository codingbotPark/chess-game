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

void drawCharacter(int x, int y, char color, int(*input)[14]) 
{
	x = RETX(x);
	y = RETY(y);
	//컴퓨터의 2차원 배열과
	//우리가 생각하는 체스판의
	//인덱스가 다르기 때문에
	//RETX, RETY를 사용해 해석
	setcolor(color);
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (input[i][j])
			{
				gotoxy(x + j * 2, y + i);
				printf(DOT);
			}
		}
	}
}
