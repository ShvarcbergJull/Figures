#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>
#include<vector>
#include "FigFunc.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Circle<double>* circle = new Circle<double>(3);
	Rectangle<double>* rect = new Rectangle<double>(3, 5);
	Triangle<double>* trig = new Triangle<double>(3, 4, 5);

	Poligon<double>* pol = new Poligon<double>();
	pol->setDot(2, 1);
	pol->setDot(4, 4);
	pol->setDot(2, 6);
	pol->setDot(5, 6);
	pol->setDot(7, 7);
	pol->setDot(8, 1);

	vector<Figure*>fig;
	fig.push_back(circle);
	fig.push_back(rect);
	fig.push_back(trig);
	fig.push_back(pol);

	double area = 0, perim = 0;
	cout << "Figures:" << endl;
	for (int i = 0; i < fig.size(); i++)
	{
		cout << fig[i]->name() << ": area = " << fig[i]->area() << ",perimetr = " << fig[i]->perimetr() << endl;
		area += fig[i]->area();
		perim += fig[i]->perimetr();
	}
	cout << endl;

	cout << "Area: " << area << endl;
	cout << "Perimetr: " << perim << endl;

	system("pause");
	return 0;
}
