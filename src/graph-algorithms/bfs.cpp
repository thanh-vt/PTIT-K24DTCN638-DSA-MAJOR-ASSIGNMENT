#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

void BFS(const std::map<int, std::vector<int>> &adj_list, int s);

int main() {
    using namespace std;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int n,s;
    iss >> n >> s;
    map<int, vector<int>> adj_map;
    for (int i = 0; i < n; i++) {
        vector<int> AI;
        getline(cin, line);
        int node = stoi(line);
        getline(cin, line);
        int num;
        istringstream iss_inner(line);
        while (iss_inner >> num) {
            AI.push_back(num);
        }
        adj_map[node] = AI;
    }
    BFS(adj_map, s);
}

void BFS(const std::map<int, std::vector<int>> &adj_list, int s) {
    using namespace std;
    map<int, bool> visited;
    for (const pair<const int, vector<int>>& pair: adj_list) {
        visited[pair.first] = false;
    }
    queue<int> queue;

    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        s = queue.front();
        queue.pop();
        cout << s << " ";

        for (vector<int> adj = adj_list.at(s); const int n : adj) {
            if (!visited[n]) {
                visited[n] = true;
                queue.push(n);
            }
        }
    }
}
