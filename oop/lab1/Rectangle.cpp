#include "Rectangle.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle() {
	side_a = 0.0;
	side_b = 0.0;
}

Rectangle::Rectangle(std::istream& is) {
	std::cout << "Введите значение a:";
	while (!(is >> side_a)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение a:";
	}
	std::cout << "Введите значение b:";
	while (!(is >> side_b)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение b:";
	}
}

double Rectangle::Square() {
	std::cout << "Площадь = ";

	return side_a*side_b;
}

void Rectangle::Print() {
	std::cout << "Сторона a=" << side_a << ", Сторона b=" << side_b << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle deleted" << std::endl;
}
