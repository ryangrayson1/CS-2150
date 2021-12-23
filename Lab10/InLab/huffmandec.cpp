/**
 * Ryan Grayson
 * rtg5xkh
 * InLab 10
 * huffmandec.cpp
 * 4/22/2021
 */

// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffnode.h"
using namespace std;

void makeHuffman(huffnode* &root, string code, string charac);
char decode(huffnode* huff, string code);

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffnode* root = new huffnode();

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code

	makeHuffman(root, prefix, character);
    }

    // read in the second section of the file: the encoded message
    //stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }

	cout << decode(root, bits);
    }
    
    //string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    cout << endl;

    delete root;

    return 0;
}

void makeHuffman(huffnode* &root, string code, string charac){

  if (code == ""){
    root->value = charac[0];
  }

  else if (code[0] == '0'){
    if (root->left == nullptr)
      root->left = new huffnode();

    code = code.substr(1, code.length());
    
    makeHuffman(root->left, code, charac);
  }

  else if (code[0] == '1'){
    if (root->right == nullptr)
      root->right = new huffnode();
    
    code = code.substr(1, code.length());
    
    makeHuffman(root->right, code, charac);
  }
}

char decode(huffnode* huff, string code){
  if ((huff->right == nullptr && huff->left == nullptr))
    return huff->value;

  else if (code[0] == '0'){
    
    code = code.substr(1, code.length());
    
    return decode(huff->left, code);
  }

  else if (code[0] == '1'){

    code = code.substr(1, code.length());
     
    return decode(huff->right, code);
  }

  return huff->value;
}
