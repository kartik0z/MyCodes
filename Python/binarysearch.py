def binary_search(arr, left, right, key):
    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == key:
            return mid
        if arr[mid] < key:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def main():
    size = int(input("Enter the number of elements in the array: "))

    arr = []
    print(f"Enter {size} sorted elements:")
    for i in range(size):
        arr.append(int(input()))

    key = int(input("Enter the element to search for: "))

    # Perform binary search
    result = binary_search(arr, 0, size - 1, key)
    if result == -1:
        print("Element is not present in the array")
    else:
        print(f"Element is present at index {result}")


if __name__ == "__main__":
    main()