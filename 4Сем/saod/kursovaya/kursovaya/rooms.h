#pragma once
#ifndef rooms_h
#define rooms_h

#include <iostream>
#include <string>
#include <vector>
# include <limits.h>
# define NO_OF_CHARS 256
#include "myr.h"
using namespace std;


struct node // структура для представления узлов дерева
{
	int key, capacity;
	string room, technic;
	bool bathroom;

	unsigned char height, type;
	node* left = nullptr;
	node* right = nullptr;
	node* top = this;
	node(int k, unsigned char t = 'A', int cap = 2, string te = "", bool b = 1);
};

node* find(node* tree, int v);

unsigned char height(node* p);
void fixheight(node* p);

int bfactor(node* p);

node* rotateright(node* p);
node* rotateleft(node* q);
node* balance(node* p);

node* insert(node* p, int k, unsigned char t = 'A', int cap = 2, string te = "-", bool b = 1);

node* find(node* tree, int v);
node* findmin(node* p);
node* findmax(node* p);

node* removemin(node* p);
node* removemax(node* p); // удаление узла с минимальным ключом из дерева p
node* remove(node* p, int k); // удаление ключа k из дерева p




void show(node* root, int space = 0);
void find_by_technic(node* tree, string technic);
void serch(node* tree, int key);
void walk(node* tree);

#endif