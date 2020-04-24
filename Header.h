#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct Node {
	string data;
	Node* next;
	Node* down;
	int level;

	Node() {
		data = "";
		next = 0;
		down = 0;
		level = 0;
	}

	Node(string d, int l) {
		data = d;
		next = 0;
		down = 0;
		level = l;
	}
};

struct MyIterator
{
	Node* it;

	Node& operator*() {
		return *it;
	}

	Node& operator->() {
		return *it;
	}

	MyIterator() { it = 0; }

	MyIterator(Node* n) {
		it = n;
	}

	MyIterator next() {
		if (it->next != 0) {
			it = it->next;
			return *this;
		}
		else return NULL;
	}

	MyIterator endNext() {
		while (it->next != 0) {
			it = it->next;
		}
		return *this;
	}

	MyIterator down() {
		if (it->down != 0) {
			it = it->down;
			return *this;
		}
		else return NULL;
	}

	MyIterator endDown() {
		endNext();
		while (it->down != 0) {
			it = it->down;
			endNext();
		}
		return *this;
	}

	bool isNext() {
		return it->next != 0;
	}

	bool isDown() {
		return it->down != 0;
	}

	void insNext(string data) {
		delete it->next;
		it->next = new Node(data, it->level);
	}

	void insDown(string data) {
		delete it->down;
		it->down = new Node(data, it->level + 1);
	}

	bool operator==(const MyIterator& iterator) {
		return it == iterator.it;
	}

	bool operator!=(const MyIterator& iterator) {
		return it != iterator.it;
	}

	friend ostream& operator<<(ostream& os, const MyIterator it);
};

ostream& operator<<(ostream& os, const MyIterator it) {
	os << it.it->data;
	return os;
}

class MyList {
	Node* head;
	Node* tail;

public:
	MyIterator begin() {
		MyIterator res(head);
		return res;
	}

	MyIterator end() {
		MyIterator res(head);
		res.endDown();
		return res;
	}

	MyList() {
		head = new Node();
		tail = head;		
	}	

	void push_back_current_level(string data) {
		if (head == tail) {
			head->data = data; 
			head->level = 0;
			head->next = 0;
		}
		else {
			tail->next = new Node(data, tail->level);
			tail = tail->next;
			tail->next = 0;
		}
	}

	void push_back_next_level(string data) {
		if (head == tail) {
			head->down = new Node(data, head->level + 1);
			tail = head->down;
			tail->next = 0;
		}
		else {
			tail->down = new Node(data, tail->level + 1);
			tail = tail->down;
			tail->next = 0;
		}
	}

	pair<string, int> pop() {
		if (head == tail) throw "";

		pair<string, int> res(tail->data, tail->level);
		tail = 0;
		return res;
	}

	void print() {
		Node* cur_next = head;
		Node* cur_down = head;
		stack<Node*> way;
		int c = 1;

		while (cur_next != 0) {
			cur_down = cur_next;
			c++;
			
			while (cur_down != 0) {	

				if (cur_down->next != 0) {
					way.push(cur_down->next);
					c--;
				}

				for (int i = 0; i < cur_down->level; i++) cout << " ";
				cout << c << ". " << cur_down->data << endl;
				cur_down = cur_down->down;
			}

			if (way.size() > 0) {
				cur_next = way.top();
				way.pop();
			}
			else cur_next = cur_next->next;
		}
		
		
	}
	
	
	
};


