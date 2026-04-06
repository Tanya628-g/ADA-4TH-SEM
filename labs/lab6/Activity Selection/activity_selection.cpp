#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;

const int MAX = 100;
struct job {
    int start;
    int finish;
};

bool comp(job a, job b) {
    return a.finish < b.finish;
}
int job_scheduling(job jobs[], int n) {
    sort(jobs, jobs + n, comp);
    int count = 1;  
    int last_finish = jobs[0].finish;

    for(int i=1; i<n; i++) {
        if(jobs[i].start >= last_finish) {
            count++;
            last_finish = jobs[i].finish;
        }
    }
    return count;
}
int main() {
    int min_el, max_el;
    job jobs[MAX];

    srand(time(0));
    ofstream fout("job_scheduling.txt");
    cout << "Enter minimum number of jobs: ";
    cin >> min_el;
    cout << "Enter maximum number of jobs: ";
    cin >> max_el;
    cout << endl;

    fout << "n time_ns selected_jobs\n";
    for(int n=min_el; n<=max_el; n++) {
        cout << "Number of jobs= "<<n<< endl;
        for(int i=0; i<n; i++) {
            jobs[i].start = rand() % 50;
            jobs[i].finish = jobs[i].start +(rand() % 50 + 1);

            cout <<"("<< jobs[i].start <<","<< jobs[i].finish <<")";
        }
        cout << endl;

        auto start_time = chrono::high_resolution_clock::now();
        int result = job_scheduling(jobs, n);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

        cout << "Selected non-overlapping jobs = " << result << endl;
        cout << "Time taken(ns) = " << duration.count() << endl << endl;
        
        fout<<n<<" "<<duration.count() <<" " <<result<<"\n";
    }
    fout.close();

    return 0;
}