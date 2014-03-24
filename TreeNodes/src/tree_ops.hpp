/*
 * homework411_treeset.hpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Scott
 */

#ifndef CS263_GVTreeSet
#define CS263_GVTreeSet
#include <stdexcept>
#include <ostream>
#include <vector>
#include <queue>

using namespace std;
namespace gvsu {
template<typename Z>
class TreeSet {
private:
	class Node;
	/* instance variables */
	Node *rootPtr; /* poiter to the root node */
	/* inner class(es) */
	struct Node { /* struct: is a class with public members */
		Z data;
		Node *parent; /* pointer to immediate parent */
		Node *left;
		Node *right;

	};
public:
	class const_iterator;
	/* member functions */

	TreeSet() {
		rootPtr = nullptr;
	}

	~TreeSet() {
		clearAll(rootPtr);
	}

	/* copy constructor => O(N) */
	TreeSet(const TreeSet& twin) {
		rootPtr = duplicate(twin.rootPtr);
	}

	TreeSet(TreeSet&& twin) {
		rootPtr = twin.rootPtr;
		twin.rootPtr = nullptr;
	}

	int numberOfNodes() const {
		return count(rootPtr);
		/* in your recursive private function, make sure to avoid duplicate recursive calls */

	}

	int numberOfLeaves() const {
		/* in your recursive private function, make sure to avoid duplicate recursive calls */
		return leafCount(rootPtr);
	}

	int numberOfFullNodes() const {
		/* in your recursive private function, make sure to avoid duplicate recursive calls */
		if(leafCount(rootPtr)>0){
			return leafCount(rootPtr)-1;
		}else
			return 0;


	}

	/* copy assignment */
	TreeSet& operator=(const TreeSet& rhs) {
		clearAll(rootPtr); /* required to avoid mem leak */
		rootPtr = duplicate(rhs.rootPtr);
		return *this;
	}

	/* move assignment */
	TreeSet& operator=(TreeSet&& rhs) {
		clearAll(rootPtr);
		this->rootPtr = rhs.rootPtr;
		rhs.rootPtr = nullptr;
		return *this;
	}

	const Z& findMax() const {
		if (rootPtr != nullptr) {
			Node *p = Max(rootPtr);
			return p->data;
		} else
			throw runtime_error("can't findMax() on empty tree");
	}

	bool contains(const Z& key) const {
		return contains(key, rootPtr);
	}

	bool insert(const Z& key) {
		return insert(key, rootPtr);
	}

	void remove(const Z& key) {
		remove(key, rootPtr);

	}

	vector<Z> levelOrder() const {
		return levelOrder(rootPtr);
	}


	void print(ostream& os = std::cout) const {
		print(rootPtr, os, "");
	}

	const_iterator begin() {
		Node* n = rootPtr;
		if (n != nullptr) {
			while (n->left != nullptr) {
				n = n->left;
			}
		}
		return const_iterator(n);

	}

	const_iterator end() {
		return const_iterator(nullptr);
	}

private:



	Node * duplicate(Node *theOtherNode) {
		Node* newNode;
		if (theOtherNode != nullptr) {
			newNode = new Node;
			newNode->data = theOtherNode->data;
			newNode->parent = theOtherNode->parent;
			newNode->left = duplicate(theOtherNode->left);
			newNode->right = duplicate(theOtherNode->right);
		} else
			return nullptr;
		return newNode;

	}

	void clearAll(Node* & pos) // remove all the nodes from this tree
			{
		if (pos != nullptr) {
			clearAll(pos->left);
			clearAll(pos->right);
			delete pos;
			pos = nullptr;
		}

	}

	void print(Node *pos, ostream& os, const string&& path) const {
		if (pos) {
			print(pos->left, os, path + "L");
			os << pos->data << " (" << path << ")" << endl;
			print(pos->right, os, path + "R");
		}
	}
	int count(Node * t) const {
		int i;
		if (t == nullptr)
			return (0);
		else {
			i = 1 + count(t->left) + count(t->right); //counts root then left and right
		}
		return (i);
	}
	int leafCount(struct Node *node) const {
		if (node == nullptr)				//tree is empty
			return 0;
		if (node->left == nullptr && node->right == nullptr)	//if no children
			return 1;
		else
			return leafCount(node->left) + leafCount(node->right);
	}

	int FullNodes(Node* root) const {

		if (root->left != nullptr && root->right != nullptr) {
			return 1 + FullNodes(root->left) + FullNodes(root->right);

		} else if (root->left == nullptr && root->right != nullptr) {//no left child so it moves right
			return FullNodes(root->right);
		} else {							//no right child so it moves left
			return FullNodes(root->left);
		}

	}

	bool insert(const Z& key, Node* & pos) {

		if (pos == nullptr) {
			pos = new Node;
			pos->data = key;
			pos->left = pos->right = pos->parent = nullptr;
			return true;
		} else if (key < pos->data) {
			if (pos->left != nullptr) {
				insert(key, pos->left);
			} else {
				Node* n = new Node;
				n->data = key;
				n->parent = pos;
				n->right = n->left = nullptr;
				pos->left = n;
				return true;
			}
		} else if (key > pos->data) {
			if (pos->right != nullptr) {
				insert(key, pos->right);
			} else {
				Node* n = new Node;
				n->data = key;
				n->parent = pos;
				n->right = n->left = nullptr;
				pos->right = n;
				return true;
			}
		}
		return false;


	}

	void remove(const Z& key, Node* & pos) {
		if (pos == nullptr)
			return;
		if (key != pos->data) {
			if (key > pos->data)
				remove(key, pos->right);
			else if (key < pos->data)
				remove(key, pos->left);
		} else {
			if (pos->left != nullptr && pos->right != nullptr) {
				Node *maxFromLeft = Max(pos->left);
				pos->data = maxFromLeft->data;
				remove(maxFromLeft->data, pos->left);
			} else if (pos->left != nullptr) {
				pos->left->parent = pos->parent;
				pos = pos->left;
			} else if (pos->right != nullptr) {
				pos->right->parent = pos->parent;
				pos = pos->right;
			} else {
				delete pos;
				pos = nullptr;
			}
		}

	}

	vector<Z> levelOrder(Node* root) const {
		vector<Z> v;
		queue<Node*> q;

		// Push the root
		q.push(root);

		while (!q.empty()) {
			// Dequeue a node from front
			Node* n = q.front();
			v.push_back(n->data);

			// Enqueue the left children
			if (n->left != nullptr)
				q.push(n->left);

			// Enqueue the right children
			if (n->right != nullptr)
				q.push(n->right);

			// Pop the visited node
			q.pop();
		}
		return v;
	}

	Node *Max(Node *root) const {
		if (root == nullptr)
			return nullptr;
		Node *r = root;
		while (r->right != nullptr)
			r = r->right;
		return r;

	}

	bool contains(const Z& key, Node* currentPos) const {
		if (currentPos == nullptr)
			return false;
		if (key == currentPos->data)
			return true;
		if (key > currentPos->data)
			return contains(key, currentPos->right);
		return contains(key, currentPos->left);

	}

public:
	class const_iterator {
	public:
		Node *current;

		const_iterator(Node *n) :
				current { n } {

		}

		/* copy assignment */
		const_iterator operator=(const const_iterator& rhs) {
			this->current = rhs.current;
			return *this;
		}

		bool operator ==(const const_iterator& rhs) const {
			return (this->current == rhs.current);
		}
		bool operator !=(const const_iterator& rhs) const {
			return (this->current != rhs.current);
		}

		/* Update the current pointer to advance to the node
		 * with the next larger value
		 */
		const_iterator& operator++() {
			Node* p;
			if (current == nullptr) {
				current = this->current;
				while (current->left != nullptr) {
					current = current->left;
				}
			} else if (current->right != nullptr) {
				current = current->right;
				while (current->left != nullptr) {
					current = current->left;
				}
			} else {
				p = current->parent;
				while (p != nullptr && current == p->right) {
					current = p;
					p = p->parent;
				}
				current = p;
			}
			return *this;

		}

		Z& operator *() const {
			return current->data;
		}
	};
};

template<typename Z>
ostream& operator<<(ostream& os, const TreeSet<Z>& t) {
	t.print(os);
	return os;
}

}

#endif
