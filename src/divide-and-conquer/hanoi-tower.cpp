#include <iostream>
#include <vector>

void move(int n, char a, char b);

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

void move(int n, char a, char b) {
}
