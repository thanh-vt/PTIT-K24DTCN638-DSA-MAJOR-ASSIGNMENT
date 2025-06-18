#include <iostream>
#include <sstream>
#include <vector>

void selection_sort(std::vector<int> &v);

int main() {
    using namespace std;
    int num;
    vector<int> A;
    string line;
    getline(std::cin, line);
    istringstream iss(line);
    while (iss >> num) {
        A.push_back(num);
    }
    selection_sort(A);
    for (const int i : A) {
        cout << i << " ";
    }
}

void selection_sort(std::vector<int> &v) {
    using namespace std;
    const int n = v.size();
    for (int i = 0; i < n; i++) {
        int min = v[i];
        for (int j = i + 1; j < n; j++) {
            if (v[j] < min) {
                const int temp = v[j];
                v[j] = min;
                min = temp;
            }
        }
        v[i] = min;
    }
}