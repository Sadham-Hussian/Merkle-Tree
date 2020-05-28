#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

struct Node
{
	unsigned long long int key;
	struct Node* left_child;
	struct Node* right_child;
};

class Binary_Tree
{
	private:
		struct Node* root;
		struct Node* current_root;
		queue <struct Node*> node_queue;
		int count;
		void insert_key(unsigned long long int);
}

#endif