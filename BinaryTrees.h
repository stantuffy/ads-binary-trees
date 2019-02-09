#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

struct node
{
	struct node* left;
	struct node* right;
	int info;
};

typedef struct node tree;

tree* create_new_node(int v);

tree* insert_BST(tree* t, int v);

void print_tree(tree* t,int space);

int get_num_nodes(tree* t);

int get_nodes_at_level(tree* t);

int get_num_leaves(tree* t);

int get_height(tree* t);

int get_max_BST(tree* t);

int get_max(tree* t);

int* get_path(tree* t, int v);

_Bool find_preorder(tree* t, int v);

_Bool is_complete(tree* t);

_Bool are_equal(tree* t1, tree* t2);

int power(int b, int exp);

#endif
