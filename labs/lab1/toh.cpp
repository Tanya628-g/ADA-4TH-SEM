#include <iostream>
#include <stack>
#include <chrono>
using namespace std;

void TOH(int n, stack<int> &source, stack<int> &through, stack<int> &destination) {
    if (n == 0) return;
    TOH(n - 1, source, destination, through);
    destination.push(source.top());
    source.pop();
    TOH(n - 1, through, source, destination);
}
int main() {
    int min, max;
    cout << "Enter min number of disks: ";
    cin >> min;

    cout << "Enter max number of disks: ";
    cin >> max;
    cout<<endl;
    cout << "n" << "  "<< "time(us)";
    cout <<endl;

    for (int n = min; n <= max; n++) {
        stack<int> source, through, destination;
        for (int i = n; i >= 1; i--) {
            source.push(i);
        }
        auto start = std::chrono::high_resolution_clock::now();
        TOH(n, source, through, destination);
        auto end = std::chrono::high_resolution_clock::now();

         std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << n << "  " << duration.count() << endl;
    }
    return 0;
}
