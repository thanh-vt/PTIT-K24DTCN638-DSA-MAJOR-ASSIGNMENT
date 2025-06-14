#include <iostream>
#include <vector>

void print_result(const std::vector<int> &A);

bool gen_next(std::vector<int> &A);

int main() {

using namespace std;
    int n;
    cin >> n;
    vector A(n, 0);
    bool ok = true;
    while (ok) {
        print_result(A);
        ok = gen_next(A);
    }
}

bool gen_next(std::vector<int> &A) {
    size_t i = A.size();
    while (i > 0 && A[i - 1] != 0) {
        A[i - 1] = 0;
        i--;
    }
    if (i > 0) {
        A[i - 1] = 1;
        return true;
    }
    return false;
}

void print_result(const std::vector<int> &A) {
    using namespace std;
    for (const int i : A) {
        cout << i;
    }
    cout << endl;
}
