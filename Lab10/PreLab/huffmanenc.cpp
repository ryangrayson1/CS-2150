/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 10
 * huffmanenc.cpp
 * 4/20/2021
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <map>
#include "huffnode.h"
#include "heap.h"
using namespace std;

void codes(string code, huffnode* root, map<char, string> &m);

int main(int argc, char** argv) {
  
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter!" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    heap h;
   
    int freq[128];
    for (int i = 0; i < 128; i++)
      freq[i] = 0;

    char c;
    while (file.get(c) ) {
        if ( (c < 32) || (c > 126) )
            continue;
	
        freq[(int)c]++;
    }

    int distinct = 0;
    for(int i = 0; i < 128; i++){
      if (freq[i] > 0){
	huffnode* newNode = new huffnode(i, freq[i]);
	h.insert(newNode);
	distinct++;
      }
    }

    //build huffman tree
    
    while(h.getSize() > 1){
      huffnode* t = new huffnode();
      
      t->frequency += h.findMin()->frequency;
      t->left = h.findMin();
      h.deleteMin();
      
      t->frequency += h.findMin()->frequency;
      t->right = h.findMin();
      h.deleteMin();

      h.insert(t);
    }

    //save all of the codes
    map<char, string> m;

    codes("", h.findMin(), m);

    //SECTION 2
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    int symbols = 0;
    char g;
    string encoded = "";
    // Read the file again
    while (file.get(g)) {
      if ( (g < 32) || (g > 126) )
	continue;
      
      symbols++;
      cout << m.at(g) << " ";
      encoded += m.at(g);
    }

    // close the file
    file.close();

    //SECTION 3
    cout << endl << "----------------------------------------" << endl;

    cout << "There are a total of " << symbols << " symbols encoded." << endl;
    cout << "There are " << distinct << " distinct symbols used." << endl;
    cout << "There were " << symbols * 8 << " bits in the original file." << endl;
    cout << "There were " << encoded.length() << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (symbols * 8.0) / (encoded.length() * 1.0) << "." << endl;
    cout << "The cost of the Huffman tree is " << encoded.length() / (symbols * 1.0) << " bits per character." << endl;


    //memory reclaim
    delete h.findMin();
    h.makeEmpty();
    return 0;
}

void codes(string code, huffnode* root, map<char, string> &m){
  if (root == nullptr)
    return;

  if (root->value != 0){
    m.insert({(char)root->value, code});

    if (root->value == ' ')
      cout << "space " << code << endl;
    
    else
      cout << root->value << " " << code << endl;
    
  }
  
  else{
    codes(code + "0", root->left, m);
    codes(code + "1", root->right, m);
  }
}
