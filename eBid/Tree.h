//============================================================================
// Name        : Tree.h
// Author      : Andrew Swarr
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Header file for the Binary Search Tree which introduces the BinarySearchTree class.
//============================================================================

#pragma once

#include <iostream>
#include <Tree.cpp>
#include <string.h>
#include <stdafx.h>
using namespace std;

class BinarySearchTree { //Define global class

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};