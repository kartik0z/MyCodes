# K-map Solver up to 4 variables
# Uses sympy for Boolean simplification
from sympy import symbols
from sympy.logic.boolalg import SOPform

# Step 1: Get number of variables
n = int(input("Enter number of variables (2 to 4): "))
if n < 2 or n > 4:
    raise ValueError("Only 2, 3, or 4 variables are supported.")

# Step 2: Define variable symbols
if n == 2:
    vars_list = symbols("A B")
elif n == 3:
    vars_list = symbols("A B C")
else:
    vars_list = symbols("A B C D")

# Step 3: Get minterms
minterms = list(map(int, input(f"Enter minterms (0 to {2**n - 1}) separated by space: ").split()))

# Step 4: Get don't-care terms
dontcares = input("Enter don't-care terms (if any) separated by space or press Enter: ")
if dontcares.strip() == "":
    dontcares = []
else:
    dontcares = list(map(int, dontcares.split()))

# Step 5: Simplify using SOPform
simplified_expr = SOPform(vars_list, minterms, dontcares)

# Step 6: Print result
print("\n--- K-map Simplification Result ---")
print(f"Number of variables: {n}")
print(f"Minterms: {minterms}")
print(f"Don't cares: {dontcares}")
print(f"Simplified Expression (SOP form): {simplified_expr}")