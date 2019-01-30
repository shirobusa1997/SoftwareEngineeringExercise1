#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Definitions.h"

int main(void)
{
	Point pos;                    // プレイヤーの現在位置
	pos.x         = MAP_SIZE - 2; // スタート地点の一を設定する
	pos.y         = 0;
	Point new_pos = pos; // 移動後

	BOOL game_end = FALSE; // ゲームの終了確認
	int  dir      = 1;     //入力値

	int load = 0;

	/* ゲーム起動時 */
	srand((unsigned)time(NULL));

	printf("=====================================================\n");
	printf("                 迷路探索ゲーム\n");
	printf("=====================================================\n");

	if (ckData()) {
		printf("前回のデータがあります．ロードしますか？\n");
		printf("1:はい 2:いいえ\n");
		load = getInput(1, 2);
	}

	switch (load) {
	case 0:
		printf("ゲームデータが存在しません．\n");
	case 2:
		printf("新規にゲームを開始します．難易度を選択してください．\n");
		printf("1:EASY 2:HARD\n");
		difficulty = getInput(1, 2);
		break;

	case 1:
		pos = loadData();
		break;
	default:
		break;
	}

	/* 迷路開始 */
	while (!game_end) {
		show(pos, dir);

		printf("進行方向を選んでください．\n");
		printf("0:終了 1:↓ 2:↑ 3:→ 4:← \n");
		dir = getInput(0, 5);

		if (dir == 0) {
			printf("セーブしました\n");
			printf("ゲームを終了します\n");
			game_end = TRUE;
			saveData(pos);
			continue;
		}

		new_pos = get_newpos(pos, dir);

		if (ckArea(new_pos, dir) == -1 || ckArea(new_pos, dir) == -2) {
			printf("その方向には進めません．\n");
			game_end = FALSE;
		} else if (ckArea(new_pos, dir) == 1) {
			printf("スタートに戻りました．\n");
			game_end = FALSE;
		} else if (ckArea(new_pos, dir) == 2) {
			printf("ゴールです．\n");
			game_end = TRUE;
		} else if (ckArea(new_pos, dir) == 3) {
			printf("ランダムな位置に飛ばされました．\n");
			pos = jump();
		} else {
			pos = new_pos;
		}
	}

	return 0;
}
