# ------------------------------
# LISTS
# ------------------------------

# Creating and Initializing Lists
numbers = [10, 20, 30, 40, 50]
fruits = ["apple", "banana", "cherry"]
mixed = [1, "hello", 3.14, True]

print("Numbers:", numbers)
print("Fruits:", fruits)
print("Mixed:", mixed)

# Accessing elements
print("First element:", numbers[0])
print("Last element:", numbers[-1])

# Slicing
print("Slicing 1 to 3:", numbers[1:4])
print("Every second element:", numbers[::2])

# Traversing list
print("Traversing list:")
for item in fruits:
    print(item, end=" ")
print()

# List Operations
print("Length of numbers:", len(numbers))
print("Concatenation:", numbers + [60, 70])
print("Repetition:", fruits * 2)
print("Is 20 in numbers?", 20 in numbers)
print("Is 100 not in numbers?", 100 not in numbers)
print("Max:", max(numbers))
print("Min:", min(numbers))
print("Sum:", sum(numbers))
print("All True?", all([1, True, "hello"]))
print("Any True?", any([0, False, 5]))

# List Methods
lst = [1, 2, 3]
lst.append(4)
print("After append:", lst)

lst.extend([5, 6])
print("After extend:", lst)

print("Count of 2:", lst.count(2))

lst.remove(3)
print("After remove 3:", lst)

print("Index of 5:", lst.index(5))

lst.pop()
print("After pop:", lst)

lst.insert(1, 10)
print("After insert 10 at index 1:", lst)

lst.sort()
print("After sort:", lst)

lst.reverse()
print("After reverse:", lst)

# ------------------------------
# INTRODUCTION TO SETS
# ------------------------------

my_set = {1, 2, 3, 4, 5}
print("Set:", my_set)

my_set.add(6)
print("After add:", my_set)

my_set.remove(3)
print("After remove 3:", my_set)

print("Is 2 in set?", 2 in my_set)

# ------------------------------
# TUPLES
# ------------------------------

tup = (10, 20, 30, 40)
print("Tuple:", tup)

# Tuple Operations
print("Length:", len(tup))
print("Concatenation:", tup + (50, 60))
print("Repetition:", tup * 2)

# Tuple Functions
print("Count of 20:", tup.count(20))
print("Index of 30:", tup.index(30))

# ------------------------------
# DICTIONARY
# ------------------------------

student = {
    "name": "Alice",
    "age": 21,
    "course": "BCA"
}

print("Dictionary:", student)

# Dictionary Operations
print("Access by key:", student["name"])
print("Using get():", student.get("age"))

# Update
student.update({"age": 22, "city": "Delhi"})
print("After update:", student)

# Copy
student_copy = student.copy()
print("Copied dictionary:", student_copy)

# Deletion
del student["course"]
print("After deleting 'course':", student)

student.pop("city")
print("After popping 'city':", student)