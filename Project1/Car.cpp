
#include "Car.h"

Car::Car() {
  name = "None";
  model = "None";
  plate = "None";
  vip = false;

}

Car::Car(string name, string model, string plate, bool vip) {
  this->name = name;
  this->model = model;
  this->plate = plate;
  this->vip = vip;

}

Car::Car(const Car& vehicle)
{
	name = vehicle.name;
	model = vehicle.model;
	plate = vehicle.plate;
	vip = vehicle.vip;
}

void Car::operator=(Car &rhs)
{
	name = rhs.name;
	model = rhs.model;
	plate = rhs.plate;
	vip = rhs.vip;
}

void Car::operator=(Car&& rhs)
{
	name = rhs.name;
	model = rhs.model;
	plate = rhs.plate;
	vip = rhs.vip;
}

bool Car::operator==(Car rhs)
{
	if (name == rhs.name && model == rhs.model && plate == rhs.plate) {
		return true;
	}
	else {
		return false;
	}
}

void Car::print()
{
	cout << name << endl;
	cout << model << "\t\t" << plate << endl << endl;
}

