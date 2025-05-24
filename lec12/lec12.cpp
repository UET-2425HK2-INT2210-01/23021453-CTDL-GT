#ifdef bai1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1001;

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    int n, m;
    fin >> n >> m;

    vector<int> adj[MAXN];
    int inDegree[MAXN] = { 0 };
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;

    // Thêm các job có bậc vào = 0 vào queue
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topoOrder.push_back(u);
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if ((int)topoOrder.size() != n) {
        fout << "IMPOSSIBLE\n"; 
    }
    else {
        for (int i = 0; i < n; ++i) {
            fout << topoOrder[i];
            if (i != n - 1) fout << " ";
        }
        fout << "\n";
    }
    fin.close();
    fout.close();

    return 0;
}
#endif bai1

#ifdef bai2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

const int MAXN = 10001;
int parent[MAXN];
int sz[MAXN];

// Tìm gốc của tập hợp có path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false; // cùng tập hợp, tạo chu trình
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    ifstream fin("connection.txt");
    ofstream fout("connection.out");

    int n, m;
    fin >> n >> m;

    // Khởi tạo DSU
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        fin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // Sắp xếp cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end());

    int totalCost = 0;
    vector<Edge> mstEdges;

    // Duyệt các cạnh theo thứ tự trọng số
    for (auto& e : edges) {
        if (unite(e.u, e.v)) {
            totalCost += e.cost;
            mstEdges.push_back(e);
        }
    }
    fout << totalCost << "\n";
    for (auto& e : mstEdges) {
        fout << e.u << " " << e.v << " " << e.cost << "\n";
    }
    fin.close();
    fout.close();

    return 0;
}
#endif bai2