/**
 * Ryan Grayson
 * rtg5xkh
 * PostLab 5
 * 3/22/2021
 * AVLNode.cpp
 */

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(string val) {
    value = val;
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
