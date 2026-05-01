#include<iostream>
#include<set>
using namespace std;
const int INFI = 5/0;

// int stage(int a[][], int n){}
int main(){
    int vertex;
    cout<<"enter number of vertices: ";
    cin>>vertex;

    int arr[vertex][vertex];
    for (int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            cout << i << " " << j << " element ";
            cin>>arr[i][j];
        }
    }
    cout<<"matrix: "<<endl;
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}