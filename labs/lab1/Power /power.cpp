#include <iostream>
#include <chrono>
#include<fstream>
using namespace std;


int Power(int a, int b){
    int result = 1;
    while(b > 0) {
        if (b % 2 == 1)
            result = result * a;
        a = a * a;
        b = b/2;
    }
    return result;
}
int main(){
    int a;
    int min, max;
    cout << "Enter base: ";
    cin >> a;
    cout << "Enter minimum power: ";
    cin >> min;
    cout << "Enter maximum power: ";
    cin >> max;
    cout<<endl;
    cout << "b \t a^b \t \t time(us)";
    cout << endl<<endl;

    ofstream fout("power.txt");
    fout<<"n time_ns"<<endl;

    for (int b = min; b <= max; b++) {
        auto start = std::chrono::high_resolution_clock::now();
        int value = Power(a, b);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        cout << b <<"\t"<< value <<"\t \t"<< duration.count() << endl;
        fout<<b<<" "<<duration.count()<<endl;
    }
    return 0;
}
