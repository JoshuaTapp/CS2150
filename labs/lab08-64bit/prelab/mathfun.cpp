// Joshua Tapp
// UVA CS2150
// 4/13/2021

#include <iostream>
#include <cstdlib>
using namespace std;

extern "C" long product (long a, long b);
extern "C" long power (long a, long b);

int main() {
    long x, y;
    cout << "Enter integer 1: ";
    cin >> x;
    cout << "\nEnter integer 2: ";
    cin >> y;
    cout << "\nProduct: " << product(x,y) << "\nPower: " << power(x,y) << "\n";
    return 0;
}
