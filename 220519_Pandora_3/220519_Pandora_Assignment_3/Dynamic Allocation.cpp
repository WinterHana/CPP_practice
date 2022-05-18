#include <iostream>
using namespace std;

class Inventory
{
private:
	int** inventory; // 세로
	int* inventory_m; // 가로
	int n, m; // 동적 할당할 때 받는 크기
public:
	Inventory(int _n, int _m); // 생성자
	~Inventory(); // 소멸자
	void GetItem(int x, int y); // 아이템 개수 증가
	void UseItem(int x, int y); // 아이템 개수 감소
	void PrintItem(); // 아이템 개수 출력
};

Inventory::Inventory(int _n, int _m)
{
	this->n = _n;
	this->m = _m;

	// 2차원 동적 할당
	this->inventory = new int* [m];
	for (int i = 0; i < m; i++)
	{
		inventory_m = new int[n];
		this->inventory[i] = inventory_m;
	}

	// 초기화를 해줘야하는..듯?
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inventory[i][j] = 0;
		}
	}
}
Inventory::~Inventory()
{
	for (int i = 0; i < m; i++)
	{
		delete[] inventory[i];
	}
	delete[] inventory;
}

void Inventory::GetItem(int x, int y)
{
	inventory[x][y]++;
}

void Inventory::UseItem(int x, int y)
{
	inventory[x][y]--;
}

void Inventory::PrintItem()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << inventory[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n, m;
	int x, y;
	char order;
	cin >> n >> m;
	Inventory myInventory(n, m);

	while (true)
	{
		cin >> order;
		if (order == 'g') 
		{
			cin >> x >> y;
			myInventory.GetItem(x, y);
		}

		else if (order == 'u')
		{
			cin >> x >> y;
			myInventory.UseItem(x, y);
		}	
		else if (order == 'p')
		{
			myInventory.PrintItem();
			break;
		}
	}
	return 0;
}