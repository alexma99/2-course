#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle() {
	side_a = 0.0;
	side_b = 0.0;
	side_c = 0.0;
}

Triangle::Triangle(std::istream &is) { 
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
	std::cout << "Введите значение c:";
	while (!(is >> side_c)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение c";
	}
}

double Triangle::Square() {
	std::cout << "Площадь = ";
	double p= double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

void Triangle::Print() {
	std::cout << "Сторона a=" << side_a << ", Сторона b=" << side_b << ", Сторона c=" << side_c << std::endl;
}

Triangle::~Triangle() {
	std::cout << "Triangle deleted" << std::endl;
}
