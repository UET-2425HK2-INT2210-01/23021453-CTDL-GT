#ifdef bai1
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string cau;
    getline(cin, cau);
    reverse(cau.begin(), cau.end());
    cout << cau;
    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>
#include <iomanip>
using namespace std;

class point {
public:
    double x, y;
     point(double x = 0, double y = 0): x(x), y(y) {};
};
class line {
public:
    point A, B;
    line(point A, point B) : A(A), B(B) {}

    bool intersection(line other, point &intersectionpoint) {
        double a1 = B.y - A.y;
        double b1 = A.x - B.x;
        double c1 = a1 * A.x + b1 * A.y;

        double a2 = other.B.y - other.A.y;
        double b2 = other.A.x - other.B.x;
        double c2 = a2 * other.A.x + b2 * other.A.y;

        double determenant = a1 * b2 - a2 * b1;
        if (determenant == 0) {
            return false;
        }
        else {
            intersectionpoint.x = (b2 * c1 - b1 * c2) / determenant ;
            intersectionpoint.y = (a1 * c2 - a2 * c1) / determenant ;
            return true;
        }

    }
};

int main() {
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    cin >> dx >> dy;

    point A(ax, ay), B(bx, by), C(cx, cy), D(dx, dy);
    line line1(A, B), line2(C, D);
    point intersectionpoint(0, 0);
    if (line1.intersection(line2, intersectionpoint)) {
        cout << fixed << setprecision(2);
        cout << intersectionpoint.x << " " << intersectionpoint.y << endl;

    }
    else {
        cout << "khong co giao diem";
    };
    return 0;
}
#endif bai2

#ifdef bai3
#include <iostream>
using namespace std;

int H(int a, int b) {


    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}
int main() {
    int so1, so2;
    cin >> so1 >> so2;
    if (so1 <= 0 || so2 <= 0) {
        cout << "khong thoa man dieu kien so1 va so2 la 2 so nguyen duong";
        return 1;
    }

    
    int result = H(so1, so2);
    cout << result;
    return 0;
}
#endif bai3

#ifdef bai4 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "khong thoa man dieu kien n la so nguyen duong";
        return 1;
    }
    vector<int> number(n);
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    sort(number.begin(), number.end());

    for (int i = 0; i < n; ++i) {
        cout << number[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    return 0;
}
#endif bai4

#ifdef bai5
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {


    vector<int> numbers(5);
    for (int i = 0; i < 5; ++i) {
        cin >> numbers[i];
    }
    
    double minnumber = numbers[0];
    double maxnumber = numbers[0];

    for (int i = 1; i < 5; ++i) {
        if(numbers[i] < minnumber) {
            minnumber = numbers[i];
        }
        if (numbers[i] > maxnumber) {
            maxnumber = numbers[i];
        }

    }
    double sum = maxnumber + minnumber;
    cout << sum;
    return 0;

}
#endif bai5