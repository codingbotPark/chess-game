#include "grapics.h"

void drawVer(int x, int y, int length)//���μ��� �����
{
	gotoxy(x, y);
	setcolor(BLACK);
	for (int i = 0; i < length; i++)
	{
		printf(DOT);//��ĭ�� ���
		//���ΰ� ���ο� ���� 2ĭ �� �����Ѵ�
		gotoxy(x, ++y);//x�� ����
	}
}

void drawHor(int x, int y, int length)//���μ��� �����
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
	//��ǻ���� 2���� �迭��
	//�츮�� �����ϴ� ü������
	//�ε����� �ٸ��� ������
	//RETX, RETY�� ����� �ؼ�
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
