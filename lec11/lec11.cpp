#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAXN = 505;

int n, m, s, e;
struct Edge {
    int u, v, d;
};
vector<Edge> edges;

int distBell[MAXN];
int parent[MAXN];
int distFloyd[MAXN][MAXN];

// Hàm in đường đi từ s đến e dựa trên mảng parent
void printPath(int e, int s, vector<int>& path) {
    if (e == s) {
        path.push_back(s);
        return;
    }
    if (parent[e] == -1) {
        return;
    }
    printPath(parent[e], s, path);
    path.push_back(e);
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    fin >> n >> m >> s >> e;

    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        fin >> edges[i].u >> edges[i].v >> edges[i].d;
    }

    // Phần a: Bellman-Ford từ s để tìm khoảng cách ngắn nhất đến e và đường đi 
    for (int i = 1; i <= n; ++i) {
        distBell[i] = INF;
        parent[i] = -1;
    }
    distBell[s] = 0;

    // Relax edges n-1 lần
    for (int i = 1; i <= n - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge.u, v = edge.v, d = edge.d;
            if (distBell[u] != INF && distBell[u] + d < distBell[v]) {
                distBell[v] = distBell[u] + d;
                parent[v] = u;
            }
        }
    }
    // In tổng dirty level nhỏ nhất
    if (distBell[e] == INF) {
        fout << "INF\n";  // Không có đường đi
        fout << "\n";     // Đường đi trống
    }
    else {
        fout << distBell[e] << "\n";
        vector<int> path;
        printPath(e, s, path);

        if (path.empty()) {
            fout << "\n";
        }
        else {
            for (int i = 0; i < (int)path.size(); ++i) {
                fout << path[i];
                if (i != (int)path.size() - 1) fout << " ";
            }
            fout << "\n";
        }
    }

    // Phần b: Floyd-Warshall tìm tất cả cặp đỉnh 
    // Khởi tạo ma trận khoảng cách
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            distFloyd[i][j] = (i == j) ? 0 : INF;
    for (auto& edge : edges) {
        distFloyd[edge.u][edge.v] = min(distFloyd[edge.u][edge.v], edge.d);
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (distFloyd[i][k] != INF && distFloyd[k][j] != INF) {
                    if (distFloyd[i][k] + distFloyd[k][j] < distFloyd[i][j]) {
                        distFloyd[i][j] = distFloyd[i][k] + distFloyd[k][j];
                    }
                }
            }
        }
    }

    // In ma trận khoảng cách
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (distFloyd[i][j] == INF)
                fout << "INF";
            else
                fout << distFloyd[i][j];

            if (j != n) fout << " ";
        }
        fout << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}