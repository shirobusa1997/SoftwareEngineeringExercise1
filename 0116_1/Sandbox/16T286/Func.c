#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Definitions.h"

/* バッファのクリア */
void stdin_clear(void)
{
	while (getchar() != '\n') {
		;
	}
}

/* min以上max以下の値を受け取る */
int getInput(int min, /* 最低値 */
             int max  /* 最高値 */
)
{
	int input;

	for (; 1;) {
		printf("> ");

		input = fgetc(stdin) - '0';
		stdin_clear();
		if (min <= input && input <= max) {
			return input;
		}
		printf("入力値が正しくありません．再入力してください．\n");
	}
	
	//	printf("続行するには何かキーをおしてください．\n");
}

/* 進路方向に対して，次の座標を決める */
Point get_newpos(Point new_pos, /* 座標 */
                 int   dir      /* 進路方向 */
)
{

	switch (dir) {
	case 1:
		new_pos.y++;
		break;
	case 3:
		new_pos.y--;
		break;
	case 2:
		new_pos.x++;
		break;
	case 4:
		new_pos.x--;
		break;

	default:
		break;
	}

	return new_pos;
}

/* プレイヤーの周囲1マスか判定 */
BOOL ck_around(Point pos, int x, int y)
{
	if ((pos.x - 1 <= x && x <= pos.x + 1) && (pos.y - 1 <= y && y <= pos.y + 1)) {
		return TRUE;
	}

	return FALSE;
}

/* 迷路の表示を行う */
void show(Point pos, /* プレイヤーの座標 */
          int   dir  /* 進行方向 */
)
{
	int i, j;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			if (i == pos.y && j == pos.x) {
				printf("%s", arrw_disp[dir]);
			} else if ((difficulty == 2) && (!ck_around(pos, j, i))) {
				/* HARDの場合，周囲1マスを隠す */
				printf("%s", chip_disp[4]);
			} else {
				printf("%s", chip_disp[map[i][j]]);
			}
		}
		puts("");
	}
}

/* エリア外か判定 */
int ckArea(Point pos, /* ユーザの現在地 */
           int   dir  /* 進路方向 */
)
{
	if (pos.x >= MAP_SIZE || pos.x < 0)
		return -1;
	if (pos.y >= MAP_SIZE || pos.y < 0)
		return -1;
	if (map[pos.y][pos.x] == WALL)
		return -2;
	if (map[pos.y][pos.x] == STRT)
		return 1;
	if (map[pos.y][pos.x] == GOAL)
		return 2;
	if (map[pos.y][pos.x] == JUMP)
		return 3;

	return 0;
}

/* ランダムな通路上の位置を返す */
Point jump(void)
{
	int   i, j, wall_num = 0;
	Point wall_data[MAP_SIZE * MAP_SIZE];

	/* 通路を走査 */
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] == EMPT) {
				wall_data[wall_num].x = i;
				wall_data[wall_num].y = j;
				wall_num++;
			}
		}
	}

	int rnd = rand() % (wall_num) + 0;
	return wall_data[rnd];
}

/* セーブデータの存在確認 */
BOOL ckData(void)
{
	FILE *fp;
	if ((fp = fopen(SAVE_FILE_NAME, "r")) == NULL) {
		return FALSE;
	}

	fclose(fp);
	return TRUE;
}

/* セーブデータの保存 */
void saveData(Point pos)
{
	FILE *fp;
	if ((fp = fopen(SAVE_FILE_NAME, "w")) == NULL) {
		exit(1);
	}

	fprintf(fp, "%f %d %d", (double)difficulty, pos.x, pos.y);

	fclose(fp);
}

/* セーブデータのロード */
Point loadData(void)
{
	Point pos;
	FILE *fp;
	if ((fp = fopen(SAVE_FILE_NAME, "r")) == NULL) {
		exit(1);
	}

	fscanf(fp, "%d %d %d", &difficulty, &pos.y, &pos.x);

	fclose(fp);

	return pos;
}
