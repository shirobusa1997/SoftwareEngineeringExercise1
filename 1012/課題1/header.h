// ===========================================================
// ソフトウェア工学演習I Software Engineering Exercise 1
// 2018.10.12 第2回 プログラム作成
// v1.0 header.h 独自ライブラリ
// s16t287 檜垣大地
// ===========================================================

// 重複宣言を回避するため、初回呼び出しのみ処理を実行します。
#ifndef SOURCE_MAIN_H
#define SOURCE_MAIN_H

#include <stdio.h>
#include <iostream>
#define MAX_EXPR 5

class test{
public:
  test(){}
  ~test(){}

  void getKeyInput();

  int counter;
};

#endif
