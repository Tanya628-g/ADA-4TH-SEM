#include<iostream>
using namespace std;

int arr[20];
int x[20];
int n, target;

void subsetsum(int index, int sum){
    if(sum == target){
        cout<<"subset: ";
        for(int i = 0; i < index; i++){
            if(x[i] == 1){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    if(index == n || sum > target){
        return;
    }
    x[index] = 1;
    subsetsum(index + 1, sum + arr[index]);

    x[index] = 0;
    subsetsum(index + 1, sum);
}
int main(){
    cout<<"enter number of elements: ";
    cin>>n;

    cout<<"enter elements:\n";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"enter target sum: ";
    cin>>target;

    subsetsum(0, 0);
    return 0;
}