#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"enter array elements:\n";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int index = -1;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                index = j;
                break;
            }
        }
        if(index != -1)
            break;
    }
    if(index != -1){
        cout<<"first duplicate found at index: "<<index<< endl;
    }
    else{
        cout<<"no duplicate found"<<endl;
    }

    return 0;
}