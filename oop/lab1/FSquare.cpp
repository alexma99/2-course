#include "FSquare.h"
#include <cmath>
#include <iostream>

FSquare::FSquare() {
	side_a = 0.0;
}

FSquare::FSquare(std::istream &is) {
	std::cout << "Введите значение a:";
	while (!(is >> side_a)) {
		std::cout << "Неверный ввод" << std::endl;
		is.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите значение a:";
	}
}

double FSquare::Square() {
	std::cout << "Площадь = ";
	return pow(side_a,2);
}

void FSquare::Print() {
	std::cout << "Сторона a=" << side_a << std::endl;
}

FSquare::~FSquare() {
	std::cout << "FSquare deleted" << std::endl;
}
