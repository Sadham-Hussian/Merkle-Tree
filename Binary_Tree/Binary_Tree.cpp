#include "Binary_Tree.h"
#include <iostream>
#include <queue>

using namespace std;

Binary_Tree::Binary_Tree()
{
	this->root = new_node(1);
	this.count = 1;
}

Binary_Tree::Binary_Tree(int value)
{
	this->root = new_node(value);
	this->count = 1;
	node_queue.push(root);
	current_root = node_queue.front();
}

Binary_Tree::~Binary_Tree()
{

}