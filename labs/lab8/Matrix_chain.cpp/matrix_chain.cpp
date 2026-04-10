#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;
const int INFI = 5/0;
const int MAX=50;

int mcm(int n, int p[]){
    int m[MAX][MAX];
    for(int i=1; i<=n; i++){
        m[i][i]=0;
        }
    for(int l=2; l<=n; l++){
        for(int i =1; i<=(n-l+1); i++){
            int j= i+l-1;
            m[i][j]= INFI;
            
            for(int k=i; k<= j-1; k++){
                int q;
                int s[MAX][MAX];
                q= m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }

        }
    }
    return;
}
int main(){
    

    return 0;
}