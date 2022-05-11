#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
class Student
{
public:
	string name;
	int num;
	Student() { name = ""; num = 0; }
	Student(string n, int i) { name = n; num = i; }
	friend ostream& operator<<(ostream& o, const Student& in);

	static enum Mode { COMP_NUM, COMP_NAME, COMP_NUM_DESC, COMP_NAME_DESC }; // 열거형을 이용해서 더 명확하게 표현할 수 있음
	static Mode compareMode;
	static bool compare(const Student& a, const Student& b); // 변수를 사용만 할 꺼면 const 붙이면 됨. 사실 안붙어도 무방
};

Student::Mode Student::compareMode = Mode::COMP_NUM;

ostream& operator<<(ostream& o, const Student& in)
{
	cout << "Num : " << in.num << " Name : " << in.name;
	return o;
}

// Student 객체를 정렬하기 위한 static 함수 >> bool 값 반환
bool Student::compare(const Student& a, const Student& b)
{
	if (compareMode == Mode::COMP_NUM)
	{
		return (a.num < b.num);
	}

	if (compareMode == Mode::COMP_NUM_DESC)
	{
		return (a.num > b.num);
	}

	if (compareMode == Mode::COMP_NAME)
	{
		return (a.name < b.name);
	}

	if (compareMode == Mode::COMP_NAME_DESC)
	{
		return (a.name > b.name);
	}
}

// 내림차순으로 정렬하기 위한 함수 >> bool 값 반환
bool myCompare(const int& a, const int& b)
{
	// return (a < b) // 같은 내용임
	if (a > b) return true;
	return false;
}

int main()
{
	vector<int> arr; // 동적 배열 생성(탬플릿)

	// 랜덤한 수 생성 후 배열에 넣기
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
	}

	// 출력
	for (auto e : arr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	// 정렬하기(오름차순)
	sort(arr.begin(), arr.end(), myCompare);

	// 출력
	for (auto e : arr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	vector<Student> brr;
	brr.push_back(Student("Kim", 10));
	brr.push_back(Student("Lee", 8));
	brr.push_back(Student("Park", 12));
	brr.push_back(Student("Song", 11));

	for (auto e : brr)
	{
		cout << e << endl;
	}
	
	cout << "-------------------------" << endl;

	// 이름 내림차순으로 정렬하기
	Student::compareMode = Student::Mode::COMP_NAME_DESC;
	sort(brr.begin(), brr.end(), Student::compare);

	for (auto e : brr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	// 번호 내림차순으로 정렬하기
	Student::compareMode = Student::Mode::COMP_NUM_DESC;
	sort(brr.begin(), brr.end(), Student::compare);

	for (auto e : brr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	// list는 vector와 쓰는 방법이 다르다. 구현한 구조 자체가 다르기 때문
	list<Student> Slist;
	Slist.push_back(Student("Kim", 5));
	Slist.push_back(Student("Lee", 3));
	Slist.push_back(Student("Park", 7));
	Slist.push_back(Student("Song", 1));

	Student::compareMode = Student::Mode::COMP_NUM;
	Slist.sort(Student::compare); // list는 sort가 맴버 함수로 존재

	for (auto e : Slist)
	{
		cout << e << endl;
	}

	return 0;
}