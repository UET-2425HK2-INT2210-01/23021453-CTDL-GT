#include <iostream> 
#include <vector>   
using namespace std; 

// Định nghĩa lớp Node đại diện cho mỗi nút trong cây
class Node {
public:
    int data; // Giá trị của node
    Node* firstChild; // Con đầu tiên của node
    Node* nextSibling; // Anh em kế tiếp của node
    Node(int value) { // Hàm khởi tạo
        data = value;
        firstChild = NULL;
        nextSibling = NULL;
    }
};

// Định nghĩa lớp Tree đại diện cho toàn bộ cây
class Tree {
public:
    Node* root; // Gốc của cây
    vector<Node*> nodeList; // Danh sách các node theo chỉ số
    vector<bool> isChild; // Kiểm tra xem node đó có phải là con không

    Tree() {
        root = NULL; // Khởi tạo gốc ban đầu là NULL
    }

    // Hàm cập nhật root trong trường hợp root được thêm sau các node con
    void updateRoot() {
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i] != NULL && !isChild[i]) { // Nếu node tồn tại và chưa từng là con
                root = nodeList[i]; // Gán làm root
                break; // Thoát vòng lặp ngay sau khi tìm được
            }
        }
    }

    // Hàm thêm quan hệ giữa node cha và node con
    void addNode(int parent, int child) {
        // Đảm bảo kích thước của mảng đủ lớn để chứa cả parent và child
        if (parent >= nodeList.size()) nodeList.resize(parent + 1, NULL);
        if (child >= nodeList.size()) nodeList.resize(child + 1, NULL);
        if (parent >= isChild.size()) isChild.resize(parent + 1, false);
        if (child >= isChild.size()) isChild.resize(child + 1, false);

        // Nếu node chưa được tạo, tạo mới
        if (nodeList[parent] == NULL) nodeList[parent] = new Node(parent);
        if (nodeList[child] == NULL) nodeList[child] = new Node(child);

        Node* parentNode = nodeList[parent]; // Lấy node cha
        Node* childNode = nodeList[child];   // Lấy node con

        // Nếu cha chưa có con nào, gán con đầu tiên
        if (parentNode->firstChild == NULL) {
            parentNode->firstChild = childNode;
        }
        // Nếu đã có con, thêm vào danh sách anh em
        else {
            Node* sibling = parentNode->firstChild;
            while (sibling->nextSibling != NULL) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = childNode; // Gán vào cuối danh sách anh em
        }

        isChild[child] = true; // Đánh dấu node này đã là con
        updateRoot(); // Cập nhật lại gốc nếu cần
    }

    // Hàm đệ quy tính chiều cao của cây
    int height(Node* node) {
        if (node == NULL) return 0; // Trường hợp : node rỗng
        int maxDepth = 0;
        Node* child = node->firstChild; // Bắt đầu từ con đầu tiên
        while (child != NULL) { // Duyệt qua tất cả các con
            maxDepth = max(maxDepth, height(child)); // Lấy chiều cao lớn nhất
            child = child->nextSibling; // Chuyển sang anh em tiếp theo
        }
        return maxDepth + 1; // Cộng 1 cho node hiện tại
    }

    // Duyệt cây theo tiền tự: root -> left -> right
    void preOrder(Node* node) {
        if (node == NULL) return; // Cơ sở: hết node
        cout << node->data << " "; // In giá trị node hiện tại
        preOrder(node->firstChild); // Duyệt con đầu tiên
        preOrder(node->nextSibling); // Duyệt anh em kế tiếp
    }

    // Duyệt cây theo hậu tự: left -> right -> root
    void postOrder(Node* node) {
        if (node == NULL) return;
        Node* child = node->firstChild; // Bắt đầu từ con đầu tiên
        while (child != NULL) {
            postOrder(child); // Gọi đệ quy trên từng con
            child = child->nextSibling; // Chuyển sang anh em tiếp theo
        }
        cout << node->data << " "; // Sau cùng in ra node hiện tại
    }

    // Kiểm tra cây có phải là cây nhị phân không
    bool isBinaryTree(Node* node) {
        if (node == NULL) return true;
        Node* child = node->firstChild;
        int cnt = 0;
        while (child != NULL) {
            cnt++; // Đếm số lượng con
            if (!isBinaryTree(child)) return false; // Nếu có con không hợp lệ thì false
            child = child->nextSibling; // Tiếp tục với anh em
        }
        return cnt <= 2; // Đúng nếu số con <= 2 (đúng định nghĩa cây nhị phân)
    }

    // Duyệt giữa (chỉ dùng được nếu cây là nhị phân): left -> root -> right
    void inOrder(Node* node) {
        if (node == NULL) return;
        // Duyệt con trái (con đầu tiên)
        if (node->firstChild != NULL) inOrder(node->firstChild);
        // In node hiện tại
        cout << node->data << " ";
        // Duyệt con phải (anh em của con đầu tiên)
        if (node->firstChild != NULL) inOrder(node->firstChild->nextSibling);
    }
};


int main() {
    int n, m; cin >> n >> m; // Nhập số lượng node và số cạnh 
    Tree tree;
    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child; 
        tree.addNode(parent, child); // Thêm vào cây
    }

    cout << tree.height(tree.root) - 1 << endl; // In ra chiều cao của cây (trừ đi 1 nếu không tính root)

    tree.preOrder(tree.root); cout << endl; // Duyệt theo tiền tự
    tree.postOrder(tree.root); cout << endl; // Duyệt theo hậu tự

    // Nếu là cây nhị phân thì duyệt theo giữa
    if (tree.isBinaryTree(tree.root)) {
        tree.inOrder(tree.root);
        cout << endl;
    }
    else cout << "NOT BINARY TREE"; // Nếu không phải thì in ra
    return 0;
}