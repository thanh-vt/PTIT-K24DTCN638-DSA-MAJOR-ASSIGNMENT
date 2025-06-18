#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void merge_sort(std::vector<int>& arr, int left, int right);

void merge(std::vector<int>& arr, int left, int mid, int right);

int main() {
    using namespace std;
    int num;
    vector<int> A;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> num) {
        A.push_back(num);
    }
    merge_sort(A, 0, A.size() - 1);
    for (const int i : A) {
        cout << i << " ";
    }
}

// Hợp nhất 2 phần của mảng đã được sắp xếp
void merge(std::vector<int>& arr, const int left, const int mid, const int right) {
    // Tạo 2 mảng con
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    // Trộn 2 mảng lại
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Sao chép phần còn lại
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Hàm merge sort chính
void merge_sort(std::vector<int>& arr, const int left, const int right) {
    if (left < right) {
        const int mid = left + (right - left) / 2;

        // Gọi đệ quy sắp xếp 2 nửa
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Gộp 2 nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}
