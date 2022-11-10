
#include <iostream>

class stack
{
public:
	stack();
	~stack();
	void add(int tick);
	int get_tick();
	void del();
	int is_empty();
	void show();

	class element
	{
	public:
		int tick;
		element* next;
		element(int tick=0, element* ptr = nullptr) { this->tick = tick; next = ptr; };
		~element();
		void set(int tick) { this->tick = tick; };
		
	};


private:
	element* top = nullptr;
};


void stack::del()
{
	element* current = top;
	for (int i = 0; i < 10; i++)
	{
		current->tick = current->next->tick;
		current = current->next;
	}
	current->tick = 0;
}

int stack::is_empty()
{
	if (top->tick==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stack::show()
{
	{
		element* current = top;
		int i = 1;
		while (current->next != nullptr and i<10)
		{
			std::cout << "stack Tasks ticks " << current->tick << ", priority: " << i<<"\n";
			i++;
			current=current->next;
		}
	}
}

int stack::get_tick() {
	if (top->tick==0)
	{
		return 0;
	}
	element* current = top;
	return current->tick;
}

stack::stack()
{
	for (int i = 0; i < 10; i++)
	{
		this->add(0);
	}
}

stack::~stack()
{
}

void stack::add(int tick)
{
	element* el = new element(tick);
	element* current = top;
	
	if (top != nullptr)
	{
		el->next = top;
		top = el;
	}
	else
	{
		
		top = el;
	}
}


class queue
{
public:
	queue(int arr[10]);
	~queue();
	void add(int tick);
	void del();
	int get_tick();
	void solve();
	int is_empty();
	void show();

	class element
	{
	public:
		element(int tick =0, element* ptr = nullptr) { this->tick = tick; next = ptr; };
		~element();
		void set(int tick) { this->tick = tick; };
		

		int tick;
		element* next;

	};

private:
	element* now = nullptr;

};

queue::queue(int arr[10])
{
	
	for (int i = 0; i < 10; i++)
	{
		add(arr[i]);
	}
}

queue::~queue()
{
}

void queue::add(int tick)
{
	if (now==nullptr)
	{
		element* el = new element(tick);
		now = el;
	}
	else
	{
		element* cur = now;
		while (cur->next !=nullptr)
		{
			cur = cur->next;
		}
		element* el = new element(tick);
		cur->next = el;
	}
}

void queue::del()
{	
	element* cur = now;
	cur = cur->next;
	now = cur;
}

int queue::get_tick()
{
	if (now==nullptr)
	{
		return 0;
	}
	return now->tick;
}

void queue::solve()
{
	now->tick = now->tick - 1;
}

int queue::is_empty()
{
	if (now==nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void queue::show()
{
	element* current = now;
	int i = 1;
	if (current == nullptr) return;
	while (current->next!=nullptr)
	{
		std::cout << "queue Tasks ticks " << current->tick << ", priority: " << i<<"\n";
		i++;
		current = current->next;
	}
}

class processor
{
public:
	processor(int num) { name = num; };
	~processor();
	void do_tick();
	void add_task(int time);
	int get_status();
	int get_task() { return task; };
	int havedone() { return done; };

private:
	int task;
	int tick=0;
	bool free=1;
	int name;
	int done;

};

processor::~processor()
{
}

void processor::do_tick()
{
	if (free)
	{
		std::cout << "PC" << name << " is free" << std::endl;
		done = 0;
	}
	else
	{
		std::cout << "PC" << name << " Is doing task. Ticks befor complete: " << tick << std::endl;
		tick = tick - 1;
		done = 0;
	}
	
	if (tick<=0 && free==0)
	{
		std::cout <<"PC"<<name << " Task is Done\n";
		free = 1;
		done = 1;
	}
	
}

void processor::add_task(int time)
{
	task = time;
	tick = time;
	free = 0;
	std::cout << "PC" << name << " recieved task. Ticks befor complete: " << tick<<'\n';
}

int processor::get_status()
{
	return free;
}




int main()
{

	int tasks[10];
	tasks[0] = 10;
	tasks[1] = 2;
	for (int i = 2; i < 10; i++)
	{
		tasks[i] = 1;
	}
	std::cout << "Do you want to set your own tasks y/n\n";
	char inp;
	std::cin >> inp;
	if (inp=='y')
	{
		std::cout << "enter 10 values: ";
		for (int i = 0; i < 10; i++)
		{
			std:: cin >> tasks[i];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << tasks[i] << "\t";
	}
	std::cout<< "\n";

	queue hosp(tasks);
	stack done;
	
	processor PC0(0);
	processor PC1(1);
	

	int timer = 1;

	while (true)
	{

		try
		{
			std::cout << "-------tick number " << timer <<"-------" << '\n';
			hosp.show();
			done.show();

			if (PC0.havedone() == 1)
			{
				done.add(PC0.get_task());
				std::cout << "Added new task " << PC0.get_task() << " in stack. time of adjust " << timer << "\n";
			}

			if (PC0.get_status() == 1)
			{
				if (hosp.get_tick() != 0)
				{
					int task = hosp.get_tick();
					PC0.add_task(task);
					hosp.del();

				}
				else
				{
					std::cout << "Hosp is empty\n";
				}

			}


			if (PC1.get_status() == 1)
			{
				if (done.get_tick() > 0)
				{
					int task = done.get_tick();
					PC1.add_task(task);
					done.del();

				}
				std::cout << "Done is empty\n";
			}
			PC0.do_tick();
			PC1.do_tick();

			timer++;
			std::cout << "\n";

			std::cin.get();

		}
		catch (const std::exception&)
		{
			continue;
		}
		

	}


}

