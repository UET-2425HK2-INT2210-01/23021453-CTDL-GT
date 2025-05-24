#ifdef bai1
#include <iostream>
using namespace std;

int sum(int n) {
    // Điều kiện dừng: nếu n = 0 thì trả về 0
    if (n == 0) return 0;
    // Gọi đệ quy: tổng từ 1 đến n = n + tổng từ 1 đến (n-1)
    return n + sum(n - 1);
}

int main() {
    int n; cin >> n;
    cout << sum(n);

    return 0;
}
#endif bai1



#ifdef bai2
#include <iostream>
using namespace std;

long long factorial(int n) {
    // Trường hợp 0! = 1
    if (n == 0) return 1;
    // Gọi đệ quy
    return n * factorial(n - 1);
}

int main() {
    int n; cin >> n;
    cout << factorial(n);

    return 0;
}
#endif bai2


 
#ifdef bai3
#include <iostream>
using namespace std;

int fibo(int n) {
    // Trường hợp fibo(0) = 0, fibo(1) = 1
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Gọi đệ quy
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n; cin >> n;
    cout << fibo(n);

    return 0;
}
#endif bai3


#ifdef bai4
#include <iostream>
using namespace std;

long long cal(int x, int n) {
    // Trường hợp x^0 = 1
    if (n == 0) return 1;
    // Gọi đệ quy 
    int half = cal(x, n / 2);
    // Nếu n là số lẻ: x^n = x^(n/2) * x^(n/2) * x
    // Nếu n là số chẵn: x^n = x^(n/2) * x^(n/2)
    if (n % 2 == 1) return half * half * x;
    else return half * half;
}

int main() {
    int n, x; cin >> x >> n;
    cout << cal(x, n);

    return 0;
}
#endif bai4

#ifdef bai5
#include <iostream>
using namespace std;

int count(int n) {
    // Trường hợp nếu n = 0 thì không còn chữ số
    if (n == 0) return 0;
    // Loại bỏ chữ số cuối cùng
    n /= 10;
    // Gọi đệ quy
    return count(n) + 1;
}

int main() {
    int n; cin >> n;
    cout << count(n);

    return 0;
}
#endif bai5

 
#ifdef bai6
#include <iostream>
using namespace std;

int sum(int n) {
    // Trường hợp nếu n = 0 thì tổng là 0
    if (n == 0) return 0;
    // tách số cuối cùng 
    int digit = n % 10;
    // loại chữ số cuối cùng 
    n /= 10;
    // Gọi đệ quy
    return digit + sum(n);
}

int main() {
    int n; cin >> n;
    cout << sum(n);

    return 0;
}
#endif bai6

#ifdef bai7
#include <iostream>
#include <cmath>
using namespace std;

int reversereverse(int n) {
    // Trường hợp nếu chỉ còn 1 chữ số thì trả về chính nó
    if (n < 10) return n;
    int temp = n;
    // đếm số lượng chữ số trong n
    int cnt = 0;
    while (temp != 0) {
        temp /= 10;
        cnt++;
    }
    // Lấy chữ số cuối cùng
    int digit = n % 10;
    // n * 10^(cnt - 1)
    return digit * pow(10, cnt - 1) + reversereverse(n / 10);
}

int main() {
    int n; cin >> n;
    cout << reversereverse(n);

    return 0;
}
#endif bai7