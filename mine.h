#include<iostream>
#include <ctime>
#include<iomanip>
using namespace std;

#define ROW 9//��ܴѽL�u�����j�p
#define COL 9
#define ROWS ROW + 2//���F�����}�C�V�ɦӦh�]�w�F����C���}�C�j�p
#define COLS COL + 2
#define BOOM 10//�]�w��10�ӹp

class Mine {
public:

	//��l�ư}�C,��椺��l��
	void gameInit(char map[ROWS][COLS], int rows, int cols, char set);

	//�C�L�ѽL���,�y��
	void gameDraw(char map[ROWS][COLS], int row, int col);

	//�I�p//�p��1
	void set_mine(char map[ROWS][COLS], int row, int col);

	//�p��y�ЩP��(�E�c��)�p�Ӽ�
	//static int get_mine_number();

	//�}�l�ƹp
	void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

	//�O�_�}�l�C�������
	void menu();

	void game();

	//�`���A�C���}�l
	void gameStart();
};
