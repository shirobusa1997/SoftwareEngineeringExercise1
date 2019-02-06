// ヘッダ指定
#include <iostream>
#include <string>
#include <sstream>

#include <stdio.h>

// ==========================================================
// 	事前宣言
// ==========================================================

// 有向グラフ(ノード)
int Node[][9] = {
					{0, 1, 1, 0, 1, 0, 0, 0, 0}, 
					{0, 0, 0, 1, 0, 0, 1, 0, 0},
					{1, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 1, 1, 0, 0, 0, 1, 0},
					{0, 0, 1, 0, 1, 0, 0, 1, 1},
					{0, 0, 0, 1, 0, 1, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 1, 0, 1, 0, 0}
				};

// 追跡情報
typedef struct{
	int route[9];
	int length;
} analyzed_info;

void scan_resI(analyzed_info *inst){
	return;
}

void scan(analyzed_info *inst){
	return;
}

int main(void){
	analyzed_info raw_data;
	scan(raw_data);

	return 0;
}
