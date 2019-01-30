// ===========================================================
// �\�t�g�E�F�A�H�w���KI Software Engineering Exercise 1
// 2018.11.09
// v1.0 source_main.cpp ���C���\�[�X
// s16t287 �w�_��n
// ===========================================================

#include <stdio.h>

// �}�b�v�`�b�v�̃T�C�Y(�c���T�C�Y�͓���)
#define MAP_SIZE 5

// �}�b�v�`�b�v�̍\���v�f
typedef enum {EMPT, STRT, GOAL, WALL, HIDE, JUMP} chip;

// �}�b�v�`�b�v�̍\���v�f�ɑΉ�����o�͓��e
const char *chip_disp[] = {" ", "S", "G", "��", "*", "J"};

// �}�b�v�`�b�v
chip map[MAP_SIZE][MAP_SIZE] = {
									{WALL, WALL, WALL, STRT, WALL},
									{WALL, JUMP, EMPT, EMPT, WALL},
									{WALL, WALL, WALL, EMPT, WALL},
									{WALL, EMPT, EMPT, EMPT, WALL},
									{WALL, GOAL, WALL, WALL, WALL}
							   };

void show(){

	for(int y = 0; y < MAP_SIZE; y++){
		for(int x = 0; x < MAP_SIZE; x++){
			printf("%s", chip_disp[map[y][x]]);
		}
		printf("\n");
	}

	return;
}

int main(void){
	
	show();

	return 0;
}