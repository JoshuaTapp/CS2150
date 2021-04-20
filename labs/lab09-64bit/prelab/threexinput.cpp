#include <iostream>
#include "timer.cpp"
using namespace std;


extern "C" int threexplusone(int x);

int main() {
    timer* stopwatch = new timer();
    int input = 0;
    int iter = 0;
    cout << "Enter a number: ";
    cin >> input;
    cout << "\nEnter iterations of subroutine: ";
    cin >> iter;
    cout << "\n";
    int result = 0;
    stopwatch->start();
    for(int i = 0; i < iter; i++) {
        result = threexplusone(input);
    }
    stopwatch->stop();
    cout << "Iterations: " << result << endl;
}