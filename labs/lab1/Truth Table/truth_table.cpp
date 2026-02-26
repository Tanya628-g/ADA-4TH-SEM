#include <iostream>
using namespace std;

long long countRows = 0;

void truthTable(int n, string s = "") {
    if (n == 0) {
        countRows++;
        return;
    }
    truthTable(n - 1, s + "T ");
    truthTable(n - 1, s + "F ");
}
int main() {
    int min_n, max_n;
    cout<<"Enter minimum number of variables: ";
    cin>>min_n;
    cout<<"Enter maximum number of variables: ";
    cin>>max_n;
    cout<<endl;
    cout<< "n\t rows(2^n)\n";
    cout<<endl;

    for (int n = min_n; n <= max_n; n++) {
        countRows = 0;
        truthTable(n);
        cout << n << "\t " << countRows << endl;
    }

    return 0;
}