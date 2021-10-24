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