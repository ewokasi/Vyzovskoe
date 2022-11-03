#include <iostream>

class Exception 
{
public:
	std::string E_error; 
	Exception() : E_error("\n Error found: ") {};
	virtual const std::string GetError() = 0;
};


class NoZero : public Exception 
{
public:
	std::string Z_error; 
	NoZero() : Z_error("No Zeros\n") { }
	virtual const std::string GetError() override
	{
		return E_error + Z_error;
	}
};


int even_multiplication(int * arr, int size)
{
	int result=arr[0];
	for (int i = 2; i < size; i = i + 2)
	{
		result = result * arr[i];
	}

	return result;
}


class arr
{
public:
	arr(int size);
	~arr();
	void fill(int index);
	void show();
	int get_size() { return size; }
	int* get_data() { return data; }
private:
	int* data;
	int size;
};

arr::arr(int size)
{
	data = new int[size];
	this->size = size;
}

arr::~arr()
{
}

void arr::fill(int index)
{
	std::cin>>data[index];
}

void arr::show()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "\n";
}



int sum_between_zeros(int* arr, int size)
{
	try
	{
		int zero1 = 0, zero2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (zero1 == 0 and arr[i] == 0)
			{
				zero1 = i;
				continue;
			}
			if (zero1 != 0 and arr[i] == 0)
			{
				zero2 = i;
				continue;
			}
		}
		std::cout << "zero1: " << zero1 << " zero2: " << zero2 << '\n';

		if (zero2 == 0)
		{
			throw NoZero();
		}

		int result = 1;
		for (int i = zero1 + 1; i < zero2; i++)
		{
			result = result * arr[i];
		}


		return result;
	}
	catch (Exception& exception)
	{
		std::cout << exception.GetError();
	}
	
}

int main()
{
	system("color f1");
	//out_of_range
	int size;
	std::cout << "Enter the size of array: ";
	std::cin >> size;
	
	arr list(size);
	std::cout << "Fill the array: ";
	for (int i = 0; i < size; i++)
	{
		list.fill(i);
	}
	list.show();
	int* smth = list.get_data();
	std::cout << even_multiplication(smth, size);
 
}
