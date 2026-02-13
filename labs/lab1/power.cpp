#include <iostream>
#include <chrono>
using namespace std;
// using namespace std::chrono;

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
    cout << "b   a^b" <<"      "<< "time(us)";
    cout << endl<<endl;

    for (int b = min; b <= max; b++) {
        auto start = std::chrono::high_resolution_clock::now();
        int value = Power(a, b);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << b <<"   "<< value <<"\t \t"<< duration.count() << endl;
    }
    return 0;
}
