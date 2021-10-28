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

//말이 이동할 수 있는 곳을 계산
char canGoGrid[10][10];

//폰의 x,y 좌표를 받아서 갈 수 있는지 계산
void isPonCanGo(int x, int y);


void initChessgrid();

//15이상이면 상대 꺼(비트시프트 4)
#define BOOLCOLOR(x) (x > 15)

//grid에 어떤 체스말이 들어가는지
#define END -1
#define VOI 0
#define PON 1
#define KNI 2
#define BIS 3
#define ROO 4
#define QUE 5
#define KIN 6
//이 define된 수를 활용해 비트 시프트 4를 해서
//상대말과 우리말을 구분

//asset의 이름을 받아서 주소를 반환하는 함수
int** retCharPtr(int input);


#define charColor(input) (input > 15 ? GREEN : YELLOW)

void click();

//말을 선택했는지 안 했는데
char clickflag;

int whereclicked_x;
int whereclicked_y;

void isCanGo(x, y);