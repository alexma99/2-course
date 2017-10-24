#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream& is);

	double Square() override;
	void Print() override;

	virtual ~Rectangle();
private:
	double side_a;
	double side_b;	
};

#endif
