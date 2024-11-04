#include <iostream>
using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter the position of Fibonacci number to find: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fibonacci_recursive(n) << endl;
    return 0;
}
