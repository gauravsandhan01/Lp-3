#include <iostream>
using namespace std;

// Iterative approach to calculate Fibonacci numbers
int fibonacci_iterative(int n) 
{
    int a = 0, b = 1, fib = 0;
    for (int i = 1; i < n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return n > 0 ? b : 0;
}

// Recursive approach to calculate Fibonacci numbers
int fibonacci_recursive(int n) 
{
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() 
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci (Iterative) of " << n << ": " << fibonacci_iterative(n) << endl;
    cout << "Fibonacci (Recursive) of " << n << ": " << fibonacci_recursive(n) << endl;

    return 0;
}
