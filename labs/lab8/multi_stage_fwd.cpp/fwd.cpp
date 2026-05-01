#include<iostream>
#include<fstream>
#include<chrono>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace chrono;

const int MAX = 50;
const int INF = 1e9;

// Print path
void printPath(int path[], int k){
    cout << "Path: ";
    for(int i = 1; i <= k; i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

// Forward Multistage Graph
int fmg(int n, int cost[MAX][MAX]){
    int mcost[MAX];
    int d[MAX];
    int path[MAX];

    mcost[n] = 0;

    // DP computation
    for(int j = n - 1; j >= 1; j--){
        mcost[j] = INF;

        for(int r = j + 1; r <= n; r++){
            if(cost[j][r] != INF){
                if(cost[j][r] + mcost[r] < mcost[j]){
                    mcost[j] = cost[j][r] + mcost[r];
                    d[j] = r;
                }
            }
        }
    }

    // Path construction
    int k = 1;
    path[1] = 1;

    while(path[k] != n){
        path[k + 1] = d[path[k]];
        k++;
    }

    // Print arrays (vertical style like your MCM)
    cout << "\nmcost = ";
    for(int i = 1; i <= n; i++){
        cout << mcost[i] << " ";
    }

    cout << "\nd = ";
    for(int i = 1; i < n; i++){
        cout << d[i] << " ";
    }

    cout << endl;
    printPath(path, k);

    return mcost[1];
}

int main(){
    int min, max;
    cout << "Enter minimum vertices: ";
    cin >> min;
    cout << "Enter maximum vertices: ";
    cin >> max;

    srand(time(0));

    ofstream fout("fmg.txt");
    fout << "n time_ns" << endl;

    for(int n = min; n <= max; n++){
        cout << "\nNumber of vertices = " << n << endl;

        int cost[MAX][MAX];

        // Generate random DAG (upper triangular matrix)
        cout << "Cost Matrix:\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j <= i){
                    cost[i][j] = INF; // no backward edges
                }
                else{
                    int val = rand() % 20 + 1;

                    // randomly remove some edges
                    if(rand() % 3 == 0)
                        cost[i][j] = INF;
                    else
                        cost[i][j] = val;
                }

                if(cost[i][j] == INF)
                    cout << "INF ";
                else
                    cout << cost[i][j] << " ";
            }
            cout << endl;
        }

        // Timing
        auto start = high_resolution_clock::now();
        int minCost = fmg(n, cost);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start);

        cout << "Minimum cost = " << minCost << endl;
        cout << "Time Taken = " << duration.count() << " ns\n";

        fout << n << " " << duration.count() << endl;
    }

    fout.close();
    return 0;
}