#include "ads-trees/BinaryTrees.h"
#include <stdlib.h>
#include <stdio.h>

// The prototipe says everything
tree* create_new_node(int v)
{
	tree* new_node = (tree*)malloc(sizeof(tree));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->info = v;

	return new_node;
}

// I assume that "t" is a binary search tree
tree* insert_BST(tree* t, int v)
{
	if (t == NULL)
	{
		t = create_new_node(v);
		return t;
	}
	
	if (t->info < v)
		t->left = insert_BST(t->left, v);
	else
		t->right = insert_BST(t->right, v);
	
	return t;

}

// Prints the tree 90 degrees counter clockwise
void print_tree(tree* t,int space)
{
    if (t == NULL) 
        return; 
  
    // Increase distance between levels 
    space += 10; 
  
    print_tree(t->right, space); 
  
    // Print current node after space 
    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%d\n", t->info); 
  
    print_tree(t->left, space); 
}

// Returns the total number of nodes
int get_num_nodes(tree* t)
{
	if (t == NULL)
		return 0;
	int l = get_num_nodes(t->left);
	int r = get_num_nodes(t->right);
	
	return 1+l+r;
}

// Returns the total number of leaves
int get_num_leaves(tree* t)
{
	if (t == NULL)
		return 1;
	if (t->left == NULL && t->right == NULL)
		return 1;
	else
		return get_num_leaves(t->left) + get_num_leaves(t->right);
}

// Returns the maximum height
int get_height(tree* t)
{
	if (t == NULL)
		return -1;
	int l = get_height(t->left);
	int r = get_height(t->right);

	if (l > r)
		return l+1;
	else
		return r+1;
}

// Simply returns the leftmost value
int get_max_BST(tree* t)
{
	while (t->left != NULL)
		t = t->left;
	
	return t->info;
}

// Given a non-BST, returns the maximum value
int get_max(tree* t)
{
	if (t == NULL)
		return -1;
	
	int root_max = t->info;
	int left_max = get_max(t->left);
	int right_max = get_max(t->right);

	if (left_max > root_max)
		root_max = left_max;
	if (right_max > root_max)
		root_max = right_max;
	
	return root_max;
}

// Returns an array containing the path from the root node down to the node with value "v"
int* get_path(tree* t, int v)
{
	if (t == NULL)
		return NULL;
	
	int* path = (int*)calloc(1,sizeof(int));
	int i = 0;
	while (t != NULL)
	{
		path[i] = t->info;

		if (t->info == v)
			return path;
		if (t->info < v)
			t = t->left;
		else 
			t = t->right;
		
		i++;
		path = (int*)realloc(path,i);
	}
	free(path);
	return NULL;
}

// Finds a value using preorder traversal
_Bool find_preorder(tree* t,int v)
{
	if (t == NULL)
	{
		printf("Could not find any value\n");
		return 0;
	}

	if (t->info == v)
		return 1;
	
	if (t->info > v)
		return find_preorder(t->right, v);
	else
		return find_preorder(t->left, v);

}

_Bool are_equal(tree* t1, tree* t2)
{
	if (t1 == NULL) && (t2 == NULL) return 1;
	if (t1 == NULL) || (t2 == NULL) return 0;
	if (t1->info != t2->info) return 0;
	
	return are_equal(t1->left, t2->left) && are_equal(t1->right, t2->right);
}

// Checks if a tree is complete
_Bool is_complete(tree* t)
{
	int h = get_height(t);
	int l = get_num_leaves(t);
	return power(2,h) == l;
}

// Utility func
int power(int b, int exp)
{
	if (exp == 0)
		return 1;
	else
		return b * power(b,exp-1);
}
