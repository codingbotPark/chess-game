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
			//fp는 어떤파일에 어떤 형식으로, 어떤 형식으로 받을지
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