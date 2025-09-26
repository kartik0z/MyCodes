# Write a program that uses a user defined function that accepts name and gender (as M for Male, F for Female) and prefixes Mr./Ms. on the basis of the gender.SS

def prefix(name, gender):
    if gender == "M":
        print(f"Mr. {name}")
    else:
        print(f"Ms. {name}")

prefix("John", "M")
prefix("Alice", "F")