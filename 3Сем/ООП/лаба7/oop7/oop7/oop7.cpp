
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
	int count_mod(int m);

	

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
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
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

	std::vector <int> res = std::partial_sum(right.data.begin(), right.data.end(), data.begin());
		
	return right;
}

int arr::count_mod(int m)
{
	int counter=0;
	for (int i = 0; i < size; i++)
	{
		
		if (data[i]%m==0)
		{
			counter++;
		}
	}
	return counter;
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

	std::cout << "Count of mods(5) For A: " << A.count_mod(5)<<'\n';
	std::cout << "Count of mods(5) For B: " << B.count_mod(5) << '\n';
	std::cout << "Count of mods(5) For C: " << C.count_mod(5) << '\n';
}

