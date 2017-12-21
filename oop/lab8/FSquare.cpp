#include "FSquare.h"
#include <cmath>
#include <iostream>

FSquare::FSquare() {
	side_a = 0.0;
}

FSquare::FSquare(size_t i) : side_a(i) {
	//	std::cout << "Создан квадрат со сторонами: " << side_a << std::endl;
}

FSquare::FSquare(std::istream& is) {
	std::cout << "Введите значение a:";
	while (!(is >> side_a)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение a:";
	}
}

FSquare::FSquare(const FSquare &orig) {
	side_a = orig.side_a;
}

FSquare& FSquare::operator=(const FSquare& right) {
	if (this == &right)
		return *this;
	side_a = right.side_a;
	return *this;
}

bool FSquare::operator == (const FSquare& other)
{
	return side_a == other.side_a;
}

FSquare& FSquare::operator++() {
	side_a++;
	return *this;
}

//FSquare operator+(const FSquare& left, const FSquare& right) {
//	return FSquare(left.side_a + right.side_a);
//}

std::ostream& operator<<(std::ostream& os, const FSquare& obj) {
	os << "Квадрат со стороной ";
	os << "[" << obj.side_a << "], Площадь = " << obj.Square() << std::endl;
	return os;
}
std::istream& operator>>(std::istream& is, FSquare& obj) {
	std::cout << "Введите значение a:";
	while (!(is >> obj.side_a)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение a:";
	}
	return is;
}

double FSquare::Square() const {
	return pow(side_a, 2);
}

void FSquare::print(std::ostream & os) const
{
	os << *this;
}

//void FSquare::Print() {
//	std::cout << "Квадрат со стороной ";
//	std::cout << "[" << side_a << "], Площадь = " << this->Square() << std::endl;
//}

FSquare::~FSquare() {

}
