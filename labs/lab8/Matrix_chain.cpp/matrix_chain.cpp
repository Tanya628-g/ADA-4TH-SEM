#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;
using namespace chrono;
const int MAX = 50;

void print(int s[MAX][MAX], int i, int j){
    if(i == j){
        cout<<"A"<< i;
    }
    else{
        cout << "(";
        print(s, s[i][j] + 1, j);
        print(s, i, s[i][j]);
        cout << ")";
    }
}
int mcm(int n, int p[]){
    int m[MAX][MAX];
    int s[MAX][MAX];
    for(int i=1; i<=n; i++){
        m[i][i] = 0;
    }
    for(int l=2; l<=n; l++){
        for(int i=1; i<=(n-l+1); i++){
            int j=i+l-1;
            m[i][j] = 999;

            for(int k=i; k<=j - 1; k++){
                int q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "\nm=";
    for(int l=2; l<=n; l++){
        for(int i=1; i<=(n-l+1); i++){
            int j=i+l-1;
            cout<<m[i][j]<< " ";
        }
    }
    cout << "\ns=";
    for(int l=2; l<=n; l++){
        for(int i=1; i<=(n-l+1); i++){
            int j=i+l-1;
            cout<<s[i][j]<< " ";
        }
    }
    cout << "\nMinmum Oder: ";
    print(s, 1, n);
    cout<<endl;
    return m[1][n];
}
int main(){
    int min, max;
    cout << "Enter minimum matrices: ";
    cin >> min;
    cout << "Enter maximum matrices: ";
    cin >> max;

    srand(time(0));
    ofstream fout("mcm.txt");
    fout << "n time_ns" << endl;

    for(int n = min; n <= max; n++){
        cout << "\nNumber of matrices = " << n;

        int p[MAX];
        cout<<endl;
        cout << "Order: ";
        for(int i=0; i<=n; i++){
            p[i]= rand() % 10 + 1;
            cout<<p[i]<< " ";
        }
        cout << endl;

        auto start = high_resolution_clock::now();
        int cost = mcm(n, p);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);

        cout<<"Minimum cost= "<<cost<< endl;
        cout<<"Time Taken= "<<duration.count()<<" ns\n";

        fout<<n<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}