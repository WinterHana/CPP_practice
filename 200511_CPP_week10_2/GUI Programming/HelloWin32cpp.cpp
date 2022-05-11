#include <iostream>

using namespace std;

// 이 함수가 핵심!
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

// main 함수는 고정됨 -> 같은 이벤트이기 때문.. main 함수의 중요성이 떨어짐
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