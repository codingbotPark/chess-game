#include "grapics.h"
#include <stdio.h>

extern int myCursorX;
extern int myCursorY;

//������ �׸��� txt���Ͽ��� �ҷ��� �����ϴ� �迭
int pon_asset[14][14];
int bisop_asset[14][14];
int king_asset[14][14];
int knight_asset[14][14];
int queen_asset[14][14];
int rook_asset[14][14];

void loadAsset(const char, int(*)[14]);
//�ɸ��� �ϳ��ϳ��� �̸�, ������ġ�� �Է¹޾� ���

//���� ü������ ���¸� �����ϴ� �迭
char chessGrid[10][10];
//������ 8 * 8 ������ �ε��� ���� �ֱ� ���ϰ� 10,10���� �Ѵ�

void initChessgrid();

//grid�� � ü������ ������
#define END -1
#define VOI 0
#define PON 1
#define KNI 2
#define BIS 3
#define ROO 4
#define QUE 5
#define KIN 6

//asset�� �̸��� �޾Ƽ� �ּҸ� ��ȯ�ϴ� �Լ�
int** retCharPtr(int input);
