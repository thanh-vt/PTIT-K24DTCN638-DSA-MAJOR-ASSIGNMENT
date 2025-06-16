#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

typedef pair<int, int> iPair;  // Pair để lưu trữ (đỉnh, trọng số)

void dijkstra(int V, vector<vector<iPair>>& adj, int src);

int main() {
    int V = 9;  // Số lượng đỉnh
    vector<vector<iPair>> adj(V);

    // Đồ thị ví dụ (đỉnh 0, 1, 2,...)
    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 8});
    adj[1].push_back({7, 11});
    adj[2].push_back({1, 8});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[2].push_back({8, 2});
    adj[3].push_back({2, 7});
    adj[3].push_back({4, 9});
    adj[3].push_back({5, 14});
    adj[4].push_back({3, 9});
    adj[4].push_back({5, 10});
    adj[5].push_back({2, 4});
    adj[5].push_back({3, 14});
    adj[5].push_back({4, 10});
    adj[5].push_back({6, 2});
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 6});
    adj[7].push_back({0, 8});
    adj[7].push_back({1, 11});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 7});
    adj[8].push_back({2, 2});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});

    int src = 0; // Đỉnh nguồn

    // Gọi hàm dijkstra để tìm đường đi ngắn nhất từ đỉnh src
    dijkstra(V, adj, src);

    return 0;
}


// Hàm cài đặt thuật toán Dijkstra
void dijkstra(const int V, vector<vector<iPair>>& adj, int src) {
    // Độ dài ngắn nhất từ đỉnh src đến tất cả các đỉnh
    vector dist(V, INT_MAX);
    dist[src] = 0;

    // Sử dụng set để lấy đỉnh có khoảng cách nhỏ nhất chưa được xét
    set<iPair> pq;
    pq.insert({0, src}); // (độ dài, đỉnh)

    while (!pq.empty()) {
        // Lấy đỉnh có độ dài ngắn nhất
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        // Duyệt tất cả các đỉnh kề của u
        for (pair<int, int>& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Nếu tìm thấy đường đi ngắn hơn đến v
            if (dist[u] + weight < dist[v]) {
                // Xóa đỉnh v trong set nếu đã tồn tại
                if (dist[v] != INT_MAX) {
                    pq.erase(pq.find({dist[v], v}));
                }

                // Cập nhật khoảng cách ngắn nhất đến v
                dist[v] = dist[u] + weight;
                pq.insert({dist[v], v});
            }
        }
    }

    // In ra kết quả
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Không có đường đến đỉnh " << i << endl;
        } else {
            cout << "Khoảng cách từ " << src << " đến " << i << " là: " << dist[i] << endl;
        }
    }
}