#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(size_t i, size_t j);
	Rectangle(std::istream& is);
	Rectangle(const Rectangle &orig);

	void print(std::ostream& os) const override;

	Rectangle& operator++();
	double Square() const;
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
	friend std::istream& operator>>(std::istream& is, Rectangle& obj);
	Rectangle& operator=(const Rectangle& right);
	bool operator==(const Rectangle& other);

	//virtual ~Rectangle();
private:
	double side_a;
	double side_b;
};

#endif
