#include<iostream>
#include<chrono>
#include<fstream>
#include<climits>
using namespace std;

const int MAX = 20;

int n;
int cost[MAX][MAX];
int visited[MAX];
int ans;

void tsp(int city, int count, int sum){
    if(count == n){
        if(cost[city][0] != 0){
            ans = min(ans, sum + cost[city][0]);
        }
        return;
    }

    for(int next = 0; next < n; next++){
        if(!visited[next] && cost[city][next] != 0){
            visited[next] = 1;

            tsp(next, count + 1, sum + cost[city][next]);

            visited[next] = 0;
        }
    }
}

int main(){
    int min_n, max_n;

    srand(time(0));
    ofstream fout("tsp.txt");

    cout<<"Enter minimum number of cities: ";
    cin>>min_n;

    cout<<"Enter maximum number of cities: ";
    cin>>max_n;
    cout<<endl;

    fout<<"n time_ns"<<endl;

    for(n = min_n; n <= max_n; n++){
        cout<<"Cities = "<<n<<endl;

        // generate random cost matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    cost[i][j] = 0;
                }
                else{
                    cost[i][j] = rand() % 50 + 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }

        visited[0] = 1;
        ans = INT_MAX;

        auto start = chrono::high_resolution_clock::now();

        tsp(0, 1, 0);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Minimum cost = "<<ans<<endl;
        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;

        fout<<n<<" "<<duration.count()<<endl;
    }

    fout.close();
    return 0;
}