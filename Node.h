#pragma once
#include <iostream>

class Node {
friend class AVL;
private:
	int data;
	int height;
	int line;
	Node* left_child;
	Node* right_child;

public:
	Node();
	~Node();

// ANALYZERS
	int getData();
	int getHeight();
	int getLine();
	Node* getLeftChild();
	Node* getRightChild();
};

