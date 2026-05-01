#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
const int max = 100;

int horner(int coeff[], int n, int x){
    if(n == 0){
        return coeff[0];
    }
    return x * horner(coeff, n-1, x) + coeff[n];
}
int main(){
    int x;
    cout<<"Enter value of x: ";
    cin>>x;

    int min, max;
    cout<<"Enter minimum degree of polynomial: ";
    cin>>min;
    cout<<"Enter maximum degree of polynomial: ";
    cin>>max;

    srand(time(0));
    ofstream fout("horner_rule.txt");
    fout << "n time_ns"<<endl;

    for(int n = min; n <= max; n++){
        cout<<"\nPolynomial degree = "<<n<<endl;

        int coeff[max];
        cout<<"Coefficients: ";
        for(int i = 0; i <= n; i++){
            coeff[i] = rand() % 10;
            cout<<coeff[i]<<" ";
        }
        cout<<endl;

        auto start = chrono::high_resolution_clock::now();
        int result = horner(coeff, n, x);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Polynomial value = "<<result<<endl;
        cout<<"Time taken: "<<duration.count()<<" ns"<<endl;
        fout<<n<<" "<<duration.count()<<endl;
    }
    return 0;
}