#include "Aeroflot.h"

Aeroflot::Aeroflot(string d1, int n1, string t1) {
	if (n1 < 0)
	{
		throw exception("Неверный номер рейса");
	}
	Destination = d1;
	flight_Number = n1;
	aircraft_Type = t1;
	cout << "Вызван класс Aeroflot, конструктор с параметрами\n";
}

Aeroflot::Aeroflot() {
	Destination = "";
	flight_Number = 0;
	aircraft_Type = "";
	cout << "Вызван класс Aeroflot, конструктор без параметров\n";
}

Aeroflot::Aeroflot(const Aeroflot& A1) {
	Destination = A1.Destination;
	flight_Number = A1.flight_Number;
	aircraft_Type = A1.aircraft_Type;
	cout << "Вызван класс Aeroflot, конструктор копирования\n";
}

Aeroflot::~Aeroflot() {
	Destination = "";
	flight_Number = 0;
	aircraft_Type = "";
	cout << "Вызван класс Aeroflot, деструктор\n";
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
		throw exception("Неверный номер рейса");
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
	out << "Рейс, который следует в: " << aeroflot.Destination << ", номер рейса: " << aeroflot.flight_Number << ", тип самолёта: " << aeroflot.aircraft_Type << "\n";
	return out;
}

istream& operator>>(istream &in, Aeroflot &aeroflot) {
	in >> aeroflot.Destination;
	in >> aeroflot.flight_Number;
	if (aeroflot.flight_Number < 0)
	{
		aeroflot.flight_Number = 0;
		throw exception("Неверный номер рейса");
	}
	in >> aeroflot.aircraft_Type;
	return in;
}