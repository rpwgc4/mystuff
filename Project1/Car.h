#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car {
  public:
	Car();
	Car(string name, string model, string plate, bool vip);
	Car(const Car& vehicle);

	void operator=(Car &rhs);
	void operator=(Car &&rhs);
	bool operator==(Car rhs);

	string get_name() { return name; }
	string get_model() { return model; }
	string get_plate() { return plate; }
	bool isVIP() { return vip; }

	void print();

	Car* next;

  private:
	string name;
	string model;
	string plate;
	bool vip;

};