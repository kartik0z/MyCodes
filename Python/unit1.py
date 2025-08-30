# ------------------------------
# Basic Introduction to Python
# ------------------------------

# Origin & Need:
# Python was created by Guido van Rossum in 1991.
# It is simple, easy to read, and versatile for web, AI, data science, automation, etc.

# Features:
# - Simple & easy to learn
# - Interpreted language
# - Portable
# - Dynamically typed
# - Large library support

# ------------------------------
# Program Structure
# ------------------------------

# This is a simple Python program
print("Hello, Python!")

# ------------------------------
# Identifiers and Reserved Words
# ------------------------------

# Identifiers: names given to variables, functions, classes
name = "Python"

# Reserved words (keywords) cannot be used as identifiers
# Examples: if, else, while, for, break, class, def, return

import keyword
print("Python Keywords:", keyword.kwlist)

# ------------------------------
# Escape Sequences
# ------------------------------

print("Hello\nWorld")   # newline
print("Tab\tSpace")     # tab
print("This is a quote: \"Python\"")

# ------------------------------
# IDLE and Interpreter
# ------------------------------

# IDLE is Python’s integrated development environment.
# The interpreter executes Python code line by line.

# ------------------------------
# Python Programming Introduction
# ------------------------------

a, b = 10, 3

# Relational Operators
print("a == b:", a == b)
print("a > b:", a > b)
print("a < b:", a < b)

# Logical Operators
print("a > 5 and b < 5:", a > 5 and b < 5)
print("a > 5 or b > 5:", a > 5 or b > 5)
print("not(a > b):", not (a > b))

# Bitwise Operators
print("a & b:", a & b)   # AND
print("a | b:", a | b)   # OR
print("a ^ b:", a ^ b)   # XOR
print("a << 1:", a << 1) # Left shift
print("a >> 1:", a >> 1) # Right shift

# Variables and Assignment
x = 100
y = x + 50
print("x:", x, "y:", y)

# ------------------------------
# Control Structures
# ------------------------------

num = 7

# if condition
if num > 5:
    print("Number is greater than 5")

# if-else condition
if num % 2 == 0:
    print("Even number")
else:
    print("Odd number")

# if-elif-else condition
marks = 85
if marks >= 90:
    print("Grade: A")
elif marks >= 75:
    print("Grade: B")
elif marks >= 50:
    print("Grade: C")
else:
    print("Grade: Fail")

# Nested if-elif-else
n = -5
if n >= 0:
    if n == 0:
        print("Number is Zero")
    else:
        print("Number is Positive")
else:
    print("Number is Negative")

# Loops
print("For loop from 1 to 5:")
for i in range(1, 6):
    print(i, end=" ")
print()

print("While loop from 5 to 1:")
count = 5
while count > 0:
    print(count, end=" ")
    count -= 1
print()

# Nested Loop
print("Nested Loop Example:")
for i in range(1, 4):
    for j in range(1, 4):
        print(f"({i},{j})", end=" ")
    print()

# break example
print("Break Example:")
for i in range(10):
    if i == 5:
        break
    print(i, end=" ")
print()

# ------------------------------
# Strings
# ------------------------------

text = "hello python programming"

# Slicing
print("Slicing:", text[0:5])    # hello
print("Reverse Slicing:", text[::-1])

# Membership
print("'python' in text:", "python" in text)

# Built-in Functions
print("Count 'o':", text.count('o'))
print("Find 'python':", text.find('python'))
print("Capitalize:", text.capitalize())
print("Title:", text.title())
print("Lower:", text.lower())
print("Upper:", text.upper())
print("Swapcase:", text.swapcase())
print("Replace:", text.replace("python", "world"))
print("Join:", "-".join(["a", "b", "c"]))
print("isspace:", "   ".isspace())
print("isdigit:", "123".isdigit())
print("Split:", text.split())
print("Startswith 'hello':", text.startswith("hello"))
print("Endswith 'ing':", text.endswith("ing"))