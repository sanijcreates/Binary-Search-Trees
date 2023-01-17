#include <fstream>
#include "BST.h"
#include <iostream>


using namespace std;
int main( ) {

    BST tree;
  
    cout << "Welcome to my program!" << endl;
    cout << "Please enter a file name" << endl;
    string file;
    cin>>file;
    ifstream input;
    input.open(file);
  
    if (!input) {
      cout <<"Error - cannot open file" <<endl;
      exit(1);
    }
  
   string str;
   
   while(input >> str) {
     if (tree.find(str) == false) {
       tree.insert(str);
     }
  }
  tree.print();

  cout << "The total number of words are "<< tree.totalWords()<< endl;

  int distinctWords = tree.distinctWords();
  cout << "The total distinct words in the file are "<<       
  distinctWords<< endl;

  if (distinctWords < 10) {
    cout << "The file has less than 10 words." << endl;
    } else {
    cout << "The highest number of ten words in the file are:" << endl;
    tree.highWords();
  }
}