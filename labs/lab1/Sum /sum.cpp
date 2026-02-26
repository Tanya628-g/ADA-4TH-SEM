#include <iostream>
#include<fstream>
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

    ofstream fout("sum.txt");
    fout<<"n  time_ns"<<endl;

    for (int n = min; n <= max; n++) {
        cout<<"array of elements ";
        int arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
            cout<<arr[i]<<" ";
        }
        cout<<endl<<"Sum= "<<Sum(arr, n);    

        auto start = std::chrono::high_resolution_clock::now();
        int sum = Sum(arr, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

       cout<<endl<<"Time Taken = "<<duration.count()<<endl;
       fout<<n<<" "<<duration.count()<<endl;
    }
    return 0;
}
