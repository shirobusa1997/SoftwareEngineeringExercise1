// ===========================================================
// �\�t�g�E�F�A�H�w���KI Software Engineering Exercise 1
// 2018.11.30
// v1.0 source_main.cpp ���C���\�[�X
// s16t287 �w�_��n
// ===========================================================

#include <stdio.h>
#include <string>
#include <iostream>

// �}�b�v�`�b�v�̃T�C�Y(�c���T�C�Y�͓���)
#define MAP_SIZE 5

// �}�b�v�`�b�v�̍\���v�f
typedef enum {EMPT, STRT, GOAL, WALL, HIDE, JUMP} chip;
// �v���C���[��2�������W
typedef struct {
	int x;
	int y;
} Point;

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

// ���݃Z�b�g����Ă���}�b�v�`�b�v����A�}�b�v�ƃv���C���[���o�͂���֐��ł��B
// �����Ƃ��āAPoint�^�\���̂��w�肵�܂��B
void show(Point pos){
	for(int y = 0; y < MAP_SIZE; y++){
		for(int x = 0; x < MAP_SIZE; x++){
			if (pos.x == x && pos.y == y) { printf("��"); }
			else { printf("%s", chip_disp[map[y][x]]); }
		}
		printf("\n");
	}
	return;
}

// min�ȏ�Amax�ȉ��̐�����W���o�͂���擾���Amain�֐��ɕԂ��֐��ł��B
int getInput(int min, int max){
	std::string userdata;
	int ud_num = 0;

	printf("�i�s������I��ł��������B\n");
	printf("-----------------------\n");
	printf("1:�� 2:�� 3:�� 4:��\n");
	printf("-----------------------\n");
	printf("> ");

	while(true){
		std::cin >> userdata;
		
		try {
			ud_num = stoi(userdata);
		} catch(const std::invalid_argument& e){
			printf("���͒l������������܂���B�ē��͂��Ă��������B\n");
			printf("> ");
			continue;
		}

		if (ud_num < min || ud_num > max){
			printf("���͒l������������܂���B�ē��͂��Ă��������B\n");
			printf("> ");
		} else { return ud_num; }
	}
}

int main(void){
	// ���[�J���ϐ��錾
	int input;							// �v���C���[�̓��͒l
	Point pos, new_pos;					// �v���C���[�̌��݈ʒu�A�ړ���̈ʒu
	bool game_end = false;				// �Q�[���I����ԃt���O

	pos.x = MAP_SIZE - 2; pos.y = 0;

	show(pos);
	
	while (!game_end) {
		input = getInput(0, 4);

		switch (input) {
			case 1:
				new_pos.x = pos.x; new_pos.y = pos.y + 1; break;  // ��
			case 2:
				new_pos.x = pos.x; new_pos.y = pos.y - 1; break;  // ��
			case 3:
				new_pos.x = pos.x + 1; new_pos.y = pos.y; break;  // �E
			case 4:
				new_pos.x = pos.x - 1; new_pos.y = pos.y; break;  // ��
			default:
				return 0;
		}

		pos = new_pos;
		show(pos);
	}

	return 0;
}