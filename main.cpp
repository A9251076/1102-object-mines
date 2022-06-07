#include "mine.h"

//是否開始遊戲的菜單
void menu()
{
	cout << "***************************" << endl;
	cout << "******  1. 開始遊戲  ******" << endl;
	cout << "******  0.   離開    ******" << endl;
	cout << "***************************" << endl;
}

int main()
{

	Mine start;
	//start.gameStart();
	srand((unsigned int)time(NULL));
	int input;
	int& reInput = input;
	menu();
	do
	{
		cout << "請選擇輸入：(1/0)";
		cin >> reInput;

		switch (reInput)
		{
		case 1:
			start.game();
			break;
		case 0:
			cout << "您已退出遊戲" << endl;
			break;
		default:
			cout << "選擇錯誤，請重試" << endl;
			break;
		}
	} while (reInput);

	return 0;
}