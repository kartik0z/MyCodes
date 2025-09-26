def concat(a, b): return a + b
def length(a): return len(a)
def compare(a, b): return a == b
def reverse(a): return a[::-1]
def to_upper(a): return a.upper()
def to_lower(a): return a.lower()

s1 = input("Enter string 1: ")
s2 = input("Enter string 2: ")

menu = """Choose:
1. Concatenate
2. Lengths
3. Compare (equal?)
4. Reverse both
5. Upper case both
6. Lower case both
7. Exit
"""
while True:
    choice = input(menu + "Enter choice: ")
    if choice == "1":
        print("Concat:", concat(s1, s2))
    elif choice == "2":
        print("Lengths:", length(s1), length(s2))
    elif choice == "3":
        print("Equal?:", compare(s1, s2))
    elif choice == "4":
        print("Reverse s1:", reverse(s1))
        print("Reverse s2:", reverse(s2))
    elif choice == "5":
        print("Upper s1:", to_upper(s1))
        print("Upper s2:", to_upper(s2))
    elif choice == "6":
        print("Lower s1:", to_lower(s1))
        print("Lower s2:", to_lower(s2))
    elif choice == "7":
        break
    else:
        print("Invalid choice")
