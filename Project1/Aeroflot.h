#pragma once
#include <iostream>
#include <string>

using namespace std;

class Aeroflot {
public:
	void setDestination(string);
	string getDestination();
	void setFlight_Number(int);
	int getFlight_Number();
	void setAircraft_Type(string);
	string getAircraft_Type();
	Aeroflot(string, int, string);
	Aeroflot();
	Aeroflot(const Aeroflot&);
	~Aeroflot();
private:
	string Destination;
	int flight_Number;
	string aircraft_Type;
};