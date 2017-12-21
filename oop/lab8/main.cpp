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
	TList<Figure> list;
	std::shared_ptr<Figure> p;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "-------------------МЕНЮ-------------------" << std::endl;
	std::cout << "|1-Добавить треугольник                  |" << std::endl;
	std::cout << "|2-Добавить прямоугольник                |" << std::endl;
	std::cout << "|3-Добавить квадрат                      |" << std::endl;
	std::cout << "|4-Удалить фигуру                        |" << std::endl;
	std::cout << "|5-Сортировка                            |" << std::endl;
	std::cout << "|6-Параллельная сортировка               |" << std::endl;
	std::cout << "|7-Расспечатать список                   |" << std::endl;
	std::cout << "|8-Выход                                 |" << std::endl;
	do {
		std::cout << "Выберете действие:" << std::endl;
		if (!(std::cin >> a)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		switch (a) {
		case 1: {
			p = std::make_shared<Triangle>(std::cin);
			list.Push(p);
			break;
		}
		case 2: {
			p = std::make_shared<Rectangle>(std::cin);
			list.Push(p);
			break;
		}
		case 3: {
			p = std::make_shared<FSquare>(std::cin);
			list.Push(p);
			break;
		}
		case 4: {
			int b;
			std::cout << "Какую фигуру удалить?" << std::endl;
			std::cout << "1-треугольник" << std::endl;
			std::cout << "2-прямоугольник" << std::endl;
			std::cout << "3-квадрат" << std::endl;
			if (!(std::cin >> b)) {
				std::cin.clear();
				while (std::cin.get() != '\n');
			}
			switch (b) {
			case 1: {
				p = std::shared_ptr<Triangle>(new Triangle(std::cin));
				list.Delete(p);
				break;
			}
			case 2: {
				p = std::shared_ptr<Rectangle>(new Rectangle(std::cin));
				list.Delete(p);
				break;
			}
			case 3: {
				p = std::shared_ptr<FSquare>(new FSquare(std::cin));
				list.Delete(p);
				break;
			}
			}
			break;
		}
		case 5: {
			list.Sort();
		}
		case 6: {
			list.SortParallel();
		}
		case 7:
			if (!list.IsEmpty()) {
				std::cout << list << std::endl;
			}
			else {
				std::cout << "Список пуст" << std::endl;
			}
		case 8: {
			break;
		}
		default: std::cout << "Неверный ввод. Попробуйте снова" << std::endl;
			break;
		}
	} while (a != 8);
	return 0;
}

