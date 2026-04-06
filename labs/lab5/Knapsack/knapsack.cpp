#include<iostream>
using namespace std;
const int max_size=100;

void by_profit(float arr[][3], int n) {
    for (int i = 1; i < n; i++) {
        float key0 = arr[i][0];
        float key1 = arr[i][1];
        float key2 = arr[i][2];
        int j = i - 1;

        while (j >= 0 && arr[j][0] < key0) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            arr[j + 1][2] = arr[j][2];
            j--;
        }

        arr[j + 1][0] = key0;
        arr[j + 1][1] = key1;
        arr[j + 1][2] = key2;
    }
}
void by_weight(float arr[][3], int n) {
    for (int i = 1; i < n; i++) {
        float key0 = arr[i][0];
        float key1 = arr[i][1];
        float key2 = arr[i][2];
        int j = i - 1;

        while (j >= 0 && arr[j][1] > key1) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            arr[j + 1][2] = arr[j][2];
            j--;
        }

        arr[j + 1][0] = key0;
        arr[j + 1][1] = key1;
        arr[j + 1][2] = key2;
    }
}
void by_pr_wt(float arr[][3], int n) {
    for (int i = 1; i < n; i++) {
        float key0 = arr[i][0];
        float key1 = arr[i][1];
        float key2 = arr[i][2];
        int j = i - 1;

        while (j >= 0 && arr[j][2] < key2) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            arr[j + 1][2] = arr[j][2];
            j--;
        }

        arr[j + 1][0] = key0;
        arr[j + 1][1] = key1;
        arr[j + 1][2] = key2;
    }
}

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