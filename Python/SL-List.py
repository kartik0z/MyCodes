nums = input("Enter numbers separated by space: ").strip().split()
nums = [float(x) for x in nums]  # floats allowed
if not nums:
    print("Empty list")
else:
    print("Smallest:", min(nums))
    print("Largest:", max(nums))