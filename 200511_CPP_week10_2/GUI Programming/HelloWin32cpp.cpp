#include <iostream>

using namespace std;

// �� �Լ��� �ٽ�!
void proc(int message)
{
	switch (message)
	{
	case 1: cout << "Sejong University" << endl;	break;
	case 2: cout << "Software Dept." << endl;		break;
	case 3: cout << "Bye~" << endl; exit(0);		break;
	case 4:											break;
	case 5:											break;
	default:										break;
	}
}

// main �Լ��� ������ -> ���� �̺�Ʈ�̱� ����.. main �Լ��� �߿伺�� ������
int main()
{
	int message;

	while (true)
	{
		cout << "Input : ";
		cin >> message;

		proc(message);
	}

	return 0;
}