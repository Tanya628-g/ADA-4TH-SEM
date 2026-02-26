#include<iostream>
using namespace std;
const int max_size=100;

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int by_profit(int arr[][3], int size){

}
int by_weighht(){}
int pr_wt(){}

int main(){
    int min, max;
    float arr[max_size][3];
    cout<<"enter minimum number of items in list ";
    cin>>min;

    cout<< "enter maximum number of items in list ";
    cin>>max;
    srand(time(0));

    for(int l=min; l<=max; l++){
        cout<<endl<<"list size "<<l<<endl<<"Profit  Weight  Profit/Weight"<<endl;
        for(int i=0; i<l; i++){
            for(int j=0; j<2; j++){
                arr[i][j]= rand() % 100;
                cout<<arr[i][j]<<"        ";
            }
        arr[i][2]= (double)arr[i][1] / arr[i][0];
        cout<<arr[i][2]<<endl;
        }
    }
    return 0;
}