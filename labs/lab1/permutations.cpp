#include <iostream>
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

    cout << "n" << " " << "permutations(n!)";
    cout << endl;

    for (int n = min; n <= max; n++) {
        string s = "";
        for (int i = 0; i < n; i++) s += char('a' + i);
        countPerm = 0;
        permutation(s, 0, n - 1);
        cout << n << " " << countPerm << endl;
    }
    return 0;
}
