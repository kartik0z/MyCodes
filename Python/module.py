# Write a program that defines a function large in a module which will be used to find larger of two values and called from code in another module

def large(a, b):
    if a > b:
        return a
    else:
        return b