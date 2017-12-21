#include <cstdlib>
#include <iostream>
#include "TList.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "FSquare.h"
#include <memory>



int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	TList list;
	std::shared_ptr<Figure> in, del;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "-------------------МЕНЮ-------------------" << std::endl;
	std::cout << "|1-Добавить треугольник                  |" << std::endl;
	std::cout << "|2-Добавить прямоугольник                |" << std::endl;
	std::cout << "|3-Добавить квадрат                      |" << std::endl;
	std::cout << "|4-Удалить фигуру                        |" << std::endl;
	std::cout << "|5-Расспечатать список                   |" << std::endl;
	std::cout << "|6-Выход                                 |" << std::endl;
	do {
		std::cout << "Выберете действие:" << std::endl;
		if (!(std::cin >> a)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		switch (a) {
		case 1: {
			in = std::make_shared<Triangle>(std::cin);
			list.Insert(in);
			break;
		}
		case 2: {
			in = std::make_shared<Rectangle>(std::cin);
			list.Insert(in);
			break;
		}
		case 3: {
			in = std::make_shared<FSquare>(std::cin);
			list.Insert(in);
			break;
		}
		case 4:
			del=list.Delete();
			break;
		case 5:
			std::cout << list;
			break;
		case 6: {
			break;
		}
		default: std::cout << "Неверный ввод. Попробуйте снова" << std::endl;
			break;
		}
	} while (a != 6);
	return 0;
}

