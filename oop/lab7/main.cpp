#include <cstdlib>
#include <iostream>
#include "TList.h"
#include "triangle.h"
#include "rectangle.h"
#include "fsquare.h"
#include <memory>
#include "storage.h"
#include "TAllocationBlock.h"



int main() {
	TStorage<Figure> storage;
	setlocale(LC_ALL, "Russian");
	int a;
	TList<Figure> list;
	std::shared_ptr<Figure> p;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------------МЕНЮ-------------" << std::endl;
	std::cout << "1-Добавить треугольник" << std::endl;
	std::cout << "2-Добавить прямоугольник" << std::endl;
	std::cout << "3-Добавить квадрат" << std::endl;
	std::cout << "4-Удалить фигуру по площади" << std::endl;
	std::cout << "5-Удалить трегольники" << std::endl;
	std::cout << "6-Удалить прямоугольники" << std::endl;
	std::cout << "7-Удалить квадраты" << std::endl;
	std::cout << "8-Расспечатать" << std::endl;
	std::cout << "0-Выход" << std::endl;
	do {
		std::cout << "Выберете действие:" << std::endl;
		if (!(std::cin >> a)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		switch (a) {
		case 1: {
			storage.Insert(std::make_shared<Triangle>(std::cin));
			break;
		}
		case 2: {
			storage.Insert(std::make_shared<Rectangle>(std::cin));
			break;
		}
		case 3: {
			storage.Insert(std::shared_ptr<FSquare>(new FSquare(std::cin)));
			break;
		}
		case 4: {
			double maxSq;
			std::cout << "Удалить все объекты с площадью меньше, чем: ";
			std::cin >> maxSq;
			RemoveCriteriaByMaxSquare critMaxSq(maxSq);
			storage.DeleteByCriteria(critMaxSq);
			break;
		}
		case 5:{
				RemoveCriteriaByFigureType critFigType("Triangle");
				storage.DeleteByCriteria(critFigType);
				break;
			}
		case 6: {
				RemoveCriteriaByFigureType critFigType("Rectangle");
				storage.DeleteByCriteria(critFigType);
				break;
			}
		case 7:{
				RemoveCriteriaByFigureType critFigType("FSquare");
				storage.DeleteByCriteria(critFigType);
				break;
			}
		case 8: {
			std::cout << storage << std::endl;
			break;
			}
		case 0: {
			break;
		}
		default: std::cout << "Неверный ввод. Попробуйте снова" << std::endl;
			break;
		}
		} while (a != 0);
		return 0;
}

