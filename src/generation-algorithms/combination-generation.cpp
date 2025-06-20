#include <iostream>
#include <sstream>
#include <vector>

void print_result(const std::vector<int> &A);

bool gen_next_combination(std::vector<int> &X, int N, int K);

int main() {
    using namespace std;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int N, K;
    iss >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
    bool ok = true;
    while (ok) {
        print_result(A);
        ok = gen_next_combination(A, N, K);
    }
}

bool gen_next_combination(std::vector<int> &X, const int N, const int K) {
    int i = K - 1; // Xuất phát từ phần tử cuối cùng của tổ hợp
    while (i >= 0 && X[i] == (N - K + i + 1)) {     //Tìm phần tử X[i]N-K+i
        i--;
    }
    if (i >= 0) {
        //Nếu i chưa vượt quá phần tử cuối cùng
        X[i]++; //Thay X[i] = X[i] +1
        for (int j = i + 1; j <= K - 1; j++) {
            //Từ phần tử thứ j +1 đến K
            X[j] = X[i] + j - i; // Thay thế X[j] = X[i] + j – i
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
