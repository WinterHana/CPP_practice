#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int num = 1;
	int i = 0;
	while (true)
	{
		if (i == str.length() - 1)
		{
			break;
		}

		cout << num << ':';

		do
		{
			if (str[i] == ';')
			{
				i++;
				continue;
			}
			cout << str[i];
			i++;

		} while (str[i] != ';');

		num++;

		cout << endl;
	}

	return 0;
}