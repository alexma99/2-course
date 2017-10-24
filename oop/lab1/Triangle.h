#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(std::istream &is);

	double Square() override;
	void Print() override;

	virtual ~Triangle();
private:
	double side_a;
	double side_b;
	double side_c;
};

#endif
