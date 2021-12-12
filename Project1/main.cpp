#include <iostream>
#include "Aeroflot.h"
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("file.txt");
	setlocale(LC_ALL, "rus");
	string File;
	int k = 0;
	int k1 = -1, k2 = 0, k3 = 0;
	int n1 = 0;
	int c = 0;
	int c1 = 0;
	string t1;
	string d1, d2;
	Aeroflot* A = nullptr;
	Aeroflot sravn;
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
				if (k2 > c || k2 <= 0)
				{
					cout << "��������� ������, ��� �������� ����� ��� ��� ����� �� ������\n";
				}
				else
				{
					k2--;
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
				if (k2 > c || k2 <= 0)
				{
					cout << "��������� ������, ��� �������� ����� ��� ����� ��������\n";
				}
				else
				{
					k2--;
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
				for (int i = 0; i < c; i++)
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
					cout << A[i];
				}
				break;
			default:
				break;
			}
			for (int i = 0; i < c - 1; i++)
			{
				for (int j = 0; j < c - i - 1; j++)
				{
					if (A[j].getFlight_Number() > A[j + 1].getFlight_Number())
					{
						sravn = A[j];
						A[j] = A[j + 1];
						A[j + 1] = sravn;
					}
				}
			}
		}
		catch (exception s)
		{
			cout << s.what() << endl;
		}
	}
	delete[]A;
	try {
		if (!fin.is_open())
		{
			throw exception("���� �� ������");
		}
		while (!fin.eof())
		{
			fin >> File;
			if (File[0] == 'a' || File[0] == 'e' || File[0] == 'i' || File[0] == 'o' || File[0] == 'u' || File[0] == 'y')
			{
				cout << File << " ";
			}
		}
		cout << endl;
	}
	catch (exception s) {
		cout << s.what() << endl;
	}
	fin.close();
	return 0;
}