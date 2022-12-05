
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

class arr
{
public:
	arr(int size, int min, int max);
	~arr();
	void fill(int index);
	void show();
	int get_size() { return size; }
	std::vector <int> get_data() { return data; }
	double avg();
	arr plus(arr right);
	int count_mod();

	

private:
	std::vector <int> data;
	int size;
};

arr::arr(int size, int min, int max)
{
	
	this->size = size;
	std::srand(time(0));
	for (int i = 0; i < size; i++)
	{
		data.push_back((int)((std::rand() % (abs(min) + abs(max) + 1)) + min)) ;
	}
}

arr::~arr()
{
}

void arr::fill(int index)
{
	int a;
	std::cin >> a;
	data[index] = a;

}

void arr::show()
{
	for (auto n : data)
		std::cout << n << " ";
	std::cout << '\n';
	std::cout << "\n";
}

double arr::avg()
{
	double sum = std::accumulate(data.begin(), data.end(), 0);
	//algoritm numeric

	return sum/size;
}

arr arr::plus(arr right)
{

	std::vector <int> v;
	v = right.data;
	
	for (int i = 0; i < v.size();i++)
	{
		v[i] += data[i];
	}
	right.data = v;
	return right;
}

int arr::count_mod()
{
	std::vector <int>v = data;
	int count_div5 = std::count_if(v.begin(), v.end(), [](int i) {return i % 5 == 0; });
	return count_div5;
}


int main()
{
	system("color f1");

	int length;
	
    std::cout << "Enter length of array: ";
	std::cin >> length;

	std::cout << "Array A: ";
	arr A(length, 0, 10);
	if (A.get_data().empty())
	{
		std::cout << "Length is 0\n";
		return 0;
	}
	A.show();

	std::cout << "Average of A is: " << A.avg()<<'\n' << '\n';
	std::cout << "Array B: ";
	arr B(length, -10, 10);
	B.show();
	std::cout << "Average of B is: " << B.avg() << '\n' << '\n';

	std::cout << "Sum of A+B = C: ";
	arr C = A.plus(B);
	C.show();
	std::cout << "Average of C is: " << C.avg() << '\n' << '\n';

	std::cout << "Count of mods(5) For A: " << A.count_mod()<<'\n';
	std::cout << "Count of mods(5) For B: " << B.count_mod() << '\n';
	std::cout << "Count of mods(5) For C: " << C.count_mod() << '\n';
}

