#include<iostream>
#include<climits>
using namespace std;

int n;
int cost[20][20];
int visited[20];
int ans = INT_MAX;

void tsp(int city, int count, int sum){
    if(count == n){
        if(cost[city][0] != 0){
            ans = min(ans, sum + cost[city][0]);
        }
        return;
    }
    for(int next=0; next<n; next++){
        if(visited[next] == 0 && cost[city][next] != 0){
            visited[next] = 1;
            tsp(next, count + 1, sum + cost[city][next]);

            visited[next] = 0;
        }
    }
}
int main(){
    cout<<"enter number of cities: ";
    cin>>n;

    cout<<"enter cost matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cost[i][j];
        }
    }
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    visited[0] = 1;
    tsp(0, 1, 0);
    cout<<"minimum cost: "<<ans;

    return 0;
}