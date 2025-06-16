#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>

void DFS(const std::map<int, std::vector<int>> &adj_list, int s);

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
    DFS(adj_map, s);
}

void DFS(const std::map<int, std::vector<int>> &adj_list, int s) {
    using namespace std;
    map<int, bool> visited;
    for (const pair<const int, vector<int>>& pair: adj_list) {
        visited[pair.first] = false;
    }

    stack<int> stack;

    cout << s << " ";
    visited[s] = true;
    stack.push(s);

    while (!stack.empty()) {
        s = stack.top();
        bool found_next = false;
        for (vector<int> adj = adj_list.at(s); const int n : adj) {
            if (!visited[n]) {
                found_next = true;
                cout << n << " ";
                visited[n] = true;
                stack.push(n);
                break;
            }
        }
        if (!found_next) {
            stack.pop();
        }
    }
}
