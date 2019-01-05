// ===========================================================
// ソフトウェア工学演習I Software Engineering Exercise 1
// 2018.11.30
// v1.0 source_main.cpp メインソース
// s16t287 檜垣大地
// ===========================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

// VisualStudioコンパイラ用、scanf()警告回避
// #pragma warning(disable:4996)

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

// ゲーム何度
int difficulty = -1;

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
			else if (difficulty == 2 && (abs(pos.x - x) > 1 || abs(pos.y - y) > 1))
				 	{ printf("*"); }
			else 	{ printf("%s", chip_disp[map[y][x]]); }
		}
		printf("\n");
	}
	return;
}

// 移動可能はマスに、ランダムにプレイヤーを移動させる関数です。
Point jump() {
    Point empt_index[MAP_SIZE * MAP_SIZE];
    int empt_amount = 0;

    for(int y = 0; y < MAP_SIZE; y++){
        for(int x = 0; x < MAP_SIZE; x++){
            if(map[y][x] == EMPT){
                empt_index[empt_amount].x = x; empt_index[empt_amount].y = y;
                empt_amount++;
            }
        }
    }

    return empt_index[rand() % empt_amount];
}

// min以上、max以下の数字を標準出力から取得し、main関数に返す関数です。
int getInput(int min, int max){
	std::string userdata;
	int ud_num = 0;

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
		new_pos = jump();
		printf("ランダムな場所に飛ばされました!\n");
	}
	else if (map[new_pos.y][new_pos.x] == GOAL)
	{
		printf("ゴールに到達しました！\n");
		*game_end = true;
	}
	*pos = new_pos;
	return;
}

void loadData(Point *pos, FILE *userdata){
	CONTINUE:
	if((userdata = fopen("userdata", "r+")) != NULL){
		printf("セーブデータが見つかりました。続きから始めますか？\n");
		printf("1:YES 2:NO\n> ");
		switch(getInput(1,2)){
			case 1:
				fscanf(userdata, "%d %d %d", difficulty, pos -> x, pos -> y);
				break;
			case 2:
				goto NEW_GAME;		}
	} else {
		NEW_GAME:
		// ファイル新規作成
		if((userdata = fopen("userdata", "w")) == NULL){
			//ファイル新規作成失敗時、異常終了
			printf("セーブデータの処理に失敗しました。プログラムを終了します。\n");
			exit(1);
		}
		// 新規ゲーム処理
		printf("新規にゲームを開始します。難易度を選択してください。\n");
		printf("1:EASY 2:HARD\n> ");
		difficulty = getInput(1, 2);
	}

	return;
}

int main(void){
	// ローカル変数宣言
	FILE *userdata;								// セーブデータ
	int input;										// プレイヤーの入力値
	int dir = 270;								// プレイヤーの向き
	Point pos;      							// プレイヤーの現在位置
	bool game_end = false;				// ゲーム終了状態フラグ

	// ゲーム初期化
	// 乱数初期化
	srand((unsigned) time(NULL));
	pos.x = MAP_SIZE - 2; pos.y = 0;

	loadData(&pos, userdata);

	show(pos, dir);

	while (!game_end) {
	    printf("進行方向を選んでください。\n");
	    printf("-----------------------\n");
	    printf("1:↓ 2:↑ 3:→ 4:←\n");
	    printf("-----------------------\n");
	    printf("> ");
		input = getInput(0, 4);

		mapResolver(&pos, input, &dir, &game_end);

		show(pos, dir);
	}



	return 0;
}