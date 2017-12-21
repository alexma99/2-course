#ifndef TRIANGLE_H
#define TRIANGLE_H 
#include <cstdlib> 
#include <iostream> 
#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(double i, double j, double k);
	Triangle(std::istream& is);
	Triangle(const Triangle &orig);

	Triangle& operator++();
	double Square();
	void Print();
	friend Triangle operator+(const Triangle& left, const Triangle &right);
	friend std::ostream& operator<<(std::ostream& os, const Triangle &obj);
	friend std::istream& operator>>(std::istream& is, Triangle& obj);

	Triangle& operator=(const Triangle& right);
	bool operator==(const Triangle& other);

	virtual ~Triangle();
private:
	double side_a;
	double side_b;
	double side_c;
};
#endif 
