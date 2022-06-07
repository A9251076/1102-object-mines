#include "mine.h"

void Mine::gameInit(char map[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			map[i][j] = set;
		}
	}
}

void Mine::gameDraw(char map[ROWS][COLS], int row, int col)
{
	//�C�L�Ĥ@�檺�C�ХH�Τ��νu
	for (int i = 0; i <= row; i++)
	{
		cout << setw(2) << i;
		if (i < row)
		{
			cout << setw(2) << "|";
		}
	}
	cout << endl;

	//������νu
	for (int i = 0; i <= row; i++)
	{
		cout  << "---";
		if (i < row)
		{
			cout  << "|";
		}
	}
	cout << endl;

	//�C�L��Ƥα�����j�u
	for (int i = 1; i <= row; i++)
	{
		cout << " " << i << " |";
		for (int j = 1; j <= col; j++)
		{
			cout << " " << map[i][j] << " ";
			if (j < col)
			{
				cout << "|";
			}
		}
		cout << endl;
		if (i < row)
		{
			for (int k = 0; k <= col; k++)
			{
				cout << "---";
				if (k < col)
				{
					cout << "|";
				}
			}
		}
		cout << endl;
	}
}

void Mine::set_mine(char mine[ROWS][COLS], int row, int col)//�p��1
{
	int count = BOOM;
	while (count > 0)
	{
		int x = rand() % row + 1; //1-9
		int y = rand() % col + 1; //1-9
		if (mine[x][y] == '0')//�Ω�P�_�O�_���T���I�p�A�u���S�Q�I�L���p�~�۴�
		{
			mine[x][y] = '1';
			count--;
		}
		
	}
}

int Mine::get_mine_number(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void Mine::sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int xx;   int& x = xx;
	int yy;   int& y = yy;
	int win = 0;
	while (win < row * col - BOOM)
	{
		cout << "�п�J�z�n�d�ߪ��y��-->";
		cin >> x >> y;

		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (mine[x][y] == '0')
			{
				int count = get_mine_number(mine, x, y);
				show[x][y] = count + '0';
				win++;
				gameDraw(show, ROW, COL);
			}
			else
			{
				cout << "��p�A�A�Q�����F" << endl;
				gameDraw(mine, ROW, COL);
				break;
			}
		}
		else
		{
			cout << "�y�ЫD�k�A�Э��s��J" << endl;
		}
	}
	if (win == row * col - BOOM)
	{
		cout << "���߱z�A�ƹp���\�C" << endl;
	}
}

void Mine::menu()
{
	cout << "***************************" << endl;
	cout << "******  1. �}�l�C��  ******" << endl;
	cout << "******  0.   ���}    ******" << endl;
	cout << "***************************" << endl;
}
void Mine::game()
{
	char mine[ROWS][COLS] = { 0 }; //�Ω�I�p
	char show[ROWS][COLS] = { 0 }; //�Ω�C�����e�����

	//��l�ư}�C
	gameInit(mine, ROWS, COLS, '0'); // 0�A�s��p�����h�ѽL ��l�Ʈɥ��]�� 0 
	gameInit(show, ROWS, COLS, '*'); // *�A�i�ܵ��ϥΪ̪����h�ѽL ��l�Ʈɥ��]�� * 

	//�C�L�ѽL
	gameDraw(show, ROW, COL);

	//�I�p
	set_mine(mine, ROW, COL);

	//�}�l�ƹp
	sweeping(mine, show, ROW, COL);
}
void Mine::gameStart()
{
	srand((unsigned int)time(NULL));
	int input;
	int& reInput = input;
	do
	{
		
		menu();
		cout << "�п�ܿ�J�G(1/0)";
		
		cin >> reInput;
		
		switch (reInput)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "�z�w�h�X�C��\n";
			break;
		default:
			cout << "��ܿ��~�A�Э���\n";
			break;
		}
	} while (reInput);
}

