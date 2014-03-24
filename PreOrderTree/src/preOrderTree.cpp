//============================================================================
// Name        :preOrderTree.cpp
// Author      : Scott Dreyer
//
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * I created a very basic tree class that will insert char's, clear the tree,
 * build the tree(from a string) and print the pre-level order.
 *
 */
class Tree {
private:
	class Node;

	Node *rootPtr;

	struct Node {
		char data;
		Node *parent;
		Node *left;
		Node *right;

	};

public:
	Tree() {
		rootPtr = 0;
	}

	bool insert(char key, Node* & pos) {

		if (pos == 0) {
			pos = new Node;
			pos->data = key;
			pos->left = pos->right = pos->parent = 0;
			return true;
		} else if (key < pos->data) {
			if (pos->left != 0) {
				insert(key, pos->left);
			} else {
				Node* n = new Node;
				n->data = key;
				n->parent = pos;
				n->right = n->left = 0;
				pos->left = n;
				return true;
			}
		} else if (key > pos->data) {
			if (pos->right != 0) {
				insert(key, pos->right);
			} else {
				Node* n = new Node;
				n->data = key;
				n->parent = pos;
				n->right = n->left = 0;
				pos->right = n;
				return true;
			}
		}
		return false;

	}
	void clearAll(Node* & pos) // remove all the nodes from this tree
			{
		if (pos != 0) {
			clearAll(pos->left);
			clearAll(pos->right);
			delete pos;
			pos = 0;
		}

	}
	void printTreePreOrder(Node* node) {
		if (node == NULL)
			return;

		cout << node->data << "";
		printTreePreOrder(node->left);
		printTreePreOrder(node->right);
	}
	void buildTree(string str){

		for(unsigned int i=0;i<str.length();i++){
			insert(str.at(i),rootPtr);
		}

		printTreePreOrder(rootPtr);
		cout<<""<<endl;
	}

};

int main(int argc, const char * argv[]) {
	ifstream input(argv[1]);
	vector<string> leaf;
	string allLeaves;
	string leaves;

	do {
		input >> leaves;
		allLeaves = "";

		while (leaves != "*" && leaves != "$") {

			allLeaves+=leaves;

			input >> leaves;

		}
		reverse(allLeaves.rbegin(),allLeaves.rend());

		Tree myTree= Tree();
		myTree.buildTree(allLeaves);
	} while (leaves != "$");



	return 0;
}
