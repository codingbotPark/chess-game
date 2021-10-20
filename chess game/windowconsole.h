#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define L_BLUE 9
#define L_GREEN 10
#define L_AQUA 11
#define L_RED 12
#define L_PURPLE 13
#define L_YELLOW 14
#define L_WHITE 15

#define DOT "  "

#define WIDTH 250
#define HEIGHT 130

void setting();
void gotoxy(int, int);
void setcolor(char);