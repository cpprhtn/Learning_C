// 프젝.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include <conio.h>
#include<windows.h>
#include <time.h>
#pragma warning(disable:4996)
#define ESC 27
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

//전역변수 선언

int g_PX, g_PY;//캐릭터 위치

int g_step;
int g_push;
int g_Box;
int Menu_Flag = 1;
char map[10][10] =
{
{1,1,1,1,1,1,1,1,1,1},
{1,1,4,1,1,0,0,0,0,1},
{1,0,0,0,1,0,0,0,0,1},
{1,0,2,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};
void SetCursor(bool);

void gotoxy(int, int);

void Map();

void PlayerEraser();

void PlayerDraw();

void PlayerAction();

void MapDraw(int, int);

void ClearMessage();

void StageClearCheck(void);

void INTRO();

void BarDraw();

void Copy();

int main()
{
	system("mode con: cols=70 lines=22");

	SetCursor(false);

	Copy();

	while (1) {
		if (Menu_Flag) {
			INTRO();
		};
		PlayerAction();

		BarDraw();
		if (Menu_Flag) {
			INTRO();
		};

		PlayerAction();

		BarDraw();

		if (StageClearCheck()) {
			ClearMessage();
		}
	}
}

void SetCursor(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = bVisible;

	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void gotoxy(int x, int y)

{

	COORD Cur;
	Cur.X = x * 2;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Copy() {
	int x, y;
	for (y = 0; y < 10; y++) {
		for (x = 0; x < 10; x++) {
			 r_map[y][x] = map[y][x];
		}
	}
}

void INTRO() {
	int x = 12, y = 3;
	g_PX = 5, g_PY = 5;
	g_step = 0;
	g_push = 0;
	g_Box = 0;
	int x_, y_;

	for (y_ = 0; y_ < 10; y_++) {
		for (x_ = 0; x_ < 10; x++) {
			map[y_][x_] = r_map[y_][x_];
		}
	}
	system("cls");
	gotoxy(x, y); printf("Made by");
	gotoxy(x, y + 2); printf("Cpprhtn");

	printf("Press And Key...");
	getch();

	system("cls");

	Menu_Flag = 0;

	PlayerDraw();

	Map();

}
void BarDraw()
{
	int x = 23;
	int y = 0;
	gotoxy(x, 6); printf("MOVE : %d", g_step);
	gotoxy(x, 7); printf("PUSH : %d", g_push);
	gotoxy(x, 8); printf("Clear : %d", g_Box);
}
void Map() {
	int x, y;

	//시작위치 5,5
	for (y = 0; y < 10; y++) {
		for (x = 0; x < 10; x++) {
			MapDraw(x, y);
		}
	}
}
int StageClearCheck(void) {
	if (g_Box == 1)
		return 1;
	else
		return 0;
}
void ClearMessage()
{
	char ch;

	gotoxy(1, 19);
	printf("End Geme?(y/n)");

	ch = getch();

	switch (ch) {
	case 'y':
		exit(0);
		break;
	case 'n':
		Menu_Flag = 1;
		break;
	default:
		break;
	}
}
void MapDraw(int x, int y) {
	char data;
	data = map[y][x];

	switch (data) {
	case 0:
		printf(" ");
		break;
	case 1:
		printf("벽");
		break;
	case 2:
		printf("*");
		break;
	case 3:
		printf("0");
		break;
	case 4:
		printf("@");
		break;
	default:
		break;
	}
}
void PlayerDraw() {
	gotoxy(g_PX, g_PY);
	printf("!");
}

void PlayerEraser()
{
	gotoxy(g_PX, g_PY);
	printf(" ");
}

void PlayerAction()
{
	int dx = 0, dy = 0;
	bool tab_block = false;
	char dir;
	if (kbhit()) {
		dir = getch();
		switch (dir)
		{
		case ESC:
			system("cls");
			Menu_Flag = 1;
			break;
		case LEFT:
			dx--;
			break;
		case RIGHT:
			dx++;
			break;
		case UP:
			dy--;
			break;
		case DOWN:
			dy++;
			break;
		default:
			break;
		}
		if (map[g_PY + dy][g_PX + dx] != 1) {
			if (map[g_PY + dy][g_PX + dx] == 2) {
				if ((map[g_PY + dy * 2][g_PX + dx * 2] == 0 || map[g_PY + dy * 2][g_PX + dx * 2] == 3)) {
					if (map[g_PY + dy * 2][g_PX + dx * 2] == 3) {
						map[g_PY + dy * 2][g_PX + dx * 2] = 4;
						g_Box++;
						map[g_PY + dy][g_PX + dx] = 0;
					}
					else
					{
						map[g_PY + dy * 2][g_PX + dx * 2] = 2;
						map[g_PY + dy][g_PX + dx] = 0;
					}
					g_push++;
				}
				else return;
			}
			else if (map[g_PY + dy][g_PX + dx] == 4) {
				if (map[g_PY + dy * 2][g_PX + dx * 2] == 0) {
					map[g_PY + dy * 2][g_PX + dx * 2] = 2;
					map[g_PY + dy][g_PX + dx] = 3;
				}
				else if (map[g_PY + dy * 2][g_PX + dx * 2] == 3) {
					map[g_PY + dy * 2][g_PX + dx * 2] = 4;
					map[g_PY + dy][g_PX + dx] = 3;
				}
				else return;
				g_push++;
			}
			Map();
			PlayerEraser();
			if (dx || dy) {
				g_step++;
				g_PX += dx;
				g_PY += dy;
			}
			PlayerDraw();
		}
		else {
			if (map[g_PY + dy][g_PX + dx] != 2) {}
			return;
		}
	}
}