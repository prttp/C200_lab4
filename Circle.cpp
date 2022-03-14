#include "Circle.h"
Circle::Circle(Point center, double rad):m_center(center)
{
	m_rad = rad;
};
Circle::Circle(int x, int y, double rad):m_center(x,y)
{
	m_rad = rad;
};

Circle::Circle()
{
	m_rad = 0;
};
//Circle::Circle(const Circle* d):m_center(d.m_center), ;
const bool Circle::operator==(const Circle& d) const {
	if ((m_rad == d.m_rad) && (m_center == d.m_center)) { return 1; }
	return 0;
};
float Circle::GetSquare() {
	return 3.14 * m_rad * m_rad;
};
std::ostream& operator<<(std::ostream& os, const Circle& c) {
	os << "Center(" <<c.m_center.GetX()<<", " << c.m_center.GetY()<< ") Radius: " << c.m_rad;
	return os;
}
std::ofstream& operator<<(std::ofstream& fout, const Circle& c) {
	fout << "Center(" << c.m_center.GetX() << ", " << c.m_center.GetY() << ") Radius: " << c.m_rad;
	return fout;
}