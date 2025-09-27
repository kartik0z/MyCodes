import pickle
import os

filename = "students.dat"

# Append a new record
def append_record(roll, name, marks):
    with open(filename, "ab") as f:
        pickle.dump({"roll": roll, "name": name, "marks": marks}, f)
    print("Record appended successfully!")

# Display all records
def display_records():
    if not os.path.exists(filename):
        print("No records found.")
        return
    with open(filename, "rb") as f:
        print("\n--- Student Records ---")
        try:
            while True:
                record = pickle.load(f)
                print(record)
        except EOFError:
            pass

# Search a record by roll number
def search_record(roll):
    found = False
    with open(filename, "rb") as f:
        try:
            while True:
                record = pickle.load(f)
                if record["roll"] == roll:
                    print("Record Found:", record)
                    found = True
                    break
        except EOFError:
            pass
    if not found:
        print("Record not found.")

# Update marks for a given roll number
def update_record(roll, new_marks):
    records = []
    updated = False
    with open(filename, "rb") as f:
        try:
            while True:
                record = pickle.load(f)
                if record["roll"] == roll:
                    record["marks"] = new_marks
                    updated = True
                records.append(record)
        except EOFError:
            pass
    with open(filename, "wb") as f:
        for r in records:
            pickle.dump(r, f)
    if updated:
        print("Record updated successfully!")
    else:
        print("Roll number not found.")

# Delete a record by roll number
def delete_record(roll):
    records = []
    deleted = False
    with open(filename, "rb") as f:
        try:
            while True:
                record = pickle.load(f)
                if record["roll"] != roll:
                    records.append(record)
                else:
                    deleted = True
        except EOFError:
            pass
    with open(filename, "wb") as f:
        for r in records:
            pickle.dump(r, f)
    if deleted:
        print("Record deleted successfully!")
    else:
        print("Roll number not found.")


# ------------------ Menu ------------------
while True:
    print("\n1. Append Record")
    print("2. Display Records")
    print("3. Search Record")
    print("4. Update Record")
    print("5. Delete Record")
    print("6. Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        roll = int(input("Enter Roll Number: "))
        name = input("Enter Name: ")
        marks = int(input("Enter Marks: "))
        append_record(roll, name, marks)

    elif choice == 2:
        display_records()

    elif choice == 3:
        roll = int(input("Enter Roll Number to Search: "))
        search_record(roll)

    elif choice == 4:
        roll = int(input("Enter Roll Number to Update: "))
        new_marks = int(input("Enter New Marks: "))
        update_record(roll, new_marks)

    elif choice == 5:
        roll = int(input("Enter Roll Number to Delete: "))
        delete_record(roll)

    elif choice == 6:
        print("Exiting...")
        break

    else:
        print("Invalid choice! Try again.")
