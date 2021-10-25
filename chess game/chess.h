#include "grapics.h"
#include <stdio.h>

extern int myCursorX;
extern int myCursorY;

//말들의 그림을 txt파일에서 불러와 저장하는 배열
int pon_asset[14][14];
int bisop_asset[14][14];
int king_asset[14][14];
int knight_asset[14][14];
int queen_asset[14][14];
int rook_asset[14][14];

void loadAsset(const char, int(*)[14]);
//케릭터 하나하나의 이름, 저장위치를 입력받아 출력

//현재 체스파일 형태를 저장하는 배열
char chessGrid[10][10];
//원래는 8 * 8 이지만 인덱스 값을 넣기 편하게 10,10으로 한다

void initChessgrid();

//grid에 어떤 체스말이 들어가는지
#define END -1
#define VOI 0
#define PON 1
#define KNI 2
#define BIS 3
#define ROO 4
#define QUE 5
#define KIN 6

//asset의 이름을 받아서 주소를 반환하는 함수
int** retCharPtr(int input);
