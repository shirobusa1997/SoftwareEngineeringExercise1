// ===========================================================
// ソフトウェア工学演習I Software Engineering Exercise 1
// 2018.11.09
// v1.0 source_main.cpp メインソース
// s16t287 檜垣大地
// ===========================================================

#include <stdio.h>

// マップチップのサイズ(縦横サイズは統一)
#define MAP_SIZE 5

// マップチップの構成要素
typedef enum {EMPT, STRT, GOAL, WALL, HIDE, JUMP} chip;

// マップチップの構成要素に対応する出力内容
const char *chip_disp[] = {" ", "S", "G", "■", "*", "J"};

// マップチップ
chip map[MAP_SIZE][MAP_SIZE] = {
									{WALL, WALL, WALL, STRT, WALL},
									{WALL, JUMP, EMPT, EMPT, WALL},
									{WALL, WALL, WALL, EMPT, WALL},
									{WALL, EMPT, EMPT, EMPT, WALL},
									{WALL, GOAL, WALL, WALL, WALL}
							   };

void show(){

	for(int y = 0; y < MAP_SIZE; y++){
		for(int x = 0; x < MAP_SIZE; x++){
			printf("%s", chip_disp[map[y][x]]);
		}
		printf("\n");
	}

	return;
}

int main(void){
	
	show();

	return 0;
}