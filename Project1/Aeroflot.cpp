#include "Aeroflot.h"

Aeroflot::Aeroflot(string d1, int n1, string t1) {
	if (n1 < 0)
	{
		throw exception("�������� ����� �����");
	}
	Destination = d1;
	flight_Number = n1;
	aircraft_Type = t1;
	cout << "������ ����� Aeroflot, ����������� � �����������\n";
}

Aeroflot::Aeroflot() {
	Destination = "";
	flight_Number = 0;
	aircraft_Type = "";
	cout << "������ ����� Aeroflot, ����������� ��� ����������\n";
}

Aeroflot::Aeroflot(const Aeroflot& A1) {
	Destination = A1.Destination;
	flight_Number = A1.flight_Number;
	aircraft_Type = A1.aircraft_Type;
	cout << "������ ����� Aeroflot, ����������� �����������\n";
}

Aeroflot::~Aeroflot() {
	Destination = "";
	flight_Number = 0;
	aircraft_Type = "";
	cout << "������ ����� Aeroflot, ����������\n";
}

void Aeroflot::setDestination(string d1) {
	Destination = d1;
}

string Aeroflot::getDestination() {
	return Destination;
}

void Aeroflot::setFlight_Number(int n1) {
	if (n1 < 0)
	{
		throw exception("�������� ����� �����");
	}
	flight_Number = n1;
}

int Aeroflot::getFlight_Number() {
	return flight_Number;
}

void Aeroflot::setAircraft_Type(string t1) {
	aircraft_Type = t1;
}

string Aeroflot::getAircraft_Type() {
	return aircraft_Type;
}

ostream& operator<<(ostream &out, const Aeroflot &aeroflot) {
	out << "����, ������� ������� �: " << aeroflot.Destination << ", ����� �����: " << aeroflot.flight_Number << ", ��� �������: " << aeroflot.aircraft_Type << "\n";
	return out;
}

istream& operator>>(istream &in, Aeroflot &aeroflot) {
	in >> aeroflot.Destination;
	in >> aeroflot.flight_Number;
	if (aeroflot.flight_Number < 0)
	{
		aeroflot.flight_Number = 0;
		throw exception("�������� ����� �����");
	}
	in >> aeroflot.aircraft_Type;
	return in;
}