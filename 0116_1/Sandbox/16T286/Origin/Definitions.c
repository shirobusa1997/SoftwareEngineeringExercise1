#include <stdio.h>

#include "Definitions.h"
const char *chip_disp[] = {" ", "S", "G",
                           "■", "*", "J"}; /* マップチップの表示内容 */

const char *arrw_disp[] = {" ", "↓", "↑", "→",
                           "←"}; /* プレーヤ(の進行方向)の表示 */

/* 迷路本体 */
chip map[MAP_SIZE][MAP_SIZE] = {{WALL, WALL, WALL, STRT, WALL},
                                {WALL, JUMP, EMPT, EMPT, WALL},
                                {WALL, WALL, WALL, EMPT, WALL},
                                {WALL, EMPT, EMPT, EMPT, WALL},
                                {WALL, GOAL, WALL, WALL, WALL}};

int defficulty = -1; /* ゲームの難易度 */
