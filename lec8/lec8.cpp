#ifdef bai1
#include <iostream>
using namespace std;

// Hàm hoán đổi hai giá trị
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Cài đặt thuật toán Quick Sort (Đệ quy)
void quickSort(double arr[], int left, int right) {
    if (left >= right) return; // Trường hợp cơ bản: nếu mảng con chỉ có 1 phần tử

    double pivot = arr[left]; // Chọn phần tử đầu tiên làm pivot
    int i = left + 1;
    int j = right;

    // Phân đoạn mảng theo pivot
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;   // Tìm phần tử lớn hơn pivot
        while (i <= j && arr[j] > pivot) j--;    // Tìm phần tử nhỏ hơn hoặc bằng pivot
        if (i < j) swap(arr[i], arr[j]);         // Hoán đổi nếu i < j
    }

    // Đưa pivot về đúng vị trí
    swap(arr[left], arr[j]);

    // Đệ quy sắp xếp hai nửa trái và phải
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main() {
    int n;
    cin >> n; 

    double arr[1000]; 

    // Nhập mảng
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    // In ra mảng đã sắp xếp
    for (int i = 0; i < n; ++i) {
        // Nếu là số nguyên (không có phần thập phân), in dưới dạng int
        if (arr[i] == (int)arr[i])
            cout << (int)arr[i];
        else
            cout << arr[i];

        // Thêm dấu cách giữa các số (trừ số cuối)
        if (i != n - 1) cout << " ";
    }

    cout << endl; // Xuống dòng sau khi in hết

    return 0; // Kết thúc chương trình
}
#endif bai1


#ifdef bai2
#include <iostream>
using namespace std;

bool subsetSum(int A[], int n, int X, int index = 0, int sum = 0) {
    // Nếu tổng tạm thời bằng X => tìm được tập con thỏa mãn
    if (sum == X) return true;

    // Nếu đã xét hết mảng hoặc tổng tạm thời vượt quá X => không hợp lệ
    if (index == n || sum > X) return false;

    // Nhánh 1: chọn phần tử tại chỉ số index
    if (subsetSum(A, n, X, index + 1, sum + A[index])) return true;

    // Nhánh 2: không chọn phần tử tại index, bỏ qua
    if (subsetSum(A, n, X, index + 1, sum)) return true;

    return false;
}

int main() {
    int n, X;
    cin >> n >> X; 

    int A[100];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Gọi hàm kiểm tra và in kết quả
    if (subsetSum(A, n, X))
        cout << "YES\n"; // Có tồn tại tập con thỏa mãn
    else
        cout << "NO\n";  // Không tồn tại tập con thỏa mãn

    return 0;
}
#endif bai2


#ifdef bai3
#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;

    int weight[100], value[100];

    // Nhập n cặp (weight, value)
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // dp[x] là giá trị lớn nhất đạt được với trọng lượng x
    int dp[10001] = { 0 }; // Giả sử X <= 10000

    // Duyệt qua từng món đồ
    for (int i = 0; i < n; ++i) {
        // Duyệt ngược từ X về weight[i] để tránh dùng lại cùng 1 đồ vật
        for (int x = X; x >= weight[i]; --x) {
            // Cập nhật giá trị lớn nhất giữa: 
            // Không lấy món đồ i (dp[x])
            // Lấy món đồ i (dp[x - weight[i]] + value[i])
            if (dp[x - weight[i]] + value[i] > dp[x]) {
                dp[x] = dp[x - weight[i]] + value[i];
            }
        }
    }

    // Tìm giá trị lớn nhất trong dp[0..X]
    int result = 0;
    for (int i = 0; i <= X; ++i) {
        if (dp[i] > result) result = dp[i];
    }

    cout << result << endl;

    return 0;
}
#endif bai3