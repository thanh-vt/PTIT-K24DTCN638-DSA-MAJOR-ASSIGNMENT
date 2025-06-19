#include <iostream>

void move_step(int n, char a, char b);

void move_tower(int n, char a, char b, char c);

int main() {
    using namespace std;
    int n;
    cin >> n;
    move_tower(n, 'A', 'B', 'C');
}

void move_step(const int n, const char a, const char b) {
    using namespace std;
    cout << "Move disc " << n << " from " << a << " to " << b << endl;
}

void move_tower(const int n, const char a, char b, const char c) {
    if (n == 1) {
        move_step(n, a, c);
    } else {
        move_tower(n - 1, a, c, b);
        move_step(n, a, c);
        move_tower(n - 1, b, a, c);
    }
}
