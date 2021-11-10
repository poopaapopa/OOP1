#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Point
{
	double x;
	double y;
public:
	explicit Point(double x = 0, double y = 0);
	void display() const;
	void read();
	static bool isEqual(const Point& point1, const Point& point2);
	static Point add(const Point& point1, const Point& point2);
	static Point mult(const Point& point1, double value);
	static double distance(const Point& point1, const Point& point2);
	static double lenght(const Point& point);
	friend bool operator==(const Point& point1, const Point& point2) { return isEqual(point1, point2); }
	friend Point operator+(const Point& point1, const Point& point2) { return add(point1, point2); }
	friend ostream& operator<<(ostream& output, const Point& point) 
	{
		output << "(" << point.x << "." << point.y << ")";
		return output;
	}
};
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::display() const
{
	cout << "(" << x << "," << y << ")";
}
void Point::read()
{
	double x;
	double y;
	cin >> x >> y;
	this->x = x;
	this->y = y;
}
bool Point::isEqual(const Point& point1, const Point& point2)
{
	return point1.x == point2.x and point1.y == point2.y;
}
Point Point::add(const Point& point1, const Point& point2)
{
	Point point3(point1.x+point2.x,point1.y+point2.y);
	return point3;
}
Point Point::mult(const Point& point1, double value)
{
	Point point2(point1.x * value, point1.y * value);
	return point2;
}
double Point::distance(const Point& point1, const Point& point2)
{
	return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}
double Point::lenght(const Point& point)
{
	return point.x - point.y;
}

int main()
{
	Point point1(1, 1);
	Point point2;
	Point point3(1, 1);
	if (point1 == point3)
		cout << "point1 and point3 are equal\n";
	cout << "p1";
	point1.display();
	cout << "\nEnter point p2 in format x y (e.g.12,10)";
	point2.read();
	cout << "p2";
	point2.display();
	cout << "\np2 + p1 = " << point2 + point1;
	//Point::add(point2, point1).display();
	cout << "\nDistance between ";
	point1.display();
	cout << " and ";
	point2.display();
	cout << " is " << Point::distance(point1, point2) << "\n";
	return 0;
}