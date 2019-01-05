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
// 引数として、Point型構造体
void show(Point pos, int dir){
	for(int y = 0; y < MAP_SIZE; y++){
		for(int x = 0; x < MAP_SIZE; x++){
			if (pos.x == x && pos.y == y)
			{
				switch (dir) {
					case 0:
						printf("→"); break;
					case 90:
						printf("↑"); break;
					case 180:
						printf("←"); break;
					case 270:
						printf("↓"); break;
					default:
						break;
				}
			}
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

void mapResolver(Point *pos, int input, int *dir, bool *game_end){
    Point new_pos;

    switch (input) {
        case 1:
            new_pos.x = pos -> x; new_pos.y = pos -> y + 1; *dir = 270; break;
        case 2:
            new_pos.x = pos -> x; new_pos.y = pos -> y - 1; *dir = 90;  break;
        case 3:
            new_pos.x = pos -> x + 1; new_pos.y = pos -> y; *dir = 0;   break;
        case 4:
            new_pos.x = pos -> x - 1; new_pos.y = pos -> y; *dir = 180; break;
        default:
            exit(0);
    }

	if ((new_pos.x < 0 || new_pos.y < 0) ||
		(new_pos.x >= MAP_SIZE || new_pos.y >= MAP_SIZE) ||
		map[new_pos.y][new_pos.x] == WALL)
	{
		printf("その方向には進めません!\n");
		return;
	}
	else if (map[new_pos.y][new_pos.x] == JUMP)
	{
		new_pos.x = MAP_SIZE - 2; new_pos.y = 0;
		printf("スタート地点に戻ってしまいました...\n");
	}
	else if (map[new_pos.y][new_pos.x] == GOAL)
	{
		printf("ゴールに到達しました！\n");
		*game_end = true;
	}
	*pos = new_pos;
	return;
}

int main(void){
// ローカル変数宣言
int input;							// プレイヤーの入力値
int dir = 270;						// プレイヤーの向き
Point pos;      					// プレイヤーの現在位置
bool game_end = false;				// ゲーム終了状態フラグ

pos.x = MAP_SIZE - 2; pos.y = 0;

show(pos, dir);

while (!game_end) {
	input = getInput(0, 4);

	mapResolver(&pos, input, &dir, &game_end);

	show(pos, dir);
}

return 0;
}