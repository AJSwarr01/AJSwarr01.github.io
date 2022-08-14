//============================================================================
// Name        : Tree.cpp
// Author      : Andrew Swarr
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : C++ file to accompany Tree.h which stores the definitions of the Binary Search Tree itself and all CRUD functions
//============================================================================

#include <Tree.h>
#include <time.h>
#include<algorithm>
#include <string>

#include "CSVparser.hpp"

double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
	string bidId; // unique identifier
	string title;
	string fund;
	double amount;
	Bid() {
		amount = 0.0;
	}
};

struct Node {
	Bid bid;
	Node* left;
	Node* right;

	//Default for constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	//Constructor for initial bid
	Node(Bid aBid) : Node() {
		this->bid = aBid;
	}
};

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

// * Destructor
BinarySearchTree::~BinarySearchTree() {
	// recurse from root deleting every node
}

 //* Traverse the tree in order
void BinarySearchTree::InOrder() {
}

// Insert a bid
void BinarySearchTree::Insert(Bid bid) {
	// FIXME (2a) Implement inserting a bid into the tree
	if (root == nullptr) {
		root = new Node(bid);
	}
	else {
		this->addNode(root, bid);
	}
}

// Remove a bid
void BinarySearchTree::Remove(string bidId) {
	// FIXME (4a) Implement removing a bid from the tree
	this->removeNode(root, bidId);
}

// Search for a bid
Bid BinarySearchTree::Search(string bidId) {
	Node* current = root;
	while (current != nullptr) {\
		if (current->bid.bidId.compare(bidId) == 0) {
			return current->bid;
		}
		if (current->bid.bidId.compare(bidId) < 0) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	Bid bid;
	return bid;
}

// Add node to tree
void BinarySearchTree::addNode(Node* node, Bid bid) {
	if (node->bid.bidId.compare(bid.bidId) > 0) {
		if (node->left == nullptr) {
			node->left = new Node(bid);
		}
		else {
			this->addNode(node->left, bid);
		}
	}
	else {
		if (node->right == nullptr) {
			node->right = new Node(bid);
		}
		else {
			this->addNode(node->right, bid);
		}
	}
}
void BinarySearchTree::inOrder(Node* node) {
	if (node != nullptr) {
		inOrder(node->left);
		cout << node->bid.bidId << ": "
			<< node->bid.title << " | "
			<< node->bid.amount << " | "
			<< node->bid.fund << endl;
		inOrder(node->right);
	}
}

Node* BinarySearchTree::removeNode(Node* node, string bidId) {
	// if tree is empty
	if (node == nullptr) {
		return node;
	}
	// left tree search
	if (bidId.compare(node->bid.bidId) < 0) {
		node->left = removeNode(node->left, bidId);
	}
	// right tree search
	else if (bidId.compare(node->bid.bidId) > 0) {
		node->right = removeNode(node->right, bidId);
	}
	// no children
	else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		// use child to the left
		else if (node->left != nullptr && node->right == nullptr) {
			Node* temp = node;
			node = node->left;
			delete temp;
		}
		// use child to the right
		else if (node->right != nullptr && node->left == nullptr) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}
		// two children
		else {
			Node* temp = node->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			node->bid = temp->bid;
			node->right = removeNode(node->right, temp->bid.bidId);
		}
	}
	return node;
}
void displayBid(Bid bid) {
	cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
		<< bid.fund << endl;
	return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
	cout << "Loading CSV file " << csvPath << endl;

	// initialize the CSV Parser using the given path
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	vector<string> header = file.getHeader();
	for (auto const& c : header) {
		cout << c << " | ";
	}
	cout << "" << endl;

	try {
		// loop to read rows of a CSV file
		for (unsigned int i = 0; i < file.rowCount(); i++) {

			// Create a data structure and add to the collection of bids
			Bid bid;
			bid.bidId = file[i][1];
			bid.title = file[i][0];
			bid.fund = file[i][8];
			bid.amount = strToDouble(file[i][4], '$');

			//cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

			// push this bid to the end
			bst->Insert(bid);
		}
	}
	catch (csv::Error& e) {
		std::cerr << e.what() << std::endl;
	}
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
	str.erase(remove(str.begin(), str.end(), ch), str.end());
	return atof(str.c_str());
}