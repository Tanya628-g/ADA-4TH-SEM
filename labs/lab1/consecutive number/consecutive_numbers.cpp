#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "enter consecutive numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int missing = -1;

    for (int i = 0; i < n - 1; i++) {
        int ele = arr[i];
        ele++;

        if (arr[i + 1] != ele) {
            missing = ele;
            break;
        }
    }

    if (missing != -1)
        cout << "missing number is: " << missing << endl;
    else
        cout << "no number is missing" << endl;

    return 0;
}