// ������� ����� �� ������ Distance � ����� � ������� 
#include <iostream>
#include <windows.h>
using namespace std;

class Distance	// ����� ���������� ��� �����
{
private:
	const float MTF;     // ����������� �������� ������ � ����
	int feet;
	float inches;

public:
	// ����������� ��� ����������
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { cout << "\n����������� �� ���������\n"; }
	// ����������� � ����� ����������, ����������� ����� � ���� � ����� 
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;      // ��������� � ����
		feet = int(fltfeet);				// ����� ����� ������ �����
		inches = 12 * (fltfeet - feet);		 // ������� - ��� �����
		cout << "\n����������� � ����� ����������\n";
	}
	// ����������� � ����� �����������
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }
	// ��������� ���������� �� ������������
	void getdist()
	{
		cout << "\n������� ����: "; cin >> feet;
		cout << "������� �����: ";  cin >> inches;
	}
	// ����� ���������� 
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}
	// �������� �������� ��� ��������� ������ �� �����

	Distance operator+ (Distance) const;

	/*explicit*/  operator float() const
	{
		float fracfeet = inches / 12;	// ��������� ����� � ����
		fracfeet += static_cast<float>(feet); // ��������� ����� ����
		return fracfeet / MTF;	// ��������� � �����

	}

	// ������������� �������� ������������

	Distance operator=(Distance d) {
		this->feet = d.feet;
		this->inches = d.inches;

		return *this;
	}


};

Distance Distance::operator+ (Distance d2) const
{
	int f = feet + d2.feet;	// ���������� ����
	float i = inches + d2.inches; // ���������� �����
	if (i >= 12.0)	// ���� ������ ����� ������ 12
	{
		i -= 12.0;	// �� ��������� ����� �� 12
		f++;	// � ����������� ���� �� 1
	}
	return Distance(f, i);      // ������� � ���������� ��������� ����������



}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	float mtrs;
	Distance dist1 = 2.35F; // ������������ �����������, ����������� ����� � ���� � �����

	Distance dist101; // �������� �������������!!!
	cout << "\ndist101 = ";
	dist101.showdist();
	//dist101 = 2.22F;  // �������� ������������!!! ������� ���������� ��������� ������������, ��� ��� ��������� ��������� � �� ����� �������� ����������� ������

	cout << "\ndist1 = ";
	dist1.showdist();

	cout << "\ndist101 = ";
	dist101.showdist();
	mtrs = static_cast<float>(dist1); // ���������� �������� �������� � �����
	cout << "\ndist1 = " << mtrs << " meters\n";
	Distance dist2(5, 10.25); // ���������� ����������� � ����� �����������

	mtrs = dist2; // ������ ���������� ������� ���� 
	cout << "\ndist2 = " << mtrs << " meters\n";

	//dist2 = mtrs; 
	cout << "\ndist2 = " << mtrs << " meters\n";
	Distance dist11 = dist1 + dist2;

	// ������������� �������� ������������
	Distance dist3;
	dist3 = dist2;
	cout << "\ndist2= ";
	dist2.showdist();
	cout << "\ndist3= ";
	dist3.showdist();
	return 0;
}
