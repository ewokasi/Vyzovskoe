#include <iostream>
#include <string>

template<typename T>
class List
{
public:
	List();
	~List();
	void push(T data);
	int get_size() { return size; }
	int value(int index);
	void remove(int index);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<int> *head;
	int size;

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;

}
template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		head->pNext = head;
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext!=head)
		{
			current = current->pNext;
		} 
		Node<T> *tempHead = current->pNext;
		current->pNext = new Node<T>(data);
		current->pNext->pNext = tempHead;
	}
	size++;
	
}

int* add(int value, int arr [], int size)
{
	size++;
	int* res = new int[size];
	for (int i = 0; i < size; i++)
	{
		res[i] = arr[i];
	}
	res[size-1] = value;
	return res;
}

template<typename T>
int List<T>::value(int index)
{
	Node<T>* current = this->head;
	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}
	return current->data;
}

template<typename T>
void List<T>::remove(int index)
{
	Node<T>* current = this->head;
	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}
	Node<T>* rightP = current->pNext;
	delete current;
	size--;
	current = this->head;
	for (int i = 0; i < index-1; i++)
	{
		current = current->pNext;
	}
	current->pNext = rightP;

}

template<typename T>
bool equal(List<T> left, List<T> right) {

	if (left.get_size() != right.get_size()) return 0;

	for (int i = 0; i < left.get_size(); i++) 
	{
		if (left.value(i) != right.value(i)) return 0;
	}

	return 1;
}

int main()
{
	List <int> lst;
	int* A_a =  new int [1];
	int* X_a = new int[1];
	X_a[0] = 0;
	A_a[0] = 0;
	int c = 1;

	while (1)
	{
		int decide;
		std::cout << "1 to push\n2 to remove\n";
		std::cin >> decide;
		if (decide ==1)
		{	
			int A, X;
			std::cout << "Enter A, X: ";
			std::cin >> A;
			std::cin >> X;
			
			lst.push(A*pow(X, lst.get_size()));
			A_a=add(A, A_a, c);
			X_a=add(X, X_a, c);
			c++;
			
		}
		else if(decide ==2)
		{
			std::cout << "Enter index: ";
			int index;
			std::cin >> index;
			if (lst.get_size() == 0) continue;
			lst.remove(index);
		}
		else
		{
			break;
		}
	}
	
	for (int i = 0; i < c; i++) {
		if (A_a[i] == 0) continue;
		std::cout << A_a[i] << "*" << X_a[i] << "^" << i;
		if (i != c - 1) { std::cout << "+"; }
	}
	std::cout << std::endl;

	for (int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst.value(i);
		if (i!=lst.get_size()-1)
		{
			std::cout << "+";
		}
	}

	std::cout << std::endl;

	List<int> lllst;
	int* a2 = new int[1];
	a2[0] = 0;
	int* x2 = new int[1];
	x2[0] = 0;
	c = 1;
	while (1)
	{
		int decide;
		std::cout << "1 to push\n2 to remove\n";
		std::cin >> decide;
		if (decide == 1)
		{
			double A, X;
			std::cout << "Enter A, X: ";
			std::cin >> A;
			std::cin >> X;

			lllst.push(A * pow(X, lllst.get_size()));
			a2 = add(A, a2, c);
			x2 = add(A, x2, c);
			c++;
			
		}
		else if (decide == 2)
		{
			std::cout << "Enter index: ";
			int index;
			std::cin >> index;
			if (lst.get_size() == 0) continue;
			lllst.remove(index);
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < c; i++) {
		if (a2[i] == 0) { continue; }
		std::cout << a2[i] << "*" << x2[i] << "^" << i;
		if (i != c - 1) { std::cout << "+"; }
	}
	std::cout << std::endl;

	for (int i = 0; i < lllst.get_size(); i++)
	{
		std::cout << lllst.value(i);
		if (i != lllst.get_size() - 1)
		{
			std::cout << "+";
		}
	}
	std::cout << "\n\n is equal: " << equal(lst, lllst) << "\n";
}
