#ifndef FSQUARE_H
#define FSQUARE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class FSquare : public Figure {
public:
	FSquare();
	FSquare(size_t i);
	FSquare(std::istream& is);
	FSquare(const FSquare &orig);

	FSquare& operator++();
	double Square();
	friend FSquare operator+(const FSquare& left, const FSquare& right);
	friend std::ostream& operator<<(std::ostream& os, const FSquare& obj);
	friend std::istream& operator>>(std::istream& is, FSquare& obj);

	FSquare& operator=(const FSquare& right);
	bool operator==(const FSquare& other);

	void Print();

	virtual ~FSquare();
private:
	double side_a;
};

#endif
