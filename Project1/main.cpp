#include <iostream>
#include "Aeroflot.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int k = 0;
	int k1 = 0;
	string d1;
	cout << "������� ����� �������� ������ Aeroflot\n";
	cin >> k;
	Aeroflot* A = new Aeroflot[k];
	Aeroflot* sravn = new Aeroflot[k];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k-i; j++)
		{
			if (A[i].getFlight_Number() < A[i + 1].getFlight_Number())
			{
				sravn[i] = A[i];
				A[i] = A[i + 1];
				A[i + 1] = sravn[i];
			}
		}
	}
	cout << "������� ����� ���������� ��� ������ ������\n";
	cin >> d1;
	for (int i = 0; i < k; i++)
	{
		if (d1 == A[i].getDestination())
		{
			cout << "����� �����: " << A[i].getFlight_Number() << ", ��� �������: " << A[i].getAircraft_Type() << endl;
		}
		else
		{
			cout << "����� ������ ���\n";
		}
	}

}