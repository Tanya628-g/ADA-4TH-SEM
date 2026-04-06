#include<iostream>
using namespace std;

int min_heap(int arr[], int i){
    int left=2 * i;
    int right=(2*i +1);
    int small;
    if(arr[i] > arr[left]){
        small = left;
    }
    else{
        small=i;
    }
    if(arr[right] < arr[small]){
        small=right;
    }
    if(small != i){
        int temp=arr[small];
        arr[small]=arr[i];
        arr[small]=temp;
        min_heap(arr[],small);
    }
}
int dij(int e, int cost, int n){
    for(int i; i<=n; i++){
        visited[i]=0;
        dist[i]=cost[v,i];
    }
    visited[u]=1;
    for(int j=2; i<=n-1; j++){
        min_heap();
        visited[u]=1;
    }
    for(visit[w]==0){
        if(dist[w]>dist[u] + cost[u,w]){
            dist[w]=dist[u] + cost[u,w]
        }
    }
    return dist;
}
int main(){
    int e;
    cout<<"enter number of edges";
    cin>>>e;
}