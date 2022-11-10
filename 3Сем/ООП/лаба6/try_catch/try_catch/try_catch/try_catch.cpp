#include <iostream>
#include <string>
#include <math.h>

class NoZero 
{
public:
	
	NoZero(const char* msg = "Not neough zeros!!!")
	{
		text = msg;
	}
	const char* what() { return text; }
private:
	const char* text;
};





class arr
{
public:
	arr(int size);
	~arr();
	void fill(int index);
	void show();
	int get_size() { return size; }
	int* get_data() { return data; }
	int even_multiplication(int* arr, int size);
	int sum_between_zeros(int* arr, int size);
	int* convert(int * arr, int size);

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
	int a;
	std::cin>>a;
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

int arr::even_multiplication(int* arr, int size)
{

	if (size<=1)
	{
		throw std::exception("Not Enough elements for even position multiplication\n");
	}
	int result = arr[0];
	for (int i = 2; i < size; i = i + 2)
	{
		result = result * arr[i];
	}

	return result;
}

int arr::sum_between_zeros(int* arr, int size)
{
	
		int zero1 = -1, zero2 = -1;
		for (int i = 0; i < size; i++)
		{

			if (zero1 == -1 and arr[i] == 0)
			{
				zero1 = i;
				continue;
			}
			if (zero1 != -1 and arr[i] == 0)
			{
				zero2 = i;
				continue;
			}
		}
		//std::cout << "zero1: " << zero1 << " zero2: " << zero2 << '\n';

		if (zero2 == -1)
		{
			throw NoZero();
			return 0;
		}

		int result = 1;
		for (int i = zero1 + 1; i < zero2; i++)
		{
			result = result * arr[i];
			//std::cout << result << '\n';
		}


		return result;
	
	
	
}

int* arr::convert(int* arr, int size)
{
	if (size<=1)
	{
		throw std::exception("Not enough elements for convertion\n");
	}

	int* even = new int[0];
	int* odd = new int[0];
	int e = 0;
	int o = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			e++;
			int* temp = even;
			even = new int[e];
			for (int q = 0; q < e-1; q++)
			{
				even[q] = temp[q];
			}
			even[e-1] = arr[i];
		}
		else
		{
			o++;
			int* temp = odd;
			odd = new int[o];
			for (int q = 0; q < o - 1; q++)
			{
				odd[q] = temp[q];
			}
			odd[o-1] = arr[i];
		}
	}
	int* result = new int[size];
	for (int i = 0; i < e; i++)
	{
		result[i] = even[i];
	}
	for (int i = e ; i < e+o; i++)
	{
		result[i] = odd[i-e];
	}

	

	return result;
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
		try
		{
			list.fill(i);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
		
	}

	std::cout << "\nYour array: ";
	list.show();


	std::cout << "1) sum between zeros\n2) even pos mult\n3) sort the array\n";
	int var = 0;
	while (true)
	{
		std::cin >> var;
		switch (var)
		{
		case 1:
			try
			{
				int* smth = list.get_data();
				std::cout << list.sum_between_zeros(smth, size) << '\n';
			}
			catch (NoZero& ex)
			{
				std::cout << ex.what() << '\n';
			}
			break;

		case 2:

			try
			{
				std::cout<<"even mult: " << list.even_multiplication(list.get_data(), size)<<"\n";
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << '\n';
			}
			break;

		case 3:

			try
			{
				int* res = list.convert(list.get_data(), size);
				for (int i = 0; i < size; i++)
				{
					std::cout << res[i] << ' ';
				}
				std::cout << '\n';
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what()<<'\n';
			}
			break;

		default:
			break;
		}
	}
}
