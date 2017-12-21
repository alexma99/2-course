#include "Rectangle.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle() {
	side_a = 0.0;
	side_b = 0.0;
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
	//	std::cout << "Создан прямоугольник со сторонами: " << side_a << ", " << side_b << std::endl;
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

Rectangle::Rectangle(const Rectangle &orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
}

Rectangle& Rectangle::operator=(const Rectangle& right) {
	if (this == &right)
		return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	return *this;
}

bool Rectangle::operator == (const Rectangle& other)
{
	return side_a == other.side_a && side_b == other.side_b;
}

Rectangle& Rectangle::operator++() {
	side_a++;
	side_b++;
	return *this;
}

Rectangle operator+(const Rectangle& left, const Rectangle& right) {
	return Rectangle(left.side_a + right.side_a, left.side_b + right.side_b);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
	os << "Прямоугольник со сторонами ";
	os << "[" << obj.side_a << "," << obj.side_b << "]" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
	std::cout << "Введите значение a:";
	while (!(is >> obj.side_a)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение a:";
	}
	std::cout << "Введите значение b:";
	while (!(is >> obj.side_b)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение b:";
	}
	return is;
}

double Rectangle::Square() {
	std::cout << "Площадь = ";
	return side_a*side_b;
}

void Rectangle::Print() {
	std::cout << "Прямоугольник со сторонами ";
	std::cout << "[" << side_a << "," << side_b << "]" << std::endl;
}

//Rectangle::~Rectangle() {
//
//}
