#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#ifndef GLOBAL
#define GLOBAL extern
#endif

// P01_原文
/*
#ifndef BOOL
typedef enum { TRUE, FALSE } BOOL;
#endif
*/

// P01_修正後
#ifndef BOOL
typedef enum { FALSE, TRUE } BOOL;
#endif

/* 迷路上の座標(原点は左上の端) */
typedef struct {
	int x;
	int y;
} Point;

#define MAP_SIZE 5 /* 迷路のサイズ */

/* 迷路の構成要素(マップチップ) */
typedef enum { EMPT, STRT, GOAL, WALL, HIDE, JUMP } chip;

GLOBAL const char *chip_disp[]; /* マップチップの表示内容 */
GLOBAL const char *arrw_disp[]; /* プレーヤ(の進行方向)の表示 */
GLOBAL chip map[MAP_SIZE][MAP_SIZE]; /* 迷路本体 */

int difficulty; /* ゲームの難易度 */

/* バッファのクリア */
void stdin_clear(void);

/* min以上max以下の値を受け取る */
int getInput(int, int);

/* 進路方向に対して，次の座標を決める */
Point get_newpos(Point, int);

/* プレイヤーの周囲1マスか判定 */
BOOL ck_around(Point, int, int);

/* 迷路とプレイヤーの表示を行う */
void show(Point, int);

/* エリア外か判定 */
int ckArea(Point, int);

/* ランダムな通路上の位置を返す */
Point jump(void);

#define SAVE_FILE_NAME "game.dat" /* セーブデータのファイル名 */

/* セーブデータの存在確認 */
BOOL ckData(void);

/* セーブデータの保存 */
void saveData(Point);

/* セーブデータのロード */
Point loadData(void);

#endif