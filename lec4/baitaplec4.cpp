#ifdef bai1
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int a) : data(a), neat(NULL) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}

    void append(int a) {
        Node* newNode = new Node(a); 
        if (!head) {
            head = newNode;.
            return;
        }
        Node* temp = head; 
        while (temp->next) { 
        }
        temp->next = newNode; 
    }

    void search(int a) { 
        Node* temp = head;  
        int position = 0; 
        while (temp) { 
            if (temp->data == a) {
                cout << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "NO" << endl; 
    }

    void reverse() { 
        Node* prev = NULL;
        Node* current = head; 
        Node* next = NULL 
        while (current) { 
            next = current->next; 
            current->next = prev;
            prev = current; 
            current = next; 
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList linkedList;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "append") {
            int a;
            cin >> a;
            linkedList.append(a);
        }
        else if (command == "search") {
            int a;
            cin >> a;
            linkedList.search(a);
        }
        else if (command == "reverse") {
            linkedList.reverse();
        }
    }

    linkedList.display();
    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>

using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(NULL), prev(NULL) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(NULL) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (!head || head->priority < priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        }
        else if (command == "dequeue") {
            pq.dequeue();
        }
        pq.printQueue();
    }
    return 0;
}
#endif bai2

#ifdef bai3
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}
#endif bai3