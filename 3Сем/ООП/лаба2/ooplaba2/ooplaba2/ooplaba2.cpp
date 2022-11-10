
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>


class cyl
{
public:
	cyl(double radius = 1 , double height = 12);
	cyl(const cyl& obj);
	~cyl();

	double volume();
	double square();

private:

	double radius, height;

};

cyl::cyl(double radius, double height)
{	
	std::cout << "Вызов контсруктора " << this<<std::endl;
	this->radius = radius;
	this->height = height;
}

cyl::cyl(const cyl& obj)
{
	std::cout << "Вызов контсруктора копирования " << this << std::endl;
	this->radius = obj.radius;
	this->height = obj.height;
}


double cyl::volume()
{
	return M_PI *radius * radius * height;
}

double cyl::square()
{
	return M_PI * radius * radius * 2 + height * M_PI * radius;
}

cyl::~cyl()
{
	std::cout << "Вызов деструктора " << this << std:: endl;
}

int main()
{
	system("color f1");
	setlocale(LC_ALL, "RUS");
	cyl a;
	std::cout << "a - с параметрами по умолчанию (0, 0) Sq, Vol: " << a.square() <<", " << a.volume() << std::endl << std::endl;

	int b_r = 4;
	int b_h = 12;
	cyl b(b_r, b_h);
	std::cout << "b - с параметрами " << b_r << ", " << b_h << " Sq, Vol: " << b.square() << ", " << b.volume() << std::endl << std::endl;

	cyl copy_of_b(b);
	std::cout << "copy_of_b - с параметрами " << b_r << ", " << b_h << " Sq, Vol: " << copy_of_b.square() << ", " << copy_of_b.volume() << std::endl << std::endl;
}
;