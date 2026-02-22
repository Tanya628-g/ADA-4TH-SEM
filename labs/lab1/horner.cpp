#include <iostream>
#include <chrono>
using namespace std;
// using namespace std::chrono;

int hornersRule(int arr[], int n, int x) {
    int result = arr[0];
    for (int i=1; i<n; i++) {
        result = result * x + arr[i];
    }
    return result;
}
int main() {
    int min, max;
    cout << "Enter minimum degree of polynomial: ";
    cin >> min;
    cout << "Enter maximum degree of polynomial: ";
    cin >> max;
    cout<<endl;
    cout << "n\t time(us)\n";
    cout << endl;

    for (int n = min; n <= max; n++) {
        int arr[100];
        for (int i = 0; i <= n; i++) {
            arr[i] = 1;
        }
        int x = 2;
        auto start = std::chrono::high_resolution_clock::now();
        hornersRule(arr, n + 1, x);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        // int time_us = duration_cast<microseconds>(end - start).count();
        // cout << n << "\t " << time_us << endl;
    }
    return 0;
}
