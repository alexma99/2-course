#ifndef TRIANGLE_H
#define TRIANGLE_H 
#include <cstdlib> 
#include <iostream> 

class Triangle {
public:
	Triangle();
	Triangle(size_t i, size_t j, size_t k);
	Triangle(std::istream& is);
	Triangle(const Triangle &orig);

	Triangle& operator++();
	double Square();
	friend Triangle operator+(const Triangle& left, const Triangle& right);
	friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
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
