#ifdef bai1
#include <iostream>
#include <fstream>      
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("numbers.txt");     // Mở file đầu vào
    ofstream output("numbers.sorted"); // Mở file đầu ra
    vector<double> numbers;           
    double num;

    // Đọc tất cả các số từ file
    while (input >> num) {
        numbers.push_back(num);
    }

    // Sắp xếp các số theo thứ tự tăng dần
    sort(numbers.begin(), numbers.end());

    // Ghi các số đã sắp xếp ra file đầu ra
    for (size_t i = 0; i < numbers.size(); ++i) {
        output << numbers[i];
        if (i != numbers.size() - 1) output << " "; // Thêm dấu cách giữa các số
    }

    // Đóng các file
    input.close();
    output.close();

    cout << "Sorted numbers written to 'numbers.sorted'\n";
    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>  
#include <fstream>    
#include <vector>     
#include <climits>   

using namespace std;

int main() {
    ifstream fin("matrix.txt");    
    ofstream fout("matrix.out");  

    int m, n;
    fin >> m >> n;                  // Đọc số hàng m và số cột n từ file

    // Khởi tạo ma trận m x n
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> matrix[i][j];   // Đọc từng phần tử của ma trận
        }
    }

    // Khởi tạo biến lưu tổng lớn nhất và vị trí vùng con tương ứng
    int maxSum = INT_MIN;          // Tổng lớn nhất khởi đầu là giá trị nhỏ nhất có thể
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;

    // Duyệt tất cả các cặp dòng trên và dưới 
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0);    // Mảng tạm chứa tổng cột giữa top và bottom

        for (int bottom = top; bottom < m; ++bottom) {
            // Cộng giá trị từng cột từ dòng top đến dòng bottom vào temp
            for (int i = 0; i < n; ++i)
                temp[i] += matrix[bottom][i];

            // Áp dụng thuật toán Kadane để tìm đoạn tổng lớn nhất trên hàng
            int sum = 0, start = 0;
            int localLeft = 0, localRight = 0;
            int maxLocalSum = INT_MIN;

            for (int i = 0; i < n; ++i) {
                if (sum <= 0) {             // Nếu tổng hiện tại âm, bắt đầu đoạn mới
                    sum = temp[i];
                    start = i;
                }
                else {
                    sum += temp[i];        // Cộng dồn giá trị hiện tại
                }
                if (sum > maxLocalSum) {   // Nếu tổng lớn hơn tổng tối đa tạm thời
                    maxLocalSum = sum;
                    localLeft = start;     // Cập nhật vị trí trái
                    localRight = i;        // Cập nhật vị trí phải
                }
            }

            // Nếu tổng lớn nhất tìm được lớn hơn tổng tối đa toàn cục
            if (maxLocalSum > maxSum) {
                maxSum = maxLocalSum;
                finalTop = top;            // Lưu lại dòng trên
                finalBottom = bottom;      // Lưu lại dòng dưới
                finalLeft = localLeft;     // Lưu lại cột trái
                finalRight = localRight;   // Lưu lại cột phải
            }
        }
    }

    // Ghi ra file kết quả
    // Tọa độ của góc trên trái và góc dưới phải của hình chữ nhật có tổng lớn nhất
    // (Chuyển sang đánh số từ 1 thay vì 0)
    fout << (finalTop + 1) << " " << (finalLeft + 1) << " "
        << (finalBottom + 1) << " " << (finalRight + 1) << " " << maxSum << "\n";

    return 0;
}
#endif bai2

#ifdef bai3
#include <iostream>     
using namespace std;

// Hàm tính ước chung lớn nhất giữa a và b
int gcd(int a, int b) {
    // Điều kiện dừng đệ quy: nếu a == 0 thì gcd là b
    if (a == 0) return b;

    // Gọi đệ quy
    return gcd(b % a, a);
}

int main() {
    int a, b;

    // Nhập vào hai số nguyên từ bàn phím
    cin >> a >> b;

    // In ra ước chung lớn nhất của a và b
    cout << gcd(a, b) << endl;

    return 0;
}
#endif bai3

#ifdef bai4
#include <iostream>     
#include <string>       
using namespace std;

int main() {
    int n;
    cin >> n;           

    int total = 1 << n; // Tính 2^n bằng cách dịch bit trái (1 << n)

    // Duyệt tất cả các số từ 0 đến 2^n - 1
    for (int i = 0; i < total; ++i) {
        string binary = "";  // Khởi tạo chuỗi nhị phân rỗng

        // Duyệt từng bit của số i từ bit cao nhất (trái) đến thấp nhất (phải)
        for (int j = n - 1; j >= 0; --j) {
            // Nếu bit là 1 thì thêm '1', nếu là 0 thì thêm '0'
            binary += ((i >> j) & 1) ? '1' : '0';
        }      
        cout << binary << endl;
    }

    return 0;
}
#endif bai4
#ifdef bai5
#include <iostream>    
#include <vector>      
#include <algorithm>   
using namespace std;

int main() {
    int n;
    cin >> n;  
    vector<int> perm;
    for (int i = 1; i <= n; ++i) {
        perm.push_back(i);
    }

    // Sắp xếp dãy ban đầu từ hoán vị nhỏ nhất
    sort(perm.begin(), perm.end());

    //vòng lặp
    do {
        // In từng phần tử trong hoán vị hiện tại
        for (int x : perm) {
            cout << x;
        }
        cout << endl;
    } while (next_permutation(perm.begin(), perm.end()));
    // Sinh hoán vị kế tiếp, trả về false khi không còn hoán vị nào

    return 0;
}
#endif bai5




