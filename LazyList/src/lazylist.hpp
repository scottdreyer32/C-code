/*
 * Scott Dreyer
 */
#ifndef CS263_LAZY_LIST_H
#define CS263_LAZY_LIST_H
#include <utility>


namespace gvsu {
template<typename Z>
class lazylist {
public:
	class iterator; /* forward declaration of inner classes */
private:
	class Node; /* forward declaration of inner classes */
	Node *head;
	Node *tail;
	int theSize;
	int num_deleted, num_nondeleted;
	bool deleted;
public:
	lazylist() { /* constructor */
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
		head->deleted = false;
		tail->deleted = false;
		num_deleted = 0;
		num_nondeleted = 0;
		theSize = 0;
	}


	lazylist(std::initializer_list<Z> values) :
			lazylist() {
		for (auto x = values.begin(); x != values.end(); ++x)
			push_back(*x);
	}

	~lazylist() {
		while (!isEmpty()) {
			pop_back_delete();
			delete head;
			delete tail;
		}
	}

	bool isEmpty() const {
		return size() == 0;
		//return head->next == tail;
	}

	int size() const {
		return num_nondeleted;
	}

	void push_back(const Z& item) {
		Node *S = new Node;
		S->data = item;
		S->prev = tail->prev;
		S->next = tail;
		tail->prev->next = S;
		tail->prev = S;
		num_nondeleted++;
	}

	void pop_back() {
		if (!isEmpty()) {
			Node *discarded = tail;
			tail->prev = discarded->prev;
			discarded->prev->next = tail;
			num_deleted++;
			num_nondeleted--;

		}
	}
	void pop_back_delete() {
		if (!isEmpty()) {
			Node *discarded = tail;
			tail->prev = discarded->prev;
			discarded->prev->next = tail;
			delete discarded;

		}
	}

	Z & front() {
		while (head->next.deleted == true) {
			head->next;
		}
		return *this->head->next;
	}

	const Z& front() const {
		while (head->next.deleted == true) {
			head->next;
		}
		return *this->head->next;
	}

	iterator insert(iterator pos, const Z& key) {

		Node * p = pos;
		num_nondeleted++;
		p->deleted = false;
		return {p-> prev= p->prev->next = new Node {key,p->prev ,p}
		};
	}

	iterator erase(iterator pos) {
		Node *p = pos.current;
		iterator retVal { p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		p->deleted = true;
		num_deleted++;
		num_nondeleted--;

		return retVal;

	}

	bool contains(const Z& key) const {
		return false;
	}

	void fulldelete(lazylist lst) {

		for (iterator itr = lst.begin(); itr != lst.end(); /*nothing*/)
		{
		    Node *p = itr.current;
			if (p->deleted ==true){
		        iterator itr{p->next};
		        p->prev->next = p->next;
		        p->next->prev=p->prev;
		        delete p;
			}

		    else
		        ++itr;
		}
	}

	iterator begin() const {
		{
			return {head->next};
		}

	}
	iterator end() const {
		{
			return {tail};
		}
	}

	/*Definition of the iterator class */
	class iterator {

	private:
		Node *current;
	public:
		iterator(Node *n) {
			current = n;
		}
		bool operator !=(const iterator& rhs) const {
			return this->current != rhs.current;
		}

		bool operator ==(const iterator& rhs) const {
			return this->current == rhs.current;
		}

		void operator++() {
			while (current->next.deleted == true) {
				current = current->next;
			}

		}
		void operator--() {
			while (current->prev.deleted == true) {
				current = current->prev;
			}
		}
		Z& operator*() {
			return current->data;
		}
		Z& operator[](int a) {
			iterator itr(head);
			for (int i = 0; i < a; i++) {
				itr++;
				itr++;
			}
			return *itr;
		}

		friend class lazylist<Z> ;
	};
}
;

template<typename Z>
class lazylist<Z>::Node {
public:
	Z data;
	bool deleted;
	Node *next; /* singly-linked lazylist */
	Node *prev; /* doublyy-linked lazylist */

};
}

#endif
