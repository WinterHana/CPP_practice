#include <iostream>
#include <string>

using namespace std;

int main() {


	int* ptr1 = new int[5]{ 1 };

	cout << *(ptr1 + 1);

	delete[] ptr1;
	ptr1 = 0;
	ptr1 = nullptr;

	return 0;
}

/*
�����Ҵ�
 ����Ǿ���ϴ°� �ڷ��� *�����̸�
 1. new �ڷ���;�� �������� ��밡�� -> �ϳ��� ������ŭ �޸� �Ҵ�
 2. new �ڷ���[ũ��];�� �������� �迭 �����Ҵ� ����
 int *p = new int;


 new int[5] => 5�� ��ŭ �Ҵ��ϴ°Ű� �ʱ�ȭ�� ����
 new int(5)�� 1����ŭ �Ҵ��ϰ� 5�� �ʱ�ȭ�ϴ� ��
 new int{ 6 }; => 1ĭ¥�� �迭�̰� {����, ����,...}�� �迭�� ���Ҹ� �ʱ�ȭ�� �� ���� ��

 delete �����ͺ��� => (single)������ �����Ҵ��� �����ϴ� ��
 delete[] �����ͺ��� => �迭�� �����Ҵ��� �����ϴ� ��
 */