# Iterative approach to calculate Fibonacci numbers
def fibonacci_iterative(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a

# Recursive approach to calculate Fibonacci numbers
def fibonacci_recursive(n):
    if n <= 1:
        return n
    else:
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

# Example usage
n = int(input("Enter a number: "))
print(f"Fibonacci (Iterative) of {n}:", fibonacci_iterative(n))
print(f"Fibonacci (Recursive) of {n}:", fibonacci_recursive(n))
