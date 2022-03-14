#include "Point.h"

Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
}
Point& Point::operator+=(const Point& other) {
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
};
Point& Point::operator+=(int d) {
	m_x += d;
	m_y += d;
	return *this;
};
Point& operator-=(Point& f, const Point& s) {
	f.m_x -= s.m_x;
	f.m_y -= s.m_y;
	return f;
};
Point& operator-=(Point& f, int d) {
	f.m_x -= d;
	f.m_y -= d;
	return f;
};
Point::Point() {
	m_x = 0; m_y = 0;
}
Point Point::operator+(const Point& other) const {
	return Point(m_x + other.m_x, m_y + other.m_y);
}
Point Point::operator+(int d) const {
	return Point(m_x + d, m_y + d);
}
Point operator-(const Point& f, int d) {
	return Point(f.m_x - d, f.m_y - d);
}
Point operator-(const Point& f, const Point& s) {
	return Point(f.m_x - s.m_x, f.m_y - s.m_y);
}
Point operator+(int d, const Point& f) {
	return Point(d+f.m_x , d+f.m_y );
}
Point Point::operator-() const {
	return Point(-m_x, -m_y);
}
const Point& Point::operator+() const {
	return *this;
}

int Point::GetX() const
{
	return m_x;
}

int Point::GetY() const
{
	return m_y;
}
bool Point::operator==(const Point& d) const {
	if ((m_x == d.m_x) && (m_y == d.m_y)) { return 1; }
	return 0;
}
