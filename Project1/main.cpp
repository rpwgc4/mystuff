#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Queue.h"

Queue new_cars;
Queue old_cars;
Queue lux_cars;


// Custom functions to help transition between char arrays and strings 
string convert_char(char arr[], int size) {
	string result = "";
	for (int i = 0; i < size; i++) {
		result += arr[i];
	}
	return result;
}

char * convert_string(string s) {
	char * result = new char[s.length() + 1];
	strcpy(result, s.c_str());
	return result;
}

#define PRESS_BUTTON 1

HWND textBox;

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
void AddControls1(HWND hwnd);
void AddControls2(HWND hwnd, string exhibitionTitle);

int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, PSTR cmdLine, INT cmdCount) {
	const char * CLASS_NAME = "myWindow";
	WNDCLASS wc{};
	wc.hInstance = currentInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcessMessages;
	RegisterClass(&wc);
	CreateWindow(CLASS_NAME, "Welcome to the Marketplace!", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 425, 400, nullptr, nullptr, nullptr, nullptr);

	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

int menu = 0;

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE:
		AddControls1(hwnd);
		break;
	case WM_COMMAND:
		switch (wp) {
		case PRESS_BUTTON:
			char text[2];
			GetWindowText(textBox, text, 2);
			int choice;
			try {
				choice = atoi(text);
			}
			catch (exception& e) {
				choice = 0;
			}
			switch (menu) {
			case 0:
				switch (choice) {
				case 1:
					AddControls2(hwnd, "New Cars");
					menu = 1;
					break;
				case 2:
					AddControls2(hwnd, "Old Cars");
					menu = 2;
					break;
				case 3:
					AddControls2(hwnd, "Luxury Cars");
					menu = 3;
					break;
				case 4:
					PostQuitMessage(0);
					break;
				default:
					::MessageBox(hwnd, "Please enter one of the numbered options.", "Notification", MB_OK);
					break;
				}
				break;
			case 1:
				switch (choice) {
				case 1:
					::MessageBox(hwnd, "Branch 1", "Hello", MB_OK);
					break;
				case 2:
					::MessageBox(hwnd, "Branch 2", "Hello", MB_OK);
					break;
				case 3:
					::MessageBox(hwnd, "Branch 3", "Hello", MB_OK);
					break;
				case 4:
					::MessageBox(hwnd, "Branch 4", "Hello", MB_OK);
					break;
				case 5:
					::MessageBox(hwnd, "Branch 5", "Hello", MB_OK);
					break;
				case 6:
					AddControls1(hwnd);
					menu = 0;
					break;
				default:
					::MessageBox(hwnd, "Please enter one of the numbered options.", "Notification", MB_OK);
					break;
				}
				break;
			case 2:
				switch (choice) {
				case 1:
					::MessageBox(hwnd, "Branch 1", "Hello", MB_OK);
					break;
				case 2:
					::MessageBox(hwnd, "Branch 2", "Hello", MB_OK);
					break;
				case 3:
					::MessageBox(hwnd, "Branch 3", "Hello", MB_OK);
					break;
				case 4:
					::MessageBox(hwnd, "Branch 4", "Hello", MB_OK);
					break;
				case 5:
					::MessageBox(hwnd, "Branch 5", "Hello", MB_OK);
					break;
				case 6:
					AddControls1(hwnd);
					menu = 0;
					break;
				default:
					::MessageBox(hwnd, "Please enter one of the numbered options.", "Notification", MB_OK);
					break;
				}
				break;
			case 3:
				switch (choice) {
				case 1:
					::MessageBox(hwnd, "Branch 1", "Hello", MB_OK);
					break;
				case 2:
					::MessageBox(hwnd, "Branch 2", "Hello", MB_OK);
					break;
				case 3:
					::MessageBox(hwnd, "Branch 3", "Hello", MB_OK);
					break;
				case 4:
					::MessageBox(hwnd, "Branch 4", "Hello", MB_OK);
					break;
				case 5:
					::MessageBox(hwnd, "Branch 5", "Hello", MB_OK);
					break;
				case 6:
					AddControls1(hwnd);
					menu = 0;
					break;
				default:
					::MessageBox(hwnd, "Please enter one of the numbered options.", "Notification", MB_OK);
					break;
				break;
				}
			}
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	

	default:
		return DefWindowProc(hwnd, msg, wp, lp);
	}
}


void AddControls1(HWND hwnd) {
	CreateWindow("Static", "", WS_VISIBLE | WS_CHILD, 0, 0, 425, 400, hwnd, nullptr, nullptr, nullptr);
	CreateWindow("Static", "Welcome to Mercedes\nPlease make a selection:", WS_VISIBLE | WS_CHILD, 100, 50, 250, 30, hwnd, nullptr, nullptr, nullptr);
	CreateWindow("Static", "1. Fast cars\n2. Old cars\n3. Luxury cars\n4. Exit", WS_VISIBLE | WS_CHILD, 100, 90, 250, 80, hwnd, nullptr, nullptr, nullptr);
	textBox = CreateWindow("Edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 100, 170, 200, 30, hwnd, nullptr, nullptr, nullptr);
	CreateWindow("Button", "Enter", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 250, 100, 30, hwnd, (HMENU) PRESS_BUTTON, nullptr, nullptr);
}

void AddControls2(HWND hwnd, string exhibitionTitle) {
	CreateWindow("Static", "", WS_VISIBLE | WS_CHILD, 0, 0, 425, 400, hwnd, nullptr, nullptr, nullptr);
	string header = "Welcome to Exhibition- " + exhibitionTitle + "\nPlease make a selection : ";
	CreateWindow("Static", convert_string(header), WS_VISIBLE | WS_CHILD, 100, 50, 250, 30, hwnd, nullptr, nullptr, nullptr);
	CreateWindow("Static", "1. Add car\n2. Add VIP cars\n3. Take car to auction\n4. Cancel car\n5. List cars in queue\n6. Exit", WS_VISIBLE | WS_CHILD, 100, 90, 250, 150, hwnd, nullptr, nullptr, nullptr);
	textBox = CreateWindow("Edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 100, 200, 200, 30, hwnd, nullptr, nullptr, nullptr);
	CreateWindow("Button", "Enter", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 250, 100, 30, hwnd, (HMENU) PRESS_BUTTON, nullptr, nullptr);
}

