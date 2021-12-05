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

	//test
	chessGrid[3][3] = PON << 4;
	chessGrid[4][4] = BIS << 4;
	chessGrid[5][5] = ROO << 4;
	chessGrid[6][6] = QUE << 4;
	chessGrid[3][4] = KIN << 4;
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


void isBisLoop(int x, int y, char flag, bool color)
{
	// flag = ���� , 0 = �»�, 1 = ���, 2 = ����, 3 = ����

	// ����� ��, ����� ��, ���� ��, �Ʊ��� ��
	if (flag == 0)
	{
		x--;
		y++;
		
	}
	else if (flag == 1)
	{
		x++;
		y++;
	}
	else if (flag == 2)
	{
		x--;
		y--;

	}
	else
	{
		x++;
		y--;
	}

	//����� ��
	if (chessGrid[x][y] == VOI)
	{
		canGoGrid[x][y] = 1;
		isBisLoop(x, y, flag, color);
	}
	//���� ��, �Ʊ��� ��
	else if (chessGrid[x][y] == END || BOOLCOLOR(chessGrid[x][y]) == color)
	{

	}
	// ����� ��
	else if (!(BOOLCOLOR(chessGrid[x][y]) == color))
	{
		canGoGrid[x][y] = 1;
	}
}

void isBisCanGo(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		isBisLoop(x, y, i, BOOLCOLOR(chessGrid[x][y]));
	}

	//int i, j;
	//bool colorBlack = BOOLCOLOR(chessGrid[x][y]);
	//if (colorBlack)//�ʷ�
	//{
	//	i = 0;
	//	j = 0;
	//	//++�ϴ� while��
	//	while (1)
	//	{
	//		i++;
	//		j++;
	//		//if������ �������, �������, ��������
	//		if (!(BOOLCOLOR(chessGrid[x + i -1][y + j-1])) && chessGrid[x+i][y+j] != VOI && chessGrid[x - 1][y - 1] != END)
	//		{
	//			canGoGrid[x + i][y + j] = 1;
	//		}
	//	}
	//	i = 0;
	//	j = 0;
	//	while(1)
	//	{
	//		i++;
	//	}
	//	if (!(BOOLCOLOR(chessGrid[x + 1][y - 1])) && chessGrid[x + 1][y - 1] != VOI && chessGrid[x + 1][y - 1] != END)
	//		canGoGrid[x + 1][y - 1] = 1;
	//	if (chessGrid[x][y - 1] == VOI)
	//	{
	//		canGoGrid[x][y - 1] = 1;
	//		if (y == 7 && chessGrid[x][y - 2] == VOI)
	//		{
	//			canGoGrid[x][y - 2] = 1;
	//		}
	//	}
	//}
	//else
	//{
	//}
}

void isRooLoop(int x, int y, char flag, bool color)
{
	// flag 0 = ��, 1 = ������, 2 = �Ʒ�, 3 = ����
	if (flag == 0)
	{
		y++;
	}
	else if (flag == 1)
	{
		x++;
	}
	else if (flag == 2)
	{
		y--;
	}
	else
	{
		x--;
	}

	// ����� ��
	if (chessGrid[x][y] == VOI)
	{
		canGoGrid[x][y] = 1;
		isRooLoop(x, y, flag, color);
	}
	// ���� ��, 
	else if (chessGrid[x][y] == END || BOOLCOLOR(chessGrid[x][y]) == color)
	{

	}
	// ����� ��
	else if (!BOOLCOLOR(chessGrid[x][y] == color))
	{
		canGoGrid[x][y] = 1;
	}
	
}

void isRooCanGo(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		isRooLoop(x, y, i, BOOLCOLOR(chessGrid[x][y]));
	}
}

//��
void isQueCanGo(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		isRooLoop(x, y, i, BOOLCOLOR(chessGrid[x][y]));
		isBisLoop(x, y, i, BOOLCOLOR(chessGrid[x][y]));
	}
}

void isKniLoop(int x, int y, char flag, bool color)
{
	// flag 0 = ��, 1 = ������, 2 = �Ʒ�, 3 = ����
	// 0 ~ 3 = 2ĭ ���� �� �� �������� ���� ��, 4�̻��� �� �������� ����
	if (flag == 0)
	{
		y += 2;
		x += 1;
	}
	else if (flag == 1)
	{
		x += 2;
		y -= 1;
	}
	else if (flag == 2)
	{
		y -= 2;
		x -= 1;
	}
	else if (flag == 3)
	{
		x -= 2;
		y += 1;
	}
	else if (flag == 4) 
	{
		y += 2;
		x -= 1;
	}
	else if (flag == 5) 
	{
		x += 2;
		y += 1;
	}
	else if (flag == 6) 
	{
		y -= 2;
		x += 1;
	}
	else {
		x -= 2;
		y -= 1;
	}

	// ����� ��
	if (chessGrid[x][y] == VOI)
	{
		canGoGrid[x][y] = 1;
	}
	// ���� ��, 
	else if (chessGrid[x][y] == END || BOOLCOLOR(chessGrid[x][y]) == color)
	{

	}
	// ����� ��
	else if (!BOOLCOLOR(chessGrid[x][y] == color))
	{
		canGoGrid[x][y] = 1;
	}
}

////����Ʈ
void isKniCanGo(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		isKniLoop(x, y, i, BOOLCOLOR(chessGrid[x][y]));
	}
}

void isKinLoop(int x, int y, char flag, bool color)
{
	if (flag == 0)
	{
		y += 1;
	}
	else if (flag == 1)
	{
		x += 1;
		y += 1;
	}
	else if (flag == 2)
	{
		x += 1;
	}
	else if (flag == 3)
	{
		x += 1;
		y -= 1;
	}
	else if (flag == 4)
	{
		y -= 1;
	}
	else if (flag == 5)
	{
		y -= 1;
		x -= 1;
	}
	else if (flag == 6)
	{
		x -= 1;
	}
	else if (flag == 7)
	{
		x -= 1;
		y += 1;
	}
	else
	{

	}

	// ����� ��
	if (chessGrid[x][y] == VOI)
	{
		canGoGrid[x][y] = 1;
	}
	// ���� ��, 
	else if (chessGrid[x][y] == END || BOOLCOLOR(chessGrid[x][y]) == color)
	{

	}
	// ����� ��
	else if (!BOOLCOLOR(chessGrid[x][y] == color))
	{
		canGoGrid[x][y] = 1;
	}

}

void isKinCanGo(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		isKinLoop(x, y, i, BOOLCOLOR(chessGrid[x][y]));
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

	case BIS:
	case BIS << 4: isBisCanGo(x, y); break;
	
	case ROO:
	case ROO << 4: isRooCanGo(x, y); break;

	case QUE:
	case QUE << 4: isQueCanGo(x, y); break;

	case KNI:
	case KNI << 4: isKniCanGo(x,y); break;

	case KIN:
	case KIN << 4: isKinCanGo(x, y); break;
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