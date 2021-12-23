/**
 * Ryan Grayson
 * rtg5xkh
 * InLab 5
 * 3/20/2021
 * BinaryNode.cpp
 */

#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::BinaryNode(string val) {
    value = val;
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
