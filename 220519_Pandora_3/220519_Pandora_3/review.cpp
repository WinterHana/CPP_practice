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
동적할당
 선행되어야하는거 자료형 *변수이름
 1. new 자료형;의 형식으로 사용가능 -> 하나의 공간만큼 메모리 할당
 2. new 자료형[크기];의 형식으로 배열 동적할당 가능
 int *p = new int;


 new int[5] => 5개 만큼 할당하는거고 초기화는 없음
 new int(5)는 1개만큼 할당하고 5로 초기화하는 것
 new int{ 6 }; => 1칸짜리 배열이고 {원소, 원소,...}는 배열의 원소를 초기화할 때 쓰는 것

 delete 포인터변수 => (single)변수의 동적할당을 해제하는 것
 delete[] 포인터변수 => 배열의 동적할당을 해제하는 것
 */