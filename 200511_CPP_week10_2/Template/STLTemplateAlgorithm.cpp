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

	static enum Mode { COMP_NUM, COMP_NAME, COMP_NUM_DESC, COMP_NAME_DESC }; // �������� �̿��ؼ� �� ��Ȯ�ϰ� ǥ���� �� ����
	static Mode compareMode;
	static bool compare(const Student& a, const Student& b); // ������ ��븸 �� ���� const ���̸� ��. ��� �Ⱥپ ����
};

Student::Mode Student::compareMode = Mode::COMP_NUM;

ostream& operator<<(ostream& o, const Student& in)
{
	cout << "Num : " << in.num << " Name : " << in.name;
	return o;
}

// Student ��ü�� �����ϱ� ���� static �Լ� >> bool �� ��ȯ
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

// ������������ �����ϱ� ���� �Լ� >> bool �� ��ȯ
bool myCompare(const int& a, const int& b)
{
	// return (a < b) // ���� ������
	if (a > b) return true;
	return false;
}

int main()
{
	vector<int> arr; // ���� �迭 ����(���ø�)

	// ������ �� ���� �� �迭�� �ֱ�
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
	}

	// ���
	for (auto e : arr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	// �����ϱ�(��������)
	sort(arr.begin(), arr.end(), myCompare);

	// ���
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

	// �̸� ������������ �����ϱ�
	Student::compareMode = Student::Mode::COMP_NAME_DESC;
	sort(brr.begin(), brr.end(), Student::compare);

	for (auto e : brr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	// ��ȣ ������������ �����ϱ�
	Student::compareMode = Student::Mode::COMP_NUM_DESC;
	sort(brr.begin(), brr.end(), Student::compare);

	for (auto e : brr)
	{
		cout << e << endl;
	}

	cout << "-------------------------" << endl;

	// list�� vector�� ���� ����� �ٸ���. ������ ���� ��ü�� �ٸ��� ����
	list<Student> Slist;
	Slist.push_back(Student("Kim", 5));
	Slist.push_back(Student("Lee", 3));
	Slist.push_back(Student("Park", 7));
	Slist.push_back(Student("Song", 1));

	Student::compareMode = Student::Mode::COMP_NUM;
	Slist.sort(Student::compare); // list�� sort�� �ɹ� �Լ��� ����

	for (auto e : Slist)
	{
		cout << e << endl;
	}

	return 0;
}