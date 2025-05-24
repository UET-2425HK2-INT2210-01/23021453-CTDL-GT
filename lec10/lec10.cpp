#ifdef bai1
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1001; 

vector<int> adj[MAXN]; 
bool visited[MAXN];    


void dfs(int u) {
    visited[u] = true; // Đánh dấu đã thăm

    // Duyệt tất cả đỉnh kề với u
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v); // Đệ quy DFS tới đỉnh chưa thăm
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 

  
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh từ x đến y
        adj[y].push_back(x); // Vì là đồ thị vô hướng nên thêm cả cạnh ngược lại

    int connected_components = 0;

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i); // Nếu chưa thăm thì thực hiện DFS
            connected_components++; // Mỗi lần DFS là 1 thành phần liên thông
        }
    }
    cout << connected_components << endl;

    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>
#include <vector>
#include <queue>
    using namespace std;

    const int MAXN = 1001;

    vector<int> adj[MAXN]; // Danh sách kề
    int dist[MAXN];        // dist[i] là số cạnh ngắn nhất từ X đến i
    bool visited[MAXN];    // Đánh dấu đã thăm

    int main() {
        int n, m, X, Y;
        cin >> n >> m >> X >> Y;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // Đồ thị có hướng: chỉ thêm từ u đến v
        }

        // Khởi tạo BFS
        queue<int> q;
        q.push(X);
        visited[X] = true;
        dist[X] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            // Duyệt tất cả đỉnh kề
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Nếu Y không được thăm => không có đường đi
        if (!visited[Y])
            cout << -1 << endl;
        else
            cout << dist[Y] << endl;

        return 0;
    }
#endif bai2