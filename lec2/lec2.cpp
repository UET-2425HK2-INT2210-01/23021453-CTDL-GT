#ifdef bai1
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class linkedlist {
	node* head;
public:
	linkedlist() : head(NULL) {}

	void insert(int a) {
		node* newnode = new node();
		newnode->data = a;
		newnode->next = NULL;

		if (head == NULL) {
			newnode->next = head;
			head = newnode;
		}
		else {
			node* tam = head;
			while (tam->next != NULL) {
				tam = tam->next;
			}
			tam->next = newnode;
		}
	}

	void pairs() {
		int dem = 0;
		node* so1 = head;
		while (so1 != NULL) {
			node* so2 = so1->next;
			while (so2 != NULL) {
				if (so1->data == so2->data) {
					dem++;
				}
				so2 = so2->next;
			}
			so1 = so1->next;
		}
		cout << dem << endl;
	}
};
	int main() {
		int n;
		cin >> n;
		linkedlist list;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			list.insert(a);
		}
		list.pairs();
		return 0;
	}
#endif bai1

#ifdef bai2
#include <iostream>
using namespace std;

	struct node {
		int data;
		node* next;		
	};
	class linkedlist {
		node* head;
	public:
		linkedlist() : head(NULL) {}

		void insert(int p, int x){
			node* newnode = new node();
			newnode->data = x;
			newnode->next = NULL;

			if (p == 0) {
				newnode->next = head;
				head = newnode;
			}
			else {
				node* current = head;
				for (int i = 0; i < p - 1 && current != NULL; i++) {
					current = current->next;
		 		}
				if (current != NULL) {
					newnode->next = current->next;
					current->next = newnode;
				}
				else {
					cout << "loi" << endl;
					delete newnode;
				}
			}
         }
		void remove(int p) {
			if (head == NULL) {
				cout << "danh sach khong co gi, trong tron, nothinggggggggg" << endl;
				return;
			}
			if (p == 0) {
				node* temp = head;
				head = head->next;
				delete temp;
			}
			else {
				node* current = head;
				for (int i = 0; i < p - 1 && current != NULL; i++) {
					current = current->next;
				}
				if (current != NULL && current->next != NULL) {
					node* temp = current->next;
					current->next = temp->next;
					delete temp;
				}
				else {
					cout << "hehe, ERROR!!!!" << endl;
				}
			}
		}
		void in(){
				node* current = head;
				while (current != NULL) {
					cout << current->data << " ";
					current = current->next;
				}
				cout << endl;
			}
	};
int main() {
		linkedlist list;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int p, x;
			string words;
			cin >> words;
			if (words == "insert") {
				cin >> p >> x;
				list.insert(p, x);
			}
			else if (words == "delete") {
				cin >> p;
				list.remove(p);
			}
		}
		list.in();
     	return 0;
	}
#endif bai2

#ifdef bai3
struct node {
	int data;
	node* next;
	node* prev;
};


class doublyLinkedList {
	node* head;
public:
	doublyLinkedList() : head(NULL) {};
	void insert(double x) {
		node* newNode = new node();
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
		if (head == NULL) {
			newNode->next = head;
			if (head != NULL) {
				head->prev = newNode;
			}
			head = newNode;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;

		}
	}
	int count_triplet() {
		int dem = 0;
		node* temp = head;
		while (temp != NULL && temp->next != NULL && temp->next->next != NULL) {
			int sum = temp->data + temp->next->data + temp->next->next->data;
			if (sum == 0) {
				dem++;
			}
			temp = temp->next;
		}
		return dem;
	}

};

int main() {
	int n;
	cin >> n;
	doublyLinkedList list;
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		list.insert(x);
	}
	cout << list.count_triplet() << endl;
	return 0;
}
#endif bai3

#ifdef bai4
struct node {
	int data;
	node* next;
};

class linkedList {
	node* head;
public:
	linkedList() : head(NULL) {}
	void queue1(int x) {
		node* newNode = new node();
		newNode->data = x;
		newNode->next = NULL;
		if (head == NULL) {
			newNode->next = head;
			head = newNode;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;

		}
	}
	void dequeue1() {
		node* temp = head;
		head = head->next;
		delete temp;
	}
	void printList() {
		node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main() {
	int n;
	cin >> n;
	linkedList queue;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "enqueue") {
			int num;
			cin >> num;
			queue.queue1(num);
		}
		else if (s == "dequeue") {
			queue.dequeue1();
		}
	}
	queue.printList();
	return 0;
}

#endif bai4

#ifdef bai5
struct node {
	int data;
	node* next;
};

class linkedList {
	node* head;
public:
	linkedList() : head(NULL) {}
	void push(int x) {
		node* newNode = new node();
		newNode->data = x;
		newNode->next = NULL;
		if (head == NULL) {
			newNode->next = head;
			head = newNode;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;

		}
	}
	void pop() {
		node* temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
	void printStack() {
		node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

};
int main() {
	int n;
	cin >> n;
	linkedList stack;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (s == "pop") {
			stack.pop();
		}
	}
	stack.printStack();
	return 0;
}
#endif bai5






