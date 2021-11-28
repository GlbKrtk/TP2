#include "Aeroflot.h"

Aeroflot::Aeroflot(string d1, int n1, string t1) {
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