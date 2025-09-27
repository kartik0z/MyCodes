import csv

filename = "users.csv"

def add_user():
    file_exists = False
    try:
        with open(filename, "r") as f:
            file_exists = True
    except FileNotFoundError:
        file_exists = False

    with open(filename, "a", newline="") as f:
        writer = csv.writer(f)
        if not file_exists:
            writer.writerow(["UserID", "Password"])  
        n = int(input("Enter number of users to add: "))
        for _ in range(n):
            uid = input("Enter User ID: ")
            pwd = input("Enter Password: ")
            writer.writerow([uid, pwd])
    print("✅ User(s) added successfully!")

def search_password(user_id):
    try:
        with open(filename, "r") as f:
            reader = csv.reader(f)
            next(reader)
            for row in reader:
                if row[0] == user_id:
                    print(f"Password for user '{user_id}' is: {row[1]}")
                    return
            print("❌ User ID not found.")
    except FileNotFoundError:
        print("❌ CSV file not found. Please create it first.")

while True:
    print("\n1. Add User(s)")
    print("2. Search Password by User ID")
    print("3. Exit")

    try:
        choice = int(input("Enter your choice: "))

        if choice == 1:
            add_user()
        elif choice == 2:
            uid = input("Enter User ID to search: ")
            search_password(uid)
        elif choice == 3:
            print("👋 Exiting...")
            break
        else:
            print("❌ Invalid choice! Try again.")
    except ValueError:
        print("❌ Invalid input! Please enter a number.")
        