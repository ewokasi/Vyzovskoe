#include "rooms.h"
#include "myr.h"
node::node(int k, unsigned char t , int cap, string te , bool b )
{
 key = k; type = t; 
 capacity = cap; technic = te;
 bathroom = b;
 left = nullptr;
 right = nullptr;
 height = 1; room =  to_string(key)+ to_string(type);
}


node* find(node* tree, int v)
{
	node* cur = tree;
	while (cur)
	{
		if (cur->key < v)
		{
			cur = cur->right;
		}
		else if (cur->key > v) {
			cur = cur->left;
		}
		if (cur and cur->key == v)
		{
			return cur;
		}


	}
	return 0;
}

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

node* rotateright(node* p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q)
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p)
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

node* insert(node* p, int k, unsigned char t , int cap , string te, bool b )//////////////////////////////////
{
	if (!p) return new node(k, t, cap, te, b);
	if (k < p->key)
		p->left = insert(p->left, k, t, cap, te, b);
	else
		p->right = insert(p->right, k, t, cap, te, b);
	return balance(p);
}

node* findmin(node* p)
{
	return p->left ? findmin(p->left) : p;
}

node* findmax(node* p)
{
	return p->right ? findmax(p->right) : p;
}

node* removemin(node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* removemax(node* p)
{
	if (p->right == 0)
		return p->left;
	p->right = removemax(p->right);
	return balance(p);
}

node* remove(node* p, int k)
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

void show(node* root, int space)
{
	if (!root)
		return;
	enum { COUNT = 2 };
	space += COUNT;
	show(root->right, space);
	for (int i = COUNT; i < space; ++i)
		std::cout << "  ";
	std::cout << root->key<<root->type << std::endl;
	show(root->left, space);
}

void find_by_technic(node* tree, string technic)
{
	if (tree == NULL) return;
	find_by_technic(tree->left, technic);
	
	if (search_myr(tree->technic, technic))
	{
		
		cout << "Node content: " << tree->key << " " << tree->type << " " << tree->capacity << " " << tree->technic << " " << tree->bathroom << endl;
	}
	find_by_technic(tree->right, technic);
}

void serch(node* tree, int key)
{
	node* current = tree;
	int i = 0;
	while (i <= tree->height)
	{
		i++;
		if (current == nullptr)
		{
			return;
		}
		cout << current->key << current->type<<"\nВместительность: "<<current->capacity<<"\nТехника: "<<current->technic<<" Санузел: "<<current->bathroom<<"\n";
		if (current->key != key)
		{
			if (key > current->key)
			{
				current = current->right;
			}
			else if (key < current->key)
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



void walk(node* tree)
{
	if (tree)
	{
		cout << tree->room<<tree->type << ", ";
		walk(tree->left);
		walk(tree->right);


	}
}
