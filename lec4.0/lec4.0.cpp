#ifdef bai1
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class linkedList {
private:
    Node* head;
public:
    linkedList() {
        head = nullptr;
    }
    void append_x(int x) {
        if (head == nullptr) {
            head = new Node(x);
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(x);
    }
    bool search(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        Node* next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    // Node* reverse() {
    //     Node* p = nullptr;
    //     Node* temp = head;
    //     while (temp != nullptr) {
    //         Node* newNode = new Node(temp->data);
    //         newNode->next = p;
    //         p = newNode;
    //         temp = temp->next;
    //     }
    //     return p;
    // }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    linkedList list;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "append") {
            int x; cin >> x;
            list.append_x(x);
        }
        else if (s == "search") {
            int x; cin >> x;
            cout << list.search(x) << '\n';
        }
        else if (s == "reverse") {
            // list.print(list.reverse());
            list.reverse();
            list.print();
        }
    }

    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    int p;
    Node* next;
    Node* prev;
    Node(int data, int p) {
        this->data = data;
        this->p = p;
        next = nullptr;
        prev = nullptr;
    }
};

class piorityQueue {
private:
    Node* head;
    Node* tail;
public:
    piorityQueue() {
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            Node* temp = head;
            while (temp != nullptr && temp->p < p) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else if (temp->prev == nullptr) {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }
    void Dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }
    void Print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->data << ", " << temp->p << "); ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    piorityQueue q;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "enqueue") {
            int x, p;
            cin >> x >> p;
            q.enqueue(x, p);
        }
        else if (s == "dequeue")
            q.Dequeue();
    }
    q.Print();

    return 0;
}
#endif bai2

#ifdef bai3
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
private:
    Node* head;
public:
    Stack() {
        head = nullptr;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }
    char Top() {
        return head->data;
    }
    void pop() {
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

bool valid(string s) {
    if (s.length() % 2 == 1)
        return false;
    Stack stack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            stack.push(s[i]);
        }
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if (i == 0) return false;
            else
                if (stack.Top() == '[' && s[i] == ']' || stack.Top() == '{' && s[i] == '}' || stack.Top() == '(' && s[i] == ')')
                    stack.pop();
                else return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    string s; cin >> s;
    if (valid(s))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}
#endif bai3