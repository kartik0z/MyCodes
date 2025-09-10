letter = ['a','b','c','d','e','f','g','h','i','j']
print("Middle 3 letters: ", letter[3:6])
print("First 3 letters: ", letter[:3])
print("From index 6 to end: ", letter[6:])

# New slicing examples
print("Last 3 letters: ", letter[-3:])
print("Every other letter (starting from beginning): ", letter[::2])
print("Letters from index 2 to 7, stepping by 2: ", letter[2:8:2])
print("Reversed list: ", letter[::-1])
print("First 5 letters: ", letter[:5])
print("Letters from index 4 to 8: ", letter[4:9])