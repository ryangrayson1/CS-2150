/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 5
 * 3/19/2021
 */
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  if (!expressionStack.empty()){
      cleanTree(expressionStack.top());
      expressionStack.pop();
  }
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if (tree != nullptr){
    if (tree->left != nullptr)
      cleanTree(tree->left);
  
    if (tree->right != nullptr)
      cleanTree(tree->right);
  
    delete tree;
  }

}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if (val == "+" || val == "-" || val == "/" || val == "*"){
    TreeNode* t1 = expressionStack.top();
    expressionStack.pop();
    TreeNode* t2 = expressionStack.top();
    expressionStack.pop();

    TreeNode* t3 = new TreeNode(val);
    t3->left = t2;
    t3->right = t1;
    expressionStack.push(t3);
  }
  else
    expressionStack.push(new TreeNode(val));
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  cout << tree->value << " ";

  if (tree->left != nullptr)
    printPrefix(tree->left);

  if (tree->right != nullptr)
    printPrefix(tree->right);
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses

  if (tree->left != nullptr){
    cout << "(";
    printInfix(tree->left);
  }

  if (tree->value == "+" || tree->value == "-" || tree->value == "*" || tree->value == "/")
    cout << " " << tree->value << " ";
  else
    cout << tree->value;
  
  if (tree->right != nullptr){
    printInfix(tree->right);
    cout << ")";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if (tree->left != nullptr)
    printPostfix(tree->left);

  if (tree->right != nullptr)
    printPostfix(tree->right);

  cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result

  if (tree == nullptr)
    return 0;

  if (tree->value == "+")
    return calculate(tree->left) + calculate(tree->right);
  else if (tree->value == "-")
    return calculate(tree->left) - calculate(tree->right);
  else if (tree->value == "*")
    return calculate(tree->left) * calculate(tree->right);
  else if (tree->value == "/")
    return calculate(tree->left) / calculate(tree->right);
  else
    return stoi(tree->value);
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int result = calculate(expressionStack.top());
  cleanTree(expressionStack.top());
  expressionStack.pop();
  return result;
}
