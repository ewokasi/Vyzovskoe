
#include <iostream>

class B1
{
public:
	B1(int z=0);
	~B1();
	virtual void show();
	int  z;


protected:
	

};

B1::B1(int z)
{
	this->z = z;
	std::cout << "Calling B1 Constructor with param x = "<<z<<"\n";
}

B1::~B1()
{
	std::cout << "Calling destructor B1\n";
}

void B1::show()
{
	std::cout << "B1 show " << z<< std::endl;
}

class D1:public B1
{
public:
	D1(int y, int z);
	~D1();
	virtual void show() override;
	int y;
private:
	
protected:
	

};

void D1::show()
{
	std::cout << "D1 show " << y << " "  << std::endl;
}

D1::D1(int y, int z): B1 (z)
{
	this->y = y;
	
	B1::show();
	std::cout << "Calling D1 Constructor with param " << y<<" "<< z << "\n";
}

D1::~D1()
{
	std::cout << "Calling destructor D1\n";
}

class D2 : private B1
{
public:
	D2(int y, int z);
	~D2();
	void show() override;
	int y, z;
private:
	int i;
protected:
	int j;
};

 void D2::show() 
{
	 std::cout << "D2 show private " << y << std::endl;
}
D2::D2(int y, int z) : B1(z)
{	
	this->y = y;
	B1::show();
	std::cout << "Calling D2 Constructor with param " << y<< " "<< z << "\n";
	
}

D2::~D2()
{
	std::cout << "Calling destructor D2\n";
}


class D3:private D1
{
public:
	D3(int x, int y, int z);
	~D3();
	void show() override;
private:
	int x;
	
};

D3::D3( int x, int y, int z) : D1(y, z)
{
	this->x = x;
	D1::show();
	
	std::cout << "calling D3 constructor with params: "<<  x <<" "<<y<<" "<<z << '\n';
}

D3::~D3()
{
	std::cout << "\nCalling destructor D3\n";
}

void D3::show()
{
	std::cout << "D3 show " <<  x <<  std::endl;
}

class D4:public D2
{
public:
	D4(int x, int y, int z);
	~D4();
	void show() override;
	int x, y, z;
private:
	int i;
protected:
	int j;
};

void D4::show()
{
	std::cout << "D4 show private " << x  << std::endl;

}

D4::D4(int x, int y , int z) : D2(y , z)
{
	this->x = x;
	D2::show();
	std::cout << "Calling D4 Constructor with params: " << x << " "<< y<<" "<<z << "\n";
}

D4::~D4()
{
	std:: cout << "\nCalling destructor D4\n";
}

int main()
{
	system("color f1");
	std::cout << "classes B1->D2->D4\n";
	D4 point(1 , 2, 3);
	point.show();

	std::cout << "\n\n";
	std::cout << "classes B1->D1->D3\n";
	D3 point2(100, 200, 300);
	point2.show();
    
}
