# Non-recursive (Iterative) Fibonacci function
def fibonacci_non_recursive(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    fib_seq = [0, 1]
    for i in range(2, n + 1):
        fib_seq.append(fib_seq[-1] + fib_seq[-2])
    return fib_seq[n], fib_seq  # Returning both nth value and sequence for demonstration

# Recursive Fibonacci function
def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

# Testing and displaying outputs
n = 10
non_recursive_result, sequence = fibonacci_non_recursive(n)
recursive_result = fibonacci_recursive(n)

print(f"Non-Recursive Fibonacci (n={n}): {non_recursive_result}")
print("Sequence (Non-Recursive):", sequence)
print(f"Recursive Fibonacci (n={n}): {recursive_result}")