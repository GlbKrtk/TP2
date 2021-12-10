#include <iostream>
#include "Aeroflot.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int k = 0;
	int k1 = -1, k2 = 0, k3 = 0;
	int n1 = 0;
	int c = 0;
	int c1 = 0;
	string t1;
	string d1, d2;
	Aeroflot* A = nullptr; //= new Aeroflot[k] ����������� ������� �����������, �� �������� ����������
	Aeroflot* sravn = new Aeroflot[k];
	//for (int i = 0; i < k; i++)
	//{
	//	for (int j = 0; j < k-i; j++)
	//	{
	//		if (A[i].getFlight_Number() < A[i + 1].getFlight_Number())
	//		{
	//			sravn[i] = A[i];
	//			A[i] = A[i + 1];
	//			A[i + 1] = sravn[i];
	//		}
	//	}
	//}
	//cout << "������� ����� ���������� ��� ������ ������\n";
	//cin >> d1;
	//for (int i = 0; i < k; i++)
	//{
	//	if (d1 == A[i].getDestination())
	//	{
	//		cout << "����� �����: " << A[i].getFlight_Number() << ", ��� �������: " << A[i].getAircraft_Type() << endl;
	//	}
	//	else
	//	{
	//		cout << "����� ������ ���\n";
	//	}
	//}
	cout << "1 - �������������\n2 - �������\n3 - ��������\n4 - ����� �� ����� ������� ������ � ����� ���������, ���������� � ����� ����������, �������� �������� ������� � ���������, ��������� � ����������\n5 - �����\n0-����� �� ���������\n";
	while (k1 != 0)
	{
		try {
			if (cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			cin >> k1;
			switch (k1)
			{
			case 1:
				cout << "�������� ����� �������, �������� �������� �� ������ ��������\n";
				cin >> k2;
				if (k2 > c)
				{
					cout << "��������� ������, ��� �������� �����\n";
				}
				else
				{
					cout << "����� �������� �� ������ ��������? 1 - �������� ����� ����������, 2 - �������� ����� �����, 3 - �������� ��� �������\n";
					cin >> k3;
					if (k3 == 1)
					{
						cout << "������� ����� �������� ���������, ������� �� ������ ��������\n";
						cin >> d2;
						A[k2].setDestination(d2);
					}
					else if (k3 == 2)
					{
						cout << "������� ����� �������� ���������, ������� �� ������ ��������\n";
						cin >> n1;
						A[k2].setFlight_Number(n1);
					}
					else if (k3 == 3)
					{
						cout << "������� ����� �������� ���������, ������� �� ������ ��������\n";
						cin >> t1;
						A[k2].setAircraft_Type(t1);
					}
					else
					{
						cout << "������, ����������� � ����\n";
					}
				}
				break;
			case 2:
				cout << "������� ����� �������, ������� ������ �������\n";
				cin >> k2;
				k2--;
				if (k2 >= c)
				{
					cout << "��������� ������, ��� �������� �����\n";
				}
				else
				{
					c--;
					A[k2] = A[c];
					A[c].setAircraft_Type("");
					A[c].setDestination("");
					A[c].setFlight_Number(0);
					cout << "������� �����" << endl;
				}
				break;
			case 3:
				if (c == 0)
				{
					A = new Aeroflot[1];
				}
				else
				{
					Aeroflot* A1 = new Aeroflot[c + 1];
					for (int i = 0; i < c; i++)
					{
						A1[i] = A[i];
					}
					delete[]A;
					A = A1;
				}
				Aeroflot* N1;
				cout << "������� ����� ����������: " << endl;
				cin >> d2;
				cout << "������� ����� �����: " << endl;
				cin >> n1;
				cout << "������� ��� �������: " << endl;
				cin >> t1;
				N1 = new Aeroflot(d2, n1, t1);
				A[c] = *N1;
				c++;
				break;
			case 4:
				cout << "������� ����� ���������� ��� ������ ������\n";
				cin >> d1;
				for (int i = 0; i < k; i++)
				{
					if (d1 == A[i].getDestination())
					{
						cout << "����� �����: " << A[i].getFlight_Number() << ", ��� �������: " << A[i].getAircraft_Type() << endl;
						c1++;
					}
					else
					{
						cout << "";
					}
				}
				if (c1 == 0)
				{
					cout << "����� ������ ���" << endl;
				}
				c1 = 0;
				break;
			case 5:
				if (c == 0)
				{
					cout << "������ ����" << endl;
				}
				for (int i = 0; i < c; i++)
				{
					cout << A[i] << endl;
				}
				break;
			default:
				break;
			}
			for (int i = 0; i < k - 1; i++)
			{
				for (int j = 0; j < k - i - 1; j++)
				{
					if (A[i].getFlight_Number() < A[i + 1].getFlight_Number())
					{
						sravn[i] = A[i];
						A[i] = A[i + 1];
						A[i + 1] = sravn[i];
					}
				}
			}
		}
		catch (exception s)
		{
			cout << s.what() << endl;
		}
	}
	return 0;
}