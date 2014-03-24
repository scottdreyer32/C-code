/*
 * Scott Dreyer
 */
#ifndef CS263_GVSUList_hpp
#define CS263_GVSUList_hpp
#include <utility>
#include <initializer_list>
namespace gvsu {

template<typename Z>
class list {

	/* forward declaration of inner classes */
	class Node;
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
	;
private:
	int theSize;
	Node *head;
	Node *tail;

public:

	list() { /* constructor */
		theSize = 0;

		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
	}


	list(std::initializer_list<Z> values) :
			list() {
		for (auto x = values.begin(); x != values.end(); ++x)
			push_back(*x);
	}

	~list() {
		while (!isEmpty())
			pop_front();
		delete head;
		delete tail;
	}
	/**
	 * copy const.
	 */
	list(const list& twin) {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
		for (auto & x : twin) {
			push_back(x);
		}
	}
	/**
	 * Move const
	 */
	list(list && twin) :
			theSize { twin.theSize }, head { twin.head }, tail { twin.tail } {
		twin.head = nullptr;
		twin.tail = nullptr;
	}
	/**
	 * copy assignment
	 */
	list & operator=(const list & twin) {
		list copy = twin;
		std::swap(*this, copy);
		return *this;
	}

	/**
	 * move assignment
	 */
	list & operator=(list && twin) {
		std::swap(head, twin.head);
		std::swap(tail, twin.tail);

		return *this;
	}

	bool isEmpty() const {
		return head->next == tail;
	}

	void push_back(const Z& item) {
		Node *S = new Node;
		S->data = item;
		S->prev = tail->prev;
		S->next = tail;
		tail->prev->next = S; /* next of K */
		tail->prev = S;
	}

	void pop_front() {
		if (!isEmpty()) {
			Node *discarded = head->next;
			head->next = discarded->next;
			discarded->next->prev = head;
			delete discarded;
		}
	}

	/* iterators */
	iterator begin() {
		return iterator(head->next);
	}
	iterator end() {
		return iterator(tail);
	}
	const_iterator begin() const {
		return const_itearator(head->next);
	}
	const_iterator end() const {
		return const_iterator(tail);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(tail->prev);
	}
	reverse_iterator rend() {
		return reverse_iterator(head);
	}
	const_reverse_iterator rbegin() const {
		return const_revIterator(tail->prev);
	}
	const_reverse_iterator rend() const {
		return const_revIterator(head);
	}
	const Z& operator[](int a) const {
		if (a < 0) {
			reverse_iterator revItr = this->tail;
			for (int i = 0; i > a; i--) {
				--revItr;

			}
			return *revItr;
		} else {
			iterator itr = this->head->next;
			for(int i = 0; i<a; i++){
				++itr;
			}
			return *itr;
		}
	}
};

template<typename Z>
class list<Z>::Node {
public:
	Z data;
	Node *next; /* singly-linked list */
	Node *prev; /* doublyy-linked list */
};


template<typename Z>
class list<Z>::iterator {
private:
	Node *currentNode;
public:
	iterator(Node *n) {
		currentNode = n;
	}
	bool operator !=(const iterator& rhs) const {
		return this->currentNode != rhs.currentNode;
	}

	bool operator ==(const iterator& rhs) const {
		return this->currentNode == rhs.currentNode;
	}

	void operator++() {
		currentNode = currentNode->next;
	}
	void operator--(){
		currentNode = currentNode->prev;
	}
	Z& operator*() {
		return currentNode->data;
	}

};
template<typename Z>
class list<Z>::reverse_iterator {
private:
	Node *currentNode;
public:
	reverse_iterator(Node *n) {
		currentNode = n;
	}
	bool operator !=(const reverse_iterator& rhs) const {
		return this->currentNode != rhs.currentNode;
	}

	bool operator ==(const reverse_iterator& rhs) const {
		return this->currentNode == rhs.currentNode;
	}

	void operator++() {
		currentNode = currentNode->next;
	}
	void operator--(){
		currentNode = currentNode->prev;
	}
	Z& operator*() {
		return currentNode->data;
	}

};
}

#endif
