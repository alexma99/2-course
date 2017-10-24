#ifndef FSQUARE_H
#define FSQUARE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class FSquare : public Figure {
public:
	FSquare();
	FSquare(std::istream &is);

	double Square() override;
	void Print() override;

	virtual ~FSquare();
private:
	double side_a;
};

#endif
