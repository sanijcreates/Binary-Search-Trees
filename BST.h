 // This file contains the interface for the 
// binary search tree class.

#include "nodes.h"
#include <string>

class BST {
  private:
    // The root of the binary search tree.
    tree_node* theRoot;



    void inOrder( tree_node* root );
 
  public:
    BST( );

    void insert( string str );

    bool find(string str );

    int distinctWordsHelp(tree_node* root);

    int distinctWords();

    void print( );

    int totalWordsHelp(tree_node* root);

    int totalWords();

    void highWords();

};
