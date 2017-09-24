#include "Node.h"
class AVL {
private:
	Node* root;
	int count;
	
public:
	AVL();
	~AVL();
	
	// BST PURE
	// PART 1 - SETUP
	Node* getRootNode();
	// PART 2 - ADD
	bool add(int data, int line);
	Node* recursiveAdd(int data, int line, Node* current_search);
	Node* contains(int data, Node* current_search);
	void print(Node* current_print);
	// PART 3 - REMOVE
	void remove(int data);
	Node* recursiveRemove(int data, Node* current_search);
	Node* IOP(Node* current_search, Node* node_to_remove);
	// PART 4 - MEMORY CLEANUP
	void clear();

	// AVL FUNCTIONS
	int height(Node* node_query);
	void fixHeight(Node* parent);
	int heightDiff(Node* parent);
	int pred(int data, Node* current_search);
	int succ(int data, Node* current_search);
	Node* balance(Node* parent);
	Node* rotateRight(Node* pivot);
	Node* rotateLeft(Node* pivot2);
	Node* getMin(Node* parent);
	Node* removeMin(Node* parent);
	int size();
	
};
