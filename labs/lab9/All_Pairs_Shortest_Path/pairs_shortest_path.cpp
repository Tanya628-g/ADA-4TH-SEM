#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
int const MAX = 50;

void shortest_path(int cost[MAX][MAX], int A[MAX][MAX], int vertices){
    for(int i=1; i<=vertices; i++){
        for(int j=1; j<=vertices; j++){
            A[i][j] = cost[i][j];
        }
    }
    for(int k=1; k<= vertices; k++){
        for(int i=1; i<=vertices; i++){
            for(int j=1; j<=vertices; j++){
                A[i][j]= min(A[i][j], (A[i][k] + A[k][j]));
            }
        }
    }

}

int main(){
    int v, e, cost;
    int graph[MAX][MAX];

    cout<<"Enter number of Vertices: ";
    cin>>v;

    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<"Enter cost for vertex "<<i<<" to vertex "<<j<<" : ";
            cin>>graph[i][j];
        }
    }
    cout<<"Initial Graph with costs"<<endl;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<shortest_path(graph, A, v);

    return 0;
}