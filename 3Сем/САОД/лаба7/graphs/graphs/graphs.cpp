
#include <iostream>
#include <vector>

class matrix
{
public:
	matrix();
	~matrix();
	void add_student();
	void add_link(int f, int s);
	void show();
	std::vector<int> find_link(int student);
	std::vector<int> no_link(int student);
	void make_groups(int num);

private:
	std::vector <std::vector <int>> groups ;
	int** table =0;
	int students = 0;
	int links = 0;
};

matrix::matrix()
{
}

matrix::~matrix()
{
}

void matrix::add_student()
{
	students++;
	int **temp_table = new int*[students];
	for (int i = 0; i < students-1; i++)
	{
		temp_table[i] = table[i];
	}
	for (int q = 0; q < links; q++)
	{
		temp_table[students - 1][q] = 0;
	}
	table = temp_table;
}

void matrix::add_link(int f, int s)
{
	int** temp_table = new int*[students];
	
	for (int i = 0; i < students; i++)
	{
		temp_table[i] = new int[links+1];
		
		for (int q = 0; q < links; q++) {
			
			temp_table[i][q] = table[i][q];
			
		}
		temp_table[i][links] = 0;

	
		
	}
	links++;
	temp_table[f][links-1] = 1;
	temp_table[s][links - 1] = 1;
	
	table = temp_table;
}

void matrix::show()
{
	for (int i = 0; i < students; i++)
	{
		for (int q = 0; q < links; q++)
		{
			std::cout << table[i][q] << "\t";
		}
		std::cout << "\n";
	}

}

std::vector<int> matrix::find_link(int student)
{
	std::vector <int> match;
	for (int i = 0; i < links; i++)
	{
		if (table[student][i] == 1)
		{
			for (int q = 0; q < students; q++)
			{
				if (table[q][i]==1 and q!=student)
				{
					match.push_back(q);
				}
			}
		
		}
	}
	return match;
}

std::vector<int> matrix::no_link(int student)
{
	std::vector <int> match;
	for (int i = 0; i < links; i++)
	{
		if (table[student][i] == 0)
		{
			for (int q = 0; q < students; q++)
			{
				if (table[q][i]==0 and q!=student)
				{
					match.push_back(q);
				}
			}
		
		}
	}
	
	return match;
}

bool already_in(std::vector <int> el ,std::vector <int> arr) {
	if (arr.empty())
	{
		return 0;
	}

	for (auto i: arr)
	{
		for (auto e: el)
		{
			if (i == e)
			{
				return 1;
			}
		}
		
	}
	return 0;

}

bool balanced(std::vector<int>arr)
{
	for (int i = 0; i < arr.size(); i++) {
		for (int q = i; q < arr.size(); q++)
		{
			if (arr[i]>arr[q]*2)
			{
				return 0;
			}
		}
	}
	return 1;
}

int can_be_moved_to(std::vector <int> links, std::vector <std::vector <int>> groups, int from)
{
	int group_num = -1;
	int move_to = -1;
	for (auto group : groups)
	{
		bool flag = 1;
		group_num++;
		for (auto stud : group)
		{
			for (auto link : links)
			{
				if (link == stud)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag and group_num!=from)
		{
			move_to = group_num;
			return move_to;
		}
	}
	return move_to;
}

int vec_find(std::vector <int> arr, int el)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]==el)
		{
			return i;
		}
	}
	return -1;
}

void matrix::make_groups(int num)
{
	
	std::vector <int>group_size;
	group_size.push_back(0);
	groups.push_back(std::vector<int>());
	int groups_count;
	for (int i = 0; i < students; i++)
	{
		std::vector <int> linked = find_link(i);
		int working_group = 0;
		groups_count = groups.size();
		while (true)
		{
			if (!already_in(linked, groups[working_group]))
			{
				groups[working_group].push_back(i);
				group_size[working_group] = groups[working_group].size();
				std::cout << "Added student num " << i << " ,Size of group " << working_group << " is " << group_size[working_group] << '\n';
				break;
			}
			else
			{
				working_group++;
				if (groups.size()<working_group+1)
				{
					groups.push_back(std::vector<int>());
					group_size.push_back(0);
				}
			}

		}
			
		
		
	}

	while (1)
	{
		if (balanced(group_size))
		{
			break;
		}
		for (int i = 0; i < group_size.size(); i++)
		{
			bool flag = 0;
			for (auto q : groups[i])
			{
				std::vector <int> linked = find_link(q);
				int move_to = can_be_moved_to(linked, groups, i);


				if (move_to!=-1)
				{
					if (vec_find(groups[i], q)!=-1)
					{
						auto iter = groups[i].begin();
						groups[i].erase(iter+vec_find(groups[i], q));
						groups[move_to].push_back(q);
						group_size[move_to] ++;
						group_size[i] --;
						
						
					}
				}
				
			}
			if (balanced(group_size))
			{
				break;
			}
		}
	}
	
	if (num<=students and num>=groups.size())
	{
		std::cout << "\n\nAvailable to make " << num << " Groups\n";
	}
	else
	{
		std::cout << "Imposible to make " << num << " Groups\n";
	}
	std::cout << "\n\nMinimal group count is "<<groups.size()<<"\n";
	for (auto group : groups)
	{
		std::cout << "Group: ";
		for (auto student : group) {
			std::cout << student << "\t";
		}
		std::cout << "\n";

	}



}


int main()
{
	matrix mat;

	std::cout << "Do you want to set your own Students and links? (y/n)\n";
	char v;
	
	std::cin >> v;
	switch (v)
	{
	case 'y':
		std::cout << "How many students you want: ";
		int stud;
		std::cin >> stud;
		for (int i = 0; i < stud; i++)
		{
			mat.add_student();
		}
		while (1)
		{
			std::cout << "Set links in format 0 2 (student student), -1 to stop\n";
			int f, s;
			std::cin >> f;
			std::cin >> s;
			if (f != -1)
			{

				mat.add_link(f, s);
			}
			else
			{
				break;
			}
		}
		
		break;
	default:
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_student();
		mat.add_link(2, 1);
		mat.add_link(2, 3);
		mat.add_link(1, 5);
		mat.add_link(6, 5);
		mat.add_link(4, 1);
		mat.add_link(6, 3);
		mat.add_link(5, 4);
		mat.add_link(6, 3);
		mat.add_link(4, 6);
		mat.add_link(0, 6);


		break;
	}

	std::cout <<"Enter a number to check the ability to make such groups: ";
	int num;
	std::cin >> num;
	mat.make_groups(num);

	
	std::cout << "\n";
	mat.show();
	
	
}
