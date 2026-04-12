#include<iostream>
using namespace std;
#include<chrono>
#include<fstream>
const int MAX = 50;

void matrix_multiply(int A[][MAX], int B[][MAX], int C[][MAX], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int main(){
    int min, max;
    cout << "enter minimum size of matrix ";
    cin >> min;
    cout << "enter maximum size of matrix ";
    cin >> max;

    srand(time(0));
    ofstream fout("matrix_multiplication.txt");
    fout << "n time_ns\n";

    for(int n = min; n <= max; n++){
        int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

        cout<<"\nMatrix size= "<<n<<"x"<<n<< endl;
        cout<<"Matrix A:\n";
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                A[i][j]= rand() % 10;
                cout<<A[i][j]<< " ";
            }
            cout << endl;
        }
        cout << "Matrix B:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                B[i][j] = rand() % 10;
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
        auto start = chrono::high_resolution_clock::now();
        matrix_multiply(A, B, C, n);
        auto end = chrono::high_resolution_clock::now();

        cout<<"Result Matrix C:\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<C[i][j]<<"\t";
            }
            cout << endl;
        }
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout << "Time Taken = " << duration.count() << " ns\n";

        fout << n << " " << duration.count() << endl;
    }
    return 0;
}