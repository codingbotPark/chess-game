#include "grapics.h"
#include "chess.h"

int main()
{
	//��Ʈ������ = 6
	system("color f0");//�ܼ�â�� ������ �Ͼ������ ����

	setting();
	

	//drawVer(10,10,100);//����
	//drawHor(10, 10, 100);//����

	for (int i = 0; i < 9; i++)//������ ���
	{
		drawHor(134, 10 + (i * 15), 120);
	}
	for (int i = 0; i < 9; i++)//������ ���
	{
		drawVer(134 + (i * 30), 10, 121);
	}

	//ü������ �Ʒ� ��(��, ��) �� ����
	for (int i=1; i <= 8;i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			drawCore(i, j);
		}
	}

	drawBorder(1, 1, BLUE);

	while (1)
	{
		//������ ���� �� ���� ������� �ʵ���
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