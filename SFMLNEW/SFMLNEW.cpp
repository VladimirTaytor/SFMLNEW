// SFMLNEW.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
using namespace sf;

void addNew();
void show();
void task();


int first[2];
int second[2];
int third[2];

int main()
{
	int menu;
	cout << "1 - new triangle; \n2 - show; \n3 - task; \n4 - exit; \n";
	while (true) {
		cout << "You are in main menu: ";
		cin >> menu;

		switch (menu) {
		case 1:
			addNew();
			cout << "Added\n";
			break;
		case 2:
			show();
			break;
		case 3:
			task();
			break;
		case 4: 
			cout << "Ended!";
			return 0;
			break;
		}
	}
}

void show() {
	RenderWindow window(VideoMode(640, 480), "Triangle is alive");

	ConvexShape convex;
	convex.setPointCount(3);
	convex.setFillColor(Color::Blue);
	convex.setPoint(0, Vector2f(first[0], first[1]));
	convex.setPoint(1, Vector2f(second[0], second[1]));
	convex.setPoint(2, Vector2f(third[0], third[1]));

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(convex);
		window.display();
	}
}

void addNew() {
	cout << "Enter new coordinates (x y)\n";
	cout << " first point : ";
	cin >> first[0] >> first[1];
	cout << "second point : ";
	cin >> second[0] >> second[1];
	cout << " third point : ";
	cin >> third[0]>>third[1];
}

void task() {
	if (first[0] != 0) {
		double f_side;
		double s_side;
		double t_side;
		int menu;
		double perimetr;
		double square;
		cout << "\n 1 - perimeter; \n 2 - square; \n";
		cin >> menu;
		f_side = sqrt(pow(first[1] - first[0], 2) + pow(second[1] - second[0], 2));
		s_side = sqrt(pow(second[1] - second[0], 2) + pow(third[1] - third[0], 2));
		t_side = sqrt(pow(first[1] - first[0], 2) + pow(third[1] - third[0], 2));
		perimetr = (f_side + s_side + t_side);
		double p_perimetr = perimetr / 2;
		square = sqrt(p_perimetr*(p_perimetr - f_side)*(p_perimetr-s_side)*(p_perimetr-t_side));
			switch(menu) {
		case 1:
			cout << "Perimeter = " << perimetr<<endl;
			break;
		case 2:
			cout << "Square = " << square<<endl;
			break;
			}
		
	}
	else cout << "Please create new triangle first.\n";
}