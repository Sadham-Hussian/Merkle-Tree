#include "Merkle_Tree.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

char* string_to_uschp(string s);

Merkle_Tree::Merkle_Tree() : Binary_Tree()
{

}

Merkle_Tree::Merkle_Tree(int value) : Binary_Tree(value)
{

}

unsigned long long int* Merkle_Tree::create_merkle_tree(char** msg_packets, int split_size)
{
	int no_of_strings = split_size;
	int no_of_nodes = (2 * no_of_strings);
	unsigned long long int *node_array = new unsigned long long int[no_of_nodes + 1];

	for(int i=1; i<= (no_of_nodes - (no_of_nodes/2)) - 1; i++)
	{
		node_array[i] = i + 1;
	}
	int index_counter = 0;

	for(int i = (no_of_nodes - (no_of_nodes/2)) - 1; i < no_of_nodes; i++)
	{
		node_array[i] = hash_generator(msg_packets[index_counter++]);
	}

	for(int i=1; i < no_of_nodes - 1; i++)
	{
		insert(node_array[i])
	}
	generate_master_hash( get_root() );
	unsigned long long int *hash_array = new unsigned long long int[no_of_nodes + 1];
	struct Node *ptr = get_root();
	queue <struct Node*> node_queue;
	index_counter = 1;

	while(ptr)
	{
		hash_array[index_counter++] = ptr->key;
		if(ptr->lchild != NULL)
		{
			node_queue.push(ptr->lchild);
		}
		if(ptr->rchild != NULL)
		{
			node_queue.push(ptr->rchild);
		}
		ptr = node_queue.front();
		node_queue.pop();
	}

	return hash_array;
}