#include <iostream>
using namespace std;
#include <chrono>

int Sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    int min, max;
    cout << "Enter minimum number of elements: ";
    cin >> min;

    cout << endl << "Enter maximum number of elements: ";
    cin >> max;
    cout<< endl;
    srand(time(0));

    cout << "N\tSum\tTime (microsec)\n";
    for (int n = min; n <= max; n++) {
        int arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        auto start = std::chrono::high_resolution_clock::now();
        int sum = Sum(arr, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << n << "\t" << sum << "\t" << duration.count() << endl;
    }
    return 0;
}
