/**
 * Ryan Grayson
 * rtg5xkh
 * PostLab 5
 * 3/22/2021
 * AVLNode.h
 */

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
  AVLNode(string val);
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif
