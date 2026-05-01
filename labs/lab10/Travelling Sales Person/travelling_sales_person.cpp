#include<iostream>
#include<chrono>
#include<fstream>

using namespace std;
const int MAX = 50;

void tsp(int n, int arr[MAX][MAX]){

}
int main(){
    int n;
    int arr[n][n];

    cout<<"Enter number of cities: ";
    cin>>n;

    cout<<"Entter distance matrix: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Distance from "<<i+1<<"to "<<j+1<<": ";
            cin>>arr[i][j];
        }
    }
    cout<<"Distance Matrix"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}