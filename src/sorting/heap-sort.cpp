#include <iostream>
#include <sstream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) ;

void heap_sort(std::vector<int>& arr) ;

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
    heap_sort(A);
    for (const int i : A) {
        cout << i << " ";
    }
}

// Hàm để "heapify" một cây con tại vị trí i trong heap có kích thước n
void heapify(std::vector<int>& arr, const int n, const int i) {
    int largest = i;        // Gốc
    const int left = 2 * i + 1;   // Con trái
    const int right = 2 * i + 2;  // Con phải

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn largest hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu largest không phải là gốc
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Đệ quy heapify lại cây con bị ảnh hưởng
        heapify(arr, n, largest);
    }
}

// Hàm heap sort chính
void heap_sort(std::vector<int>& arr) {
    const int n = arr.size();

    // Xây dựng heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất từng phần tử một từ heap
    for (int i = n - 1; i > 0; i--) {
        // Di chuyển gốc hiện tại về cuối
        std::swap(arr[0], arr[i]);

        // Gọi heapify trên heap giảm kích thước
        heapify(arr, i, 0);
    }
}