#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;
class LinkedList : public List {
	node* head;
	node* tail;
	int size;
	
	public:
	LinkedList() {
		head = new node;
		cout << "Head add: " << head << endl;
		tail = new node;
		cout << "Tail add: " << tail << endl;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	~LinkedList() {
		cout << "Deleting myself from here"<< endl;
		// free all nodes bye byeeeeeeeeeeeeeee
		node* curr = head;
		while (curr != tail) {
			curr = curr->next;
			delete curr->prev;
		}
		delete tail;
	}
	void add(int num) {
		add_between(num, tail->prev, tail);
	}
	node* add_between(int num, node* pred, node* succ) {
		node* n = (node*) malloc( sizeof( node )) ;
		cout << "Address is " << n << endl;
		n->elem = num;
		n->prev = pred;
		n->next = succ;
		pred->next = n;
		succ->prev = n;
		size++;
	}
	void addHead(int num) { // addhead
		add_between(num, head, head->next);
	}
	int removeHead() {
		int tmp = head->next->elem;
		remove_node(head->next);
		return tmp;
	}
	int get(int pos) {
		node* curr = head;
		for (int i = 1; i < pos; i++) {
			curr = curr->next;
		}
		return curr->elem;
	}
	void remove_node(node* n) {
		node* succ = n->next;
		node* pred = n->prev;
		pred->next = succ;
		succ->prev = pred;
		free(n);
	}
	
	int remove(int num) {
		node* curr = head;
		int pos = 1;
		while (curr->elem != num) {
			curr = curr->next;
			pos++;
		}
		remove_node(curr);
		return pos;
	}
 	void print() {
		cout << "Size: " << size << endl<<"head:";
		node* curr = head->next;
		while (curr != tail) {
			cout << curr->elem << " -> ";
			curr = curr->next;
		}
		cout << endl << "tail: ";
		curr = tail->prev;
		while (curr != head) {
			cout << curr->elem << " -> ";
			curr = curr->prev;
		}
		cout << endl ;
	}
};
