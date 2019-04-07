#pragma once
#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.1415

using namespace std;

struct Point
{
	double x, y;
};

class Figure {
public:
	virtual string name() = 0;
	virtual double area() = 0;
	virtual double perimetr() = 0;
};

template <class T> class Circle : public Figure
{
public:
	Circle(T r)
	{
		this->r = r;
	}

	Circle() {};

	string name()
	{
		return "circle";
	}

	double area()
	{
		return PI * r * r;
	}

	double perimetr()
	{
		return 2 * PI * r;
	}

private:
	T r;
};


template <class T> class Triangle : public Figure
{
public:
	Triangle(T a, T b, T c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	Triangle() {};

	string name()
	{
		return "triangle";
	}

	double area()
	{
		double p = this->perimetr() / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	double perimetr()
	{
		return a + b + c;
	}

private:
	T a, b, c;
};

template <class T> class Poligon : public Figure
{
public:
	Poligon() {}

	void setDot(T x, T y)
	{
		Point d;
		d.x = x;
		d.y = y;

		dots.push_back(d);
	}

	string name()
	{
		return "Poligon";
	}

	double area()
	{
		double area = 0;
		for (int i = 0; i < dots.size() - 2; i++) {
			area += ((dots[i + 1].x - dots[0].x) * (dots[i + 2].y - dots[0].y)) - ((dots[i + 1].y - dots[0].y) * (dots[i + 2].x - dots[0].x));
		}
		return abs(area) / 2;
	}

	double perimetr()
	{
		double perim = 0;
		for (int i = 0; i < dots.size() - 1; i++) {
			perim += sqrt((dots[i + 1].x - dots[i].x) * (dots[i + 1].x - dots[i].x) + (dots[i + 1].y - dots[i].y) * (dots[i + 1].y - dots[i].y));
		}
		perim += sqrt((dots[dots.size() - 1].x - dots[0].x) * (dots[dots.size() - 1].x - dots[0].x) +
			(dots[dots.size() - 1].y - dots[0].y) * (dots[dots.size() - 1].y - dots[0].y));
		return perim;
	}


private:
	vector<Point> dots;
};

template <class T> class Rectangle : public Figure
{
public:
	Rectangle(T a, T b)
	{
		this->a = a;
		this->b = b;
	}

	string name()
	{
		return "rectangle";
	}

	double area()
	{
		return a * b;
	}

	double perimetr()
	{
		return (a + b) * 2;
	}

private:
	T a, b;
};
