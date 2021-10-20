#include  "windowconsole.h"

void setting()//기본적인 세팅
{//콘솔창을 세팅
	SetConsoleTitle(TEXT("신나는 체스게임"));
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	system("mode con cols=500 lines=135");//가로를 500 세로를 135로 해서 체스판의 모양을 지킨다
}

void gotoxy(int x, int y)//특정 좌표로 커서이동
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(char color)//색 변경
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color << 4);
}
