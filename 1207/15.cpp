// ===========================================================
// �\�t�g�E�F�A�H�w���KI Software Engineering Exercise 1
// 2018.11.30
// v1.0 source_main.cpp ���C���\�[�X
// s16t287 �w�_��n
// ===========================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

// VisualStudio�R���p�C���p�Ascanf()�x�����
// #pragma warning(disable:4996)

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

// �Q�[�����x
int difficulty = -1;

// �}�b�v�`�b�v
chip map[MAP_SIZE][MAP_SIZE] = {
									{WALL, WALL, WALL, STRT, WALL},
									{WALL, JUMP, EMPT, EMPT, WALL},
									{WALL, WALL, WALL, EMPT, WALL},
									{WALL, EMPT, EMPT, EMPT, WALL},
									{WALL, GOAL, WALL, WALL, WALL}
							   };

// ���݃Z�b�g����Ă���}�b�v�`�b�v����A�}�b�v�ƃv���C���[���o�͂���֐��ł��B
// �����Ƃ��āAPoint�^�\����
void show(Point pos, int dir){
	for(int y = 0; y < MAP_SIZE; y++){
		for(int x = 0; x < MAP_SIZE; x++){
			if (pos.x == x && pos.y == y)
			{
				switch (dir) {
					case 0:
						printf("��"); break;
					case 90:
						printf("��"); break;
					case 180:
						printf("��"); break;
					case 270:
						printf("��"); break;
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

// �ړ��\�̓}�X�ɁA�����_���Ƀv���C���[���ړ�������֐��ł��B
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

// min�ȏ�Amax�ȉ��̐�����W���o�͂���擾���Amain�֐��ɕԂ��֐��ł��B
int getInput(int min, int max){
	std::string userdata;
	int ud_num = 0;

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
		printf("���̕����ɂ͐i�߂܂���!\n");
		return;
	}
	else if (map[new_pos.y][new_pos.x] == JUMP)
	{
		new_pos = jump();
		printf("�����_���ȏꏊ�ɔ�΂���܂���!\n");
	}
	else if (map[new_pos.y][new_pos.x] == GOAL)
	{
		printf("�S�[���ɓ��B���܂����I\n");
		*game_end = true;
	}
	*pos = new_pos;
	return;
}

int main(void){
// ���[�J���ϐ��錾
int input;							// �v���C���[�̓��͒l
int dir = 270;						// �v���C���[�̌���
Point pos;      					// �v���C���[�̌��݈ʒu
bool game_end = false;				// �Q�[���I����ԃt���O

// ����������
srand((unsigned) time(NULL));

pos.x = MAP_SIZE - 2; pos.y = 0;

// ��Փx�w��
printf("�V�K�ɃQ�[�����J�n���܂��B��Փx��I�����Ă��������B\n");
printf("1:EASY 2:HARD\n> ");
difficulty = getInput(1, 2);

show(pos, dir);

while (!game_end) {
    printf("�i�s������I��ł��������B\n");
    printf("-----------------------\n");
    printf("1:�� 2:�� 3:�� 4:��\n");
    printf("-----------------------\n");
    printf("> ");
	input = getInput(0, 4);

	mapResolver(&pos, input, &dir, &game_end);

	show(pos, dir);
}

return 0;
}