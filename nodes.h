// This file contains the definitions
// for the nodes used in linked lists
// and in trees.

#ifndef _NODES
#define _NODES
#include <string>

using namespace std;
//For BST
struct tree_node {
    public:
        int data;
        string word;
        tree_node* left;
        tree_node* right;
};

//For LinkedList;
struct list_node {
public:
  string word;
  int data;
  list_node *next;
};
#endif