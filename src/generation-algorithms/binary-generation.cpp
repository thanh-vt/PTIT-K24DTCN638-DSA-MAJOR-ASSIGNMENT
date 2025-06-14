#include <iostream>
#include <vector>

using namespace std;

void print_result(const vector<int> &A);

bool gen_next(vector<int> &A);

int main() {
    vector A = {0, 0, 0, 0};
    bool ok = true;
    while (ok) {
        print_result(A);
        ok = gen_next(A);
    }
    return EXIT_SUCCESS;
}

bool gen_next(vector<int> &A) {
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

void print_result(const vector<int> &A) {
    using namespace std;
    for (const int i : A) {
        cout << i;
    }
    cout << endl;
}
