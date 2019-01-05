// ===========================================================
// ソフトウェア工学演習I Software Engineering Exercise 1
// 2018.10.12 第2回 プログラム作成
// v1.0 source_class.cpp テストソース
// s16t287 檜垣大地
// ===========================================================

#include "header.h"
using namespace std;

void test::getKeyInput(){
  int coutner;
  int answer = sizeof(int);

  int user[5] = {0};

  printf("任意の整数値を5つ入力してください。\n=>");
  for(counter = 0; counter < MAX_EXPR; counter++){
    scanf("%d", &user[counter]);
    answer = (answer > user[counter]) ? user[counter] : answer;
  }

  printf("\n<<< 結果 >>>\n");
  for(counter = 0; counter < MAX_EXPR; counter++){
    printf("%d回目 : %d\n", counter + 1, user[counter]);
  }
  printf("\n最小値 : %d\n", answer);
}
