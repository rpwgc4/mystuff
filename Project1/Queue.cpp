#pragma once
#include "Queue.h"

Queue::Queue() {
  count = 0;
  vip_count = 0;
  front = NULL;
  back = NULL;
}

Car Queue::pop()
{
	if (front == NULL) {
		cout << "\nNo cars in queue to be removed.\n";
		return Car();
	}
	else {
		Car temp;
		temp = *front;
		front = front->next;
		count--;
		if (temp.isVIP()) {
			vip_count--;
		}
		return temp;
	}
}

int Queue::find(Car vehicle)
{
	Car *current = front;
	for (int i = 1; i <= count; i++) {
		if (*current == vehicle) {
			return i;
		}
		current = current->next;
	}
	cout << "\nCar not found in queue\n";
	return 0;
}

void Queue::add(Car &vehicle){
	if (count > 99) {
		cout << "Too many cars in queue, could not add" << endl;
	}
	else {
		if (!vehicle.isVIP()) {
			if (count == 0) {
				front = &vehicle;
				back = &vehicle;
			}
			else {
				back->next = &vehicle;
				back = &vehicle;
			}
		}
		else {
			if (vip_count == 0) {
				vehicle.next = front;
				front = &vehicle;
			}
			else {
				Car *current = front;
				for (int i = 1; i < vip_count; i++) {
					current = current->next;
				}
				vehicle.next = current->next;
				current->next = &vehicle;
			}
			if (vehicle.next == NULL) {
				back = &vehicle;
			}
			vip_count++;
		}
		count++;
	}
}

void Queue::cancel(int idx)
{
	Car * current;
	Car * temp;

	if (count == 0) {
		cout << "No cars in queue to be removed.\n";
	}
	else if (idx == 0) {
		cout << "Could not remove specified car\n";
	}
	else {
		//
		current = front;
		if (idx == 1) {
			front = current->next;
			erase(current);
			if (count == 0) {
				back = NULL;
			}
		}
		else {
			for (int i = 1; i < idx-1; i++) {
				current = current->next;
			}
			temp = current->next;
			if (idx == count) {
				back = current;
				current->next = NULL;
				erase(temp);
			}
			else {
				current->next = temp->next;
				erase(temp);
			}
		}
	}
}

void print_queue(Car *current, int num = 1) {
	cout << num << ")\t";
	current->print();
	if (current->next != NULL) {
		print_queue(current->next, num+1);
	}
}

void Queue::print() {
	if (count > 0) {
		print_queue(front);
	}
	else {
		cout << "No items in queue" << endl;
	}
}

void Queue::erase(Car * vehicle)
{
	count--;
	if (vehicle->isVIP()) {
		vip_count--;
	}
	//delete vehicle;
}
