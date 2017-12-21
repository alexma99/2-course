#include "Triangle.h"
#include <iostream>
#include <cmath> 
Triangle::Triangle() : Triangle(0, 0, 0) {
}

Triangle::Triangle(double i, double j, double k) : side_a(i), side_b(j), side_c(k) {
	//	std::cout << "Создан треугольник со сторонами: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(std::istream& is) {
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

Triangle::Triangle(const Triangle &orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

double Triangle::Square() {
	std::cout << "Площадь = ";
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

void Triangle::Print() {
	std::cout << "Треугольник со сторонами ";
	std::cout << "[" << side_a << "," << side_b << "," << side_c << "]" << std::endl;
}

Triangle& Triangle::operator=(const Triangle& right) {
	if (this == &right)
		return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	side_c = right.side_c;
	return *this;
}

bool Triangle::operator == (const Triangle& other)
{
	return side_a == other.side_a && side_b == other.side_b && side_c == other.side_c;
}

Triangle& Triangle::operator++() {
	side_a++;
	side_b++;
	side_c++;
	return *this;
}

Triangle operator+(const Triangle& left, const Triangle& right) {
	return Triangle(left.side_a + right.side_a, left.side_b + right.side_b, left.side_c + right.side_c);
}

std::ostream& operator<<(std::ostream& os, const Triangle& obj) {
	os << "Треугольник со сторонами ";
	os << "[" << obj.side_a << "," << obj.side_b << "," << obj.side_c << "]" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Triangle& obj) {
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
	std::cout << "Введите значение c:";
	while (!(is >> obj.side_c)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение c";
	}
	return is;
}

Triangle::~Triangle() {

}
