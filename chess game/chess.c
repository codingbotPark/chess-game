#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4047)
#include "chess.h"
int myCursorX = 1;
int myCursorY = 1;

void loadAsset(const char fileName, int(*input)[14])
{
	FILE* fp = fopen("fileName", "r");
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fscanf(fp, "%d", input[i][j]);
			//fp�� ����Ͽ� � ��������, � �������� ������
		}
	}
	fclose(fp);
}

void initChessgrid()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i == 0 || i == 9 || j == 0 || j == 9)
				chessGrid[i][j] = END;
	for (int i = 1; i <= 8; i++)
		chessGrid[i][2] = PON;
	for (int i = 1; i <= 8; i++)
		chessGrid[i][7] = PON << 4;

	chessGrid[1][1] = ROO;
	chessGrid[8][1] = ROO;
	chessGrid[1][8] = ROO << 4;
	chessGrid[8][8] = ROO << 4;

	chessGrid[2][1] = KNI;
	chessGrid[7][1] = KNI;
	chessGrid[2][8] = KNI << 4;
	chessGrid[7][8] = KNI << 4;

	chessGrid[3][1] = BIS;
	chessGrid[6][1] = BIS;
	chessGrid[3][8] = BIS << 4;
	chessGrid[6][8] = BIS << 4;

	chessGrid[4][1] = QUE;
	chessGrid[4][8] = QUE << 4;

	chessGrid[5][1] = KIN;
	chessGrid[5][8] = KIN << 4;

	chessGrid[3][3] = PON << 4;
}


int** retCharPtr(int input)
{
	switch (input)
	{
	case PON:
	case PON << 4:
		return pon_asset;
	case KNI:
	case KNI << 4:
		return knight_asset;
	case BIS:
	case BIS << 4:
		return bisop_asset;
	case ROO:
	case ROO << 4:
		return rook_asset;
	case QUE:
	case QUE << 4:
		return queen_asset;
	case KIN:
	case KIN << 4:
		return king_asset;
	default:
		return pon_asset;
	}
}


void isPonCanGo(int x, int y)
{
	bool colorBlack = BOOLCOLOR(chessGrid[x][y]);
	if (colorBlack)
	{
		//��� ���� �밢�� �� ĭ�� ���� �� + �밢�� �� ĭ�� ���� �ƴ� �� = ���� �밢������ �� �� �ִ�
		if (!(BOOLCOLOR(chessGrid[x - 1][y - 1])) && chessGrid[x - 1][y - 1] != VOI && chessGrid[x - 1][y - 1] != END)
			canGoGrid[x - 1][y - 1] = 1;
		if (!(BOOLCOLOR(chessGrid[x + 1][y - 1])) && chessGrid[x + 1][y - 1] != VOI && chessGrid[x + 1][y - 1] != END)
			canGoGrid[x + 1][y - 1] = 1;
		//���������� y--
		//�Ϲ������� �� ĭ ������ ��
		if (chessGrid[x][y - 1] == VOI)
		{
			canGoGrid[x][y - 1] = 1;
			if (y == 7 && chessGrid[x][y - 2] == VOI)
			{
				canGoGrid[x][y - 2] = 1;
			}
		}
	}
	else
	{
		if (BOOLCOLOR(chessGrid[x - 1][y + 1]) && chessGrid[x - 1][y + 1] != VOI && chessGrid[x - 1][y + 1] != END)
			canGoGrid[x - 1][y + 1] = 1;
		if (BOOLCOLOR(chessGrid[x + 1][y + 1]) && chessGrid[x + 1][y + 1] != VOI && chessGrid[x + 1][y + 1] != END)
			canGoGrid[x + 1][y + 1] = 1;

		if (chessGrid[x][y + 1] == VOI)
		{
			canGoGrid[x][y + 1] = 1;
			if (y == 2 && chessGrid[x][y + 2] == VOI)
			{
				canGoGrid[x][y + 2] = 1;
			}
		}
	}
}




void click()
{
	//���� �� ����� ��
	if (clickflag == 0)
	{
		//���� x, y�� ��ġ�� �̵�
		whereclicked_x = myCursorX;
		whereclicked_y = myCursorY;
		//���� �����
		clickflag = 1;
		isCanGo(whereclicked_x, whereclicked_y);
	}
	else
	{
		//���� ����� ��
		clickflag = 0;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (canGoGrid[i][j] == 1)
				{
					//1�� �� ���� isCanGo~ �� ���� �׷��� ���� �ִ� ���̰�
					//�ٽ��� �� drawCore�� ���� ���� ���� �׷��� ���� ������� �ٲ۴�
					drawCore(i, j);

					//dot�� ����ϰ� ��븻�� ��Ʈ�� ���� ������� ������ ���
					if (chessGrid[i][j] != VOI)
					{
						drawCharacter(i, j, charColor(chessGrid[i][j]), retCharPtr(chessGrid[i][j]));
					}		
				}
			}
		}
		//���� Ŀ���� drawCore�� ���� �������� ���� �ٽ� �׸�
		drawBorder(myCursorX,myCursorY,BLUE);

	}
}

void isCanGo(x, y) 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			canGoGrid[i][j] = 0;
		}
	}
	int whatChar = chessGrid[x][y];
	switch (whatChar)
	{
	//ü������ x,y�� �ִ� ���� ��,
	//�� �� �ִ� ���� ����� �Լ� ����
	case PON:
	case PON << 4: isPonCanGo(x, y); break;
	
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (canGoGrid[i][j] == 1)
			{
				drawCharacter(i, j, PURPLE,dot_asset);
			}
		}
	}
}