#include<iostream>
using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, fib;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int n;
    cout << "Enter the position of Fibonacci number to find: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fibonacci_iterative(n) << endl;
    return 0;
}
