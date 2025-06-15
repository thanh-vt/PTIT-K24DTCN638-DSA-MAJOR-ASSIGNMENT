#include <iostream>
#include <vector>

void print_result(const std::vector<int> &A);

bool gen_next_permutation(std::vector<int> &X, int N);

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    bool ok = true;
    while (ok) {
        print_result(A);
        ok = gen_next_permutation(A, N);
    }
}

bool gen_next_permutation(std::vector<int> &X, const int N) {
    int j = N - 2; // Xuất phát từ phần tử N-1
    while (j >= 0 && X[j] > X[j + 1]) j--; // Tìm j sao cho X[j]<X[j+1]
    if (j >= 0) {
        // Nếu j chưa vượt quá phần tử cuối cùng
        int k = N - 1; // Xuất phát từ N
        while (X[j] > X[k]) k--; // Tìm k sao cho X[j] <X[k]
        int t = X[j];
        X[j] = X[k];
        X[k] = t; // Đổi chỗ X[j] cho X[k]
        int r = j + 1, s = N - 1;
        while (r <= s) {
            // Lật ngược đoạn từ j +1 đến N
            t = X[r];
            X[r] = X[s];
            X[s] = t;
            r++;
            s--;
        }
        return true;
    }
    return false; // Nếu đến hoán vị cuối cùng
}

void print_result(const std::vector<int> &A) {
    using namespace std;
    for (const int i: A) {
        cout << i << " ";
    }
    cout << endl;
}
