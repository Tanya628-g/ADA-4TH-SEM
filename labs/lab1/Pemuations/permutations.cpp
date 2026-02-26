#include <iostream>
#include<fstream>
#include<chrono>
using namespace std;

long long countPerm = 0;

void permutation(string s, int l, int r) {
    if(l == r) {
        countPerm++;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permutation(s, l + 1, r);
        swap(s[l], s[i]);
    }
}
int main() {
    int min, max;
    cout << "Enter minimum string length: ";
    cin >> min;
    cout << "Enter maximum string length: ";
    cin >> max;
    cout<<endl;

    ofstream fout("permuatations.txt");
    fout<<"n time_ns"<<endl;

    cout << "n" << " " << "permutations(n!)"<< " " << "time(ns)" << endl;
    cout << endl;

    for (int n = min; n <= max; n++) {
        string s = "";
        for (int i = 0; i < n; i++) s += char('a' + i);
        countPerm = 0;
        auto start= chrono::high_resolution_clock::now();
        permutation(s, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        fout << n << " " << duration.count() << endl;
        cout << n << " " << countPerm << " " << duration.count() << endl;
    }
    return 0;
}
