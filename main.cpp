#include "mine.h"

//�O�_�}�l�C�������
void menu()
{
	cout << "***************************" << endl;
	cout << "******  1. �}�l�C��  ******" << endl;
	cout << "******  0.   ���}    ******" << endl;
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
		cout << "�п�ܿ�J�G(1/0)";
		cin >> reInput;

		switch (reInput)
		{
		case 1:
			start.game();
			break;
		case 0:
			cout << "�z�w�h�X�C��" << endl;
			break;
		default:
			cout << "��ܿ��~�A�Э���" << endl;
			break;
		}
	} while (reInput);

	return 0;
}