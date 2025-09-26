months = {
    "January":31, "February":28, "March":31, "April":30,
    "May":31, "June":30, "July":31, "August":31,
    "September":30, "October":31, "November":30, "December":31
}

def days_in_month(month, leap=False):
    if month.lower() == "february" and leap:
        return 29
    return months.get(month.capitalize(), None)

m = input("Enter month name: ")
d = days_in_month(m)
print(f"Days in {m}:", d if d is not None else "Unknown month")

print("Months (alphabetical):", sorted(months.keys()))

print("Months with 31 days:", [k for k, v in months.items() if v == 31])

print("Pairs sorted by days:", sorted(months.items(), key=lambda kv: kv[1]))