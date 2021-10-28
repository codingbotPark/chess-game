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

//���� �̵��� �� �ִ� ���� ���
char canGoGrid[10][10];

//���� x,y ��ǥ�� �޾Ƽ� �� �� �ִ��� ���
void isPonCanGo(int x, int y);


void initChessgrid();

//15�̻��̸� ��� ��(��Ʈ����Ʈ 4)
#define BOOLCOLOR(x) (x > 15)

//grid�� � ü������ ������
#define END -1
#define VOI 0
#define PON 1
#define KNI 2
#define BIS 3
#define ROO 4
#define QUE 5
#define KIN 6
//�� define�� ���� Ȱ���� ��Ʈ ����Ʈ 4�� �ؼ�
//��븻�� �츮���� ����

//asset�� �̸��� �޾Ƽ� �ּҸ� ��ȯ�ϴ� �Լ�
int** retCharPtr(int input);


#define charColor(input) (input > 15 ? GREEN : YELLOW)

void click();

//���� �����ߴ��� �� �ߴµ�
char clickflag;

int whereclicked_x;
int whereclicked_y;

void isCanGo(x, y);