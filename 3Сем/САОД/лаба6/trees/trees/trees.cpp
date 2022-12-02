
#include <iostream>
#include <string>
using namespace std;

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node* top = this;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

node* findmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findmin(p->left) : p;
}

node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* remove(node* p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void add(node *root, int key) {
	node* current = root;
	node *top = current->top;
	bool flag = 1;
	while (current)
	{
		if (current->key>key )
		{
			if (current->left != nullptr)
			{
				insert(current, key);
				break;
			}
			current = current->left;
		}
		if (current->key < key )
		{
			
			if (current->right != nullptr)
			{
				insert(current, key);
				break;
			}
			current = current->right;
		}
		
	}
	
	root->top = top;
}
void show(node* root, int space = 0) {
	if (!root)
		return;
	enum { COUNT = 2 };
	space += COUNT;
	show(root->right, space);
	for (int i = COUNT; i < space; ++i)
		std::cout << "  ";
	std::cout << root->key << std::endl;
	show(root->left, space);
}

void serch(node* tree, int key) {
	node* current = tree;
	int i = 0;
	while (i<=tree->height)
	{
		i++;
		cout << current->key << "-";
		if (current->key!=key)
		{
			if (key>current->key)
			{
				current = current->right;
			}
			if (key < current->key)
			{
				current = current->left;
			}
			
		}
		else
		{
		
			break;
		}
		
	}
	
}

int main()
{
	srand(time(0));
	node* root = new node(55);
	
	
	for (int i = 0; i < 23; i++) {
		insert(root, rand() % 100);
	}
	
	show(root);
	int k;
	cin >> k;
	serch(root, k);
}

