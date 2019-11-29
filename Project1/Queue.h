
#include "Car.h"

class Queue {
  public:

	Queue();
	int size() { return count;}
	Car* get_top() { return front; }
	Car pop();
	int find(Car vehicle);
	void add(Car &vehicle);
	void cancel(int idx);
	void print();

private:
	void erase(Car *vehicle);
	Car* front;
	Car* back;
	int count;
	int vip_count;
	
};