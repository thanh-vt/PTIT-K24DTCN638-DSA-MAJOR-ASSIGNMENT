#include <iostream>
#include <vector>

void print_result(const std::vector<int> &A);

bool gen_next_combination(std::vector<int> &X, int N, int K);

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(K);
    for (int i = 0; i < K; i++) {
        std::cin >> A[i];
    }
    bool ok = true;
    while (ok) {
        print_result(A);
        ok = gen_next_combination(A, N, K);
    }
}

bool gen_next_combination(std::vector<int> &X, const int N, const int K) {
    int i = K; // Xuất phát từ phần tử cuối cùng của tổ hợp
    while (i > 0 && X[i - 1] == (N - K + i)) {     //Tìm phần tử X[i]N-K+i
        i--;
    }
    if (i > 0) {
        //Nếu i chưa vượt quá phần tử cuối cùng
        X[i - 1]++; //Thay X[i] = X[i] +1
        for (int j = i + 1; j <= K; j++) {
            //Từ phần tử thứ j +1 đến K
            X[j - 1] = X[i - 1] + 1; // Thay thế X[j] = X[i] + j – i
        }
        return true;
    }
    return false; //OK =0 nếu đã đến tập con cuối cùng
}

void print_result(const std::vector<int> &A) {
    using namespace std;
    for (const int i: A) {
        cout << i << " ";
    }
    cout << endl;
}
