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
	//列印第一行的列標以及分割線
	for (int i = 0; i <= row; i++)
	{
		cout << setw(2) << i;
		if (i < row)
		{
			cout << setw(2) << "|";
		}
	}
	cout << endl;

	//控制分割線
	for (int i = 0; i <= row; i++)
	{
		cout  << "---";
		if (i < row)
		{
			cout  << "|";
		}
	}
	cout << endl;

	//列印資料及控制分隔線
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

void Mine::set_mine(char mine[ROWS][COLS], int row, int col)//雷為1
{
	int count = BOOM;
	while (count > 0)
	{
		int x = rand() % row + 1; //1-9
		int y = rand() % col + 1; //1-9
		if (mine[x][y] == '0')//用於判斷是否正確的埋雷，只有沒被埋過的雷才自減
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
		cout << "請輸入您要查詢的座標-->";
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
				cout << "抱歉，你被炸死了" << endl;
				gameDraw(mine, ROW, COL);
				break;
			}
		}
		else
		{
			cout << "座標非法，請重新輸入" << endl;
		}
	}
	if (win == row * col - BOOM)
	{
		cout << "恭喜您，排雷成功。" << endl;
	}
}

void Mine::menu()
{
	cout << "***************************" << endl;
	cout << "******  1. 開始遊戲  ******" << endl;
	cout << "******  0.   離開    ******" << endl;
	cout << "***************************" << endl;
}
void Mine::game()
{
	char mine[ROWS][COLS] = { 0 }; //用於埋雷
	char show[ROWS][COLS] = { 0 }; //用於遊戲的畫面顯示

	//初始化陣列
	gameInit(mine, ROWS, COLS, '0'); // 0，存放雷的底層棋盤 初始化時全設為 0 
	gameInit(show, ROWS, COLS, '*'); // *，展示給使用者的頂層棋盤 初始化時全設為 * 

	//列印棋盤
	gameDraw(show, ROW, COL);

	//埋雷
	set_mine(mine, ROW, COL);

	//開始排雷
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
		cout << "請選擇輸入：(1/0)";
		
		cin >> reInput;
		
		switch (reInput)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "您已退出遊戲\n";
			break;
		default:
			cout << "選擇錯誤，請重試\n";
			break;
		}
	} while (reInput);
}

