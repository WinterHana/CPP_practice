#include <iostream>
using namespace std;

class Inventory
{
private:
	int** inventory; // ����
	int* inventory_m; // ����
	int n, m; // ���� �Ҵ��� �� �޴� ũ��
public:
	Inventory(int _n, int _m); // ������
	~Inventory(); // �Ҹ���
	void GetItem(int x, int y); // ������ ���� ����
	void UseItem(int x, int y); // ������ ���� ����
	void PrintItem(); // ������ ���� ���
};

Inventory::Inventory(int _n, int _m)
{
	this->n = _n;
	this->m = _m;

	// 2���� ���� �Ҵ�
	this->inventory = new int* [m];
	for (int i = 0; i < m; i++)
	{
		inventory_m = new int[n];
		this->inventory[i] = inventory_m;
	}

	// �ʱ�ȭ�� ������ϴ�..��?
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