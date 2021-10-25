#define _CRT_SECURE_NO_WARNINGS

//#include "grapics.h"
#include "chess.h"

int main()
{
	//폰트사이즈 = 6
	system("color f0");//콘솔창의 배경색을 하얀색으로 설정

	setting();
	

	//drawVer(10,10,100);//세로
	//drawHor(10, 10, 100);//가로

	for (int i = 0; i < 9; i++)//가로줄 출력
	{
		drawHor(134, 10 + (i * 15), 120);
	}
	for (int i = 0; i < 9; i++)//세로줄 출력
	{
		drawVer(134 + (i * 30), 10, 121);
	}

	//체스판의 아래 색(휜, 검) 을 만듬
	for (int i=1; i <= 8;i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			drawCore(i, j);
		}
	}

	//말들을 로딩하는 코드
	//pon
	FILE* fp = fopen("pon.txt", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", &pon_asset[i][j]);
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
		}
	}
	fclose(fp);
	
	//bisop
	fp = fopen("bisop.txt", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", &bisop_asset[i][j]);
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
		}
	}
	fclose(fp);

	//king
	fp = fopen("king.txt", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", &king_asset[i][j]);
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
		}
	}
	fclose(fp);

	//knight
	fp = fopen("knight.txt", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", &knight_asset[i][j]);
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
		}
	}
	fclose(fp);

	//queen
	fp = fopen("queen.txt", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", &queen_asset[i][j]);
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
		}
	}
	fclose(fp);

	//rook
	fp = fopen("rook.txt", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", &rook_asset[i][j]);
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
		}
	}
	fclose(fp);
	
	//loadAsset("pon.txt", pon_asset);


	initChessgrid();


	//drawCharacter(2, 2, YELLOW, pon_asset);

	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			drawCharacter(j, i, YELLOW, retCharPtr(chessGrid[j][i]));
		}
	}


	drawBorder(1, 1, BLUE);

	while (1)
	{
		//게임이 끝날 때 까지 종료되지 않도록
		if (GetAsyncKeyState(VK_LEFT) && myCursorX > 1)
		{
			drawBorder(myCursorX, myCursorY, RETCOLOR(myCursorX, myCursorY));
			myCursorX--;
			drawBorder(myCursorX, myCursorY, BLUE);
		}
		if (GetAsyncKeyState(VK_DOWN) && myCursorY > 1)
		{
			drawBorder(myCursorX, myCursorY, RETCOLOR(myCursorX, myCursorY));
			myCursorY--;
			drawBorder(myCursorX, myCursorY, BLUE);
		}
		if (GetAsyncKeyState(VK_UP) && myCursorY < 8)
		{
			drawBorder(myCursorX, myCursorY, RETCOLOR(myCursorX, myCursorY));
			myCursorY++;
			drawBorder(myCursorX, myCursorY, BLUE);
		}
		if (GetAsyncKeyState(VK_RIGHT) && myCursorX < 8)
		{
			drawBorder(myCursorX, myCursorY, RETCOLOR(myCursorX, myCursorY));
			myCursorX++;
			drawBorder(myCursorX, myCursorY,BLUE);
		}
		if (GetAsyncKeyState(VK_SPACE))
		{

		}
		Sleep(100);
	}


}