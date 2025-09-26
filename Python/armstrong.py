n = int(input("Enter a number: "))
s = str(n)
power = len(s)
total = sum(int(d) ** power for d in s)
if total == n:
    print(n, "is an Armstrong number")
else:
    print(n, "is NOT an Armstrong number")
