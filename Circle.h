#pragma once
#include "Point.h"
#include <iostream>
#include <fstream>

class Circle
{
	Point m_center;
	double m_rad;
public:
	Circle(Point center, double rad);
	Circle();
	Circle(int x, int y, double rad);
	float GetSquare();
	//Circle(const Circle* d);
	const bool operator==(const Circle& d) const;
	friend std::ostream& operator<<(std::ostream& os, const Circle& c);
	friend std::ofstream& operator<<(std::ofstream& fout, const Circle& c);
};