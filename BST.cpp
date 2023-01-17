// This file contains the implementation
// for the binary search tree class.

#include <iostream>
#include "BST.h"


using namespace std;


void BST::inOrder( tree_node* root ) {
    if ( root != NULL ) {
        inOrder( root->left );
        cout << root->word << " " << root->data<< " " << endl;
        inOrder( root->right );
    }
}

int BST::distinctWordsHelp (tree_node* root) {
  if (root == NULL) {
    return 0;
  } else {
    return 1 + distinctWordsHelp(root->left) + 
            distinctWordsHelp(root->right);
  }
}
int BST::totalWordsHelp(tree_node* root) {
  if (root==NULL) {
    return 0; 
  } else {
    return root->data + totalWordsHelp(root->left) + 
      totalWordsHelp(root->right);
  }
}
void switchData(int &a, int &b) {
  a += b;
  b = a - b;
  a -= b;
}
void highWordsHelp(tree_node *root, list_node *&list_root) {
  if (root != NULL) {

    list_node *add = new list_node;
    
    add->data = root->data;
    
    add->word = root->word;

    if (list_root == NULL) {
      list_root = add;
      } else {
      list_node *temp = list_root;
      list_node *prev = temp;

      while ((temp != NULL) && (temp->data <= root->data)) {
        prev = temp;
        temp = temp->next;
      }

      if (temp == NULL) {
        prev->next = add;
        } else if (prev != temp) {
        prev->next = add;
        add->next = temp;
      } else {
        add->next = list_root->next;
        list_root->next = add;
        switchData(list_root->data, add->data);
      }
    }

    highWordsHelp(root->left, list_root);
    highWordsHelp(root->right, list_root);
  }
}
//print the linkedlist stored with 10 highest words backwards;
void list_print(list_node *root, int &n) {
  if (root != NULL) {
    
    list_print(root->next, n);
    
    cout << root->word << " " << root->data << endl;
    
    n++;
    
    if (n == 10) {
      exit(0);
      }
    }
}

void BST::highWords() {
  list_node *list_root = NULL;

  highWordsHelp(theRoot, list_root);

  int n = 0;
  
  list_print(list_root, n);
}

int BST::totalWords() {
  return totalWordsHelp(theRoot);
}
int BST::distinctWords() {
  return distinctWordsHelp(theRoot);
}

BST::BST( ) {
    theRoot = NULL;
}


bool BST::find( string str ) {
    tree_node* temp = theRoot;

    while ( temp != NULL ) {
        if ( str == temp->word ) {
            temp->data++;
            return true;
          }
        else if ( str < temp->word ) {
            temp = temp->left;
          }
        else
            temp = temp->right;
    }
    return false;
}


void BST::insert( string str ) {
    tree_node* add = new tree_node;
    add->word = str;
    add->data = 1;
    add->left = NULL;
    add->right = NULL;

    if ( theRoot == NULL ) {
        theRoot = add;
        return;
    }

    tree_node* prev = theRoot;
    tree_node* temp;

    if ( str < prev->word )
        temp = prev->left;
    else
        temp = prev->right;

    while ( temp != NULL ) {
        prev = temp;
        if ( str < temp->word )
            temp = temp->left;
        else
            temp = temp->right;  
    }

    if ( str < prev->word )
        prev->left = add;
    else
        prev->right = add;
}

void BST::print( ) {
    inOrder( theRoot );
    cout << endl;
}
