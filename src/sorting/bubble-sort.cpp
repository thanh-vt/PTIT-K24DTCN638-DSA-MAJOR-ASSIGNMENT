#include <iostream>
#include <sstream>
#include <vector>

void bubble_sort(std::vector<int> &v);

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
    bubble_sort(A);
    for (const int i : A) {
        cout << i << " ";
    }
}

void bubble_sort(std::vector<int> &v) {
    using namespace std;
    const int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= i; j--) {
            if (v[j] > v[j + 1]) {
                const int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}