// ===========================================================
// ソフトウェア工学演習I Software Engineering Exercise 1
// 2018.11.30
// v1.0 source_main.cpp メインソース
// s16t287 檜垣大地
// ===========================================================

#include <stdio.h>
#include <string>
#include <iostream>

// マップチップのサイズ(縦横サイズは統一)
#define MAP_SIZE 5

// マップチップの構成要素
typedef enum {EMPT, STRT, GOAL, WALL, HIDE, JUMP} chip;
// プレイヤーの2次元座標
typedef struct {
	int x;
	int y;
} Point;

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

// 現在セットされているマップチップから、マップとプレイヤーを出力する関数です。
// 引数として、Point型構造体を指定します。
void show(Point pos){
	for(int y = 0; y < MAP_SIZE; y++){
		for(int x = 0; x < MAP_SIZE; x++){
			if (pos.x == x && pos.y == y) { printf("↓"); }
			else { printf("%s", chip_disp[map[y][x]]); }
		}
		printf("\n");
	}
	return;
}

// min以上、max以下の数字を標準出力から取得し、main関数に返す関数です。
int getInput(int min, int max){
	std::string userdata;
	int ud_num = 0;

	printf("進行方向を選んでください。\n");
	printf("-----------------------\n");
	printf("1:↓ 2:↑ 3:→ 4:←\n");
	printf("-----------------------\n");
	printf("> ");

	while(true){
		std::cin >> userdata;
		
		try {
			ud_num = stoi(userdata);
		} catch(const std::invalid_argument& e){
			printf("入力値が正しくありません。再入力してください。\n");
			printf("> ");
			continue;
		}

		if (ud_num < min || ud_num > max){
			printf("入力値が正しくありません。再入力してください。\n");
			printf("> ");
		} else { return ud_num; }
	}
}

int main(void){
	// ローカル変数宣言
	int input;							// プレイヤーの入力値
	Point pos, new_pos;					// プレイヤーの現在位置、移動後の位置
	bool game_end = false;				// ゲーム終了状態フラグ

	pos.x = MAP_SIZE - 2; pos.y = 0;

	show(pos);
	
	while (!game_end) {
		input = getInput(0, 4);

		switch (input) {
			case 1:
				new_pos.x = pos.x; new_pos.y = pos.y + 1; break;  // 上
			case 2:
				new_pos.x = pos.x; new_pos.y = pos.y - 1; break;  // 下
			case 3:
				new_pos.x = pos.x + 1; new_pos.y = pos.y; break;  // 右
			case 4:
				new_pos.x = pos.x - 1; new_pos.y = pos.y; break;  // 左
			default:
				return 0;
		}

		pos = new_pos;
		show(pos);
	}

	return 0;
}