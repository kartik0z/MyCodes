def is_prime(n):
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True

a = int(input("Enter lower bound: "))
b = int(input("Enter upper bound: "))
if a > b:
    a, b = b, a

primes = [p for p in range(a, b+1) if is_prime(p)]
print("Primes:", primes)
print("Sum of primes:", sum(primes))
