#include <iostream>
#include <sstream>
#include <vector>

void quick_sort_recursive(std::vector<int> &v, int l, int r);

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
    quick_sort_recursive(A, 0, A.size() - 1);
    for (const int i : A) {
        cout << i << " ";
    }
}

void quick_sort_recursive(std::vector<int> &v, const int l, const int r) {
    using namespace std;
    const int pivot = v[(l + r) / 2];
    int i = l, j = r;
    do {
        while (v[i] < pivot) {i++;}
        while (v[j] > pivot) {j--;}
        if (i <= j) {
            const int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }while (i <= j);
    if (i < r) {
        quick_sort_recursive(v, i, r);
    }
    if (j > l) {
        quick_sort_recursive(v, l, j);
    }
}