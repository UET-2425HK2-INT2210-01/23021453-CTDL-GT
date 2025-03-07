#ifdef bai1
2^10: O(1);
2^log(n) : O(log(n));
4n : O(n);
3n + 100log(n) : O(n)
nlog(n) : O(nlog(n))
4nlog(n) : O(nlog(n))
n^2 + 10n : O(n^2)
n^3 : O(n^3)
2^n : O(2^n)
#endif bai1

#ifdef bai2
#include <iostream>

using namespace std;

int so1(int x) {
    long long count = 1;
    for (int i = 0; i < x; i++) {
        count *= 2;
    }
    return count;
} // O(n)

int so2(int a) {
    if (a == 0) {
        return 0;
    }
    if (a < 0) {
        return -2 + so2(a + 1);
    }
    else {
        return 2 + so2(a - 1);
    }
} // O(n)

int main() {
    int n;
    cin >> n;
    cout << so2(n);
    return 0;
}
#endif bai2

#ifdef bai3
#include <iostream>

using namespace std;

int a[1000], maxN = 1000;
int n = 0;

int size() {
    return n;
} // O(1)


void push(int x) {
    if (n == maxN) {
        return;
    }
    else {
        a[n] = x;
        n++;
    }
} // O(n)

void pop() {
    if (n == 0) return;
    for (int i = 0; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
} // O(n)

void in() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
} // O(n)

int front() {
    return a[0];
} // O(1)

int main() {
    int n;
    cin >> n;
    int x;
    string require;
    for (int i = 0; i < n; i++) {
        cin >> require;
        if (require == "push") {
            cin >> x;
            push(x);
        }
        else {
            pop();
        }
    }
    in();
    return 0;
}
#endif bai3

#ifdef bai4
#include <iostream>
using namespace std;
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

///pseudo
Struct Node :
int data
Node* next

Class LinkedList :
Node * head

Method INIT :
Set head to NULL

Method QUEUE1(x) :
    Create newNode
    Set newNode.data to x
    Set newNode.next to NULL
    If head is NULL :
Set newNode.next to head
Set head to newNode
Else :
Set temp to head
While temp.next is not NULL :
    Set temp to temp.next
    End While
    Set temp.next to newNode
    End If
    End Method

    Method DEQUEUE1 :
Set temp to head
Set head to head.next
Delete temp
End Method

Method PRINT_LIST :
Set temp to head
While temp is not NULL :
    Print temp.data
    Set temp to temp.next
    End While
    End Method
    End Class

    Main :
Read n
Create LinkedList queue
For i from 0 to n - 1 :
    Read string
    If stringd is "enqueue" :
    Read num
    Call queue.QUEUE1(num)
    Else If string is "dequeue" :
    Call queue.DEQUEUE1()
    End If
    End For
    Call queue.PRINT_LIST()
#endif bai4

#ifdef bai5
#include <iostream>
using namespace std;

int n = 0, stack[100];

void push(int x) {
    stack[n] = x;
    n++;
} // O(1)

void pop() {
    if (n >= 1)
        n--;
} // O(1)

int top() {
    return stack[n];
} // O(1)

void in() {
    for (int i = 0; i <= n; i++) {
        cout << stack[i];
    }
} // O(n)

int main() {
    int n;
    cin >> n;
    int x;
    string require;
    for (int i = 0; i < n; i++) {
        cin >> require;
        if (require == "push") {
            cin >> x;
            push(x);
        }
        else {
            pop();
        }
    }
    in();
    return 0;
}
#endif bai5

#ifdef bai6
#include <iostream>
using namespace std;
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
///pseudo
Struct Node :
int data
Node* next

Class LinkedList :
Node * head

Method INIT :
Set head to NULL

Method PUSH(x) :
    Create newNode
    Set newNode.data to x
    Set newNode.next to NULL
    If head is NULL :
Set newNode.next to head
Set head to newNode
Else :
Set temp to head
While temp.next is not NULL :
    Set temp to temp.next
    End While
    Set temp.next to newNode
    End If
    End Method

    Method POP :
Set temp to head
While temp.next.next is not NULL :
    Set temp to temp.next
    End While
    Delete temp.next
    Set temp.next to NULL
    End Method

    Method PRINT_STACK :
Set temp to head
While temp is not NULL :
    Print temp.data
    Set temp to temp.next
    End While
    End Method
    End Class

    Main :
Read n
Create LinkedList stack
For i from 0 to n - 1 :
    Read string
    If string is "push" :
    Read num
    Call stack.PUSH(num)
    Else If string is "pop" :
    Call stack.POP()
    End If
    End For
    Call stack.PRINT_STACK()
    End Main
#endif bai6
