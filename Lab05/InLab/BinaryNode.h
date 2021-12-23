/**
 * Ryan Grayson
 * rtg5xkh
 * InLab 5
 * 3/20/2021
 * BinaryNode.h
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
    BinaryNode(string val);
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
