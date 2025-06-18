#include <iostream>
#include <sstream>
#include <vector>

void quick_sort(std::vector<int> &v);

void quick_sort_recursive(std::vector<int> &v, int leftIdx, int rightIdx);

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
    quick_sort(A);
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
}

void quick_sort(std::vector<int> &v) {
    using namespace std;
    const int n = v.size();
    const int pivot = v[0];
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



void quick_sort_recursive(std::vector<int> &v, int leftIdx, int rightIdx) {
}