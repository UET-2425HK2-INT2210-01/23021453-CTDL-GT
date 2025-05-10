#ifdef bai1
#include <iostream>
using namespace std;

// Cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;            // Dữ liệu của nút
    Node* left;          // Con trỏ tới nút con bên trái
    Node* right;         // Con trỏ tới nút con bên phải
    Node(int val) {      // Constructor khởi tạo một nút với giá trị val
        data = val;  
        left = nullptr;
        right = nullptr;
    }
};
// Hàm chèn một giá trị vào cây
Node* Insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);
    if (key < node->data) node->left = Insert(node->left, key);
    else if (key > node->data) node->right = Insert(node->right, key);
    return node;
}
// Hàm duyệt cây theo thứ tự inorder (trái - gốc - phải)
void Inorder(Node* node) {
    if (node == nullptr) return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}
// Hàm tìm nút có giá trị nhỏ nhất trong cây con bên phải
Node* findMin(Node* cur) {
    cur = cur->right;
    while (cur != nullptr && cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}
// Hàm xóa một giá trị khỏi cây
Node* Delete(Node* node, int key) {
    if (node == nullptr) return node;
    if (key < node->data) node->left = Delete(node->left, key);
    else if (key > node->data) node->right = Delete(node->right, key);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        Node* temp = findMin(node);
        node->data = temp->data;
        node->right = Delete(node->right, temp->data);
    }
    return node;
}

int main() {
    int n; 
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    Inorder(root); cout << endl; // Duyệt và in cây theo thứ tự inorder
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = Delete(root, x);
    }

    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa lớp MinHeap
class minHeap {
private:
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }          // Hàm trả về chỉ số nút cha của nút tại chỉ số i
    int left(int i) { return 2 * i + 1; }              // Trả về chỉ số con trái của nút tại chỉ số i
    int right(int i) { return 2 * i + 2; }             // Trả về chỉ số con phải của nút tại chỉ số i
    void heapifyUp(int i) {                            // Hàm điều chỉnh từ dưới lên để đảm bảo tính chất min-heap
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);            // Đổi chỗ với cha nếu nhỏ hơn
            i = parent(i);                             // Cập nhật vị trí cha
        }
    }
                                                       // Hàm điều chỉnh từ trên xuống để đảm bảo tính chất min-heap
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        if (l < heap.size() && heap[l] < heap[smallest])  // So sánh với con trái
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])  // So sánh với con phải
            smallest = r;
        if (smallest != i) {                              // Nếu cần đổi chỗ
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);                        // Gọi đệ quy tiếp xuống
        }
    }
public:
    void Insert(int key) {                                // Hàm chèn một phần tử mới vào heap
        heap.push_back(key);                              // Thêm phần tử vào cuối vector
        int keyPos = heap.size() - 1;
        heapifyUp(keyPos);                                // Đưa về đúng vị trí theo min-heap
    }
                                                          // Hàm xóa phần tử có giá trị bằng key khỏi heap
    void Delete(int key) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {           // Tìm chỉ số của phần tử cần xóa
            if (heap[i] == key) {
                index = i;
                break;
            }
        }
        if (index == -1) return;                          // Nếu không tìm thấy thì thoát
        heap[index] = heap.back();                        // Thay phần tử đó bằng phần tử cuối
        heap.pop_back();                                  // Xóa phần tử cuối
        if (!heap.empty() && index < heap.size()) {       // Sau khi thay đổi, điều chỉnh lại heap
            if (index > 0 && heap[index] < heap[parent(index)])
                heapifyUp(index);
            else
                heapifyDown(index);
        }
    }
    // Hàm in các phần tử trong heap
    void Print() {
        for (auto data : heap) {
            cout << data << " ";
        }
    }
};

int main() {
    int n;
    cout << "Dien so can chen vao: ";
    cin >> n;
    minHeap minHeap;
    for (int i = 0; i < n; i++) { 
        int x; cin >> x;
        minHeap.Insert(x);
    }
    minHeap.Print();
    cout << endl;
    cout << "Dien so can xoa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        minHeap.Delete(x);
    }

    return 0;
}
#endif bai2