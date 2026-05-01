#include<iostream>
using namespace std;
#define INF 10000

int main(){
    int v, e, v1, v2, w;
    int stages = 1;

    cout<<"Enter number of vertices: ";
    cin>>v;
    int arr[50][50];
    int current[50], next[50];
    int visited[50] = {0};
    int indegree[50] = {0};

    cout<<"Enter number of edges: ";
    cin>>e;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i == j){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = INF;
            }
        }
    }
    cout<<"Enter edges (u v w):\n";
    for(int i=0; i<e; i++){
        cin>>v1>>v2>>w;

        arr[v1][v2] = w;
        indegree[v2]++;
    }
    int source = 0;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            source = i;
            break;
        }
    }
    int k = 1;
    current[0] = source;
    visited[source] = 1;

    while(true){
        int p = 0;
        for(int i=0; i<k; i++){
            int node = current[i];

            for(int j=0; j<v; j++){
                if(arr[node][j] != 0 && arr[node][j] != INF && visited[j] == 0){
                    next[p] = j;
                    p++;
                    visited[j] = 1;
                }
            }
        }
        if(p == 0){
            break;
        }
        for(int i=0; i<p; i++){
            current[i] = next[i];
        }
        k = p;
        stages++;
    }
    cout<<"Number of stages: "<<stages;
    return 0;
}