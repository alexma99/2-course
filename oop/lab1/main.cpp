#include <cstdlib>
#include <iostream>
#include "Triangle.h"
#include "FSquare.h"
#include "Rectangle.h"


void func(Figure* ptr) {
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	std::cout << "------------------------------------------"<< std::endl;
	std::cout << "-------------------МЕНЮ-------------------"<< std::endl;
	std::cout << "|Выбирите действие:                      |" << std::endl;
	std::cout << "|1-Вычислить площадь треугольника        |" << std::endl;
	std::cout << "|2-Вычислить площадь квадрата            |" << std::endl;
	std::cout << "|3-Вычислить площадь прямоугольника      |" << std::endl;
	std::cout << "|4-Выход                                 |" << std::endl;
	do {
		if (!(std::cin >> a)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		switch (a) {
		case 1:func(new Triangle(std::cin));break;
		case 2:func(new FSquare(std::cin));break;
		case 3:func(new Rectangle(std::cin));break;
		case 4:break;
		default: std::cout << "Неверный ввод. Попробуйте снова" << std::endl;
			break;
		}
	} while (a != 4);
	return 0;
}
