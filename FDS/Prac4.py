# Function for Linear Search
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

# Function for Sentinel Search
def sentinel_search(arr, x):
    n = len(arr)
    last = arr[n - 1]
    arr[n - 1] = x
    i = 0
    while arr[i] != x:
        i += 1
    arr[n - 1] = last
    if i < n - 1 or arr[n - 1] == x:
        return i
    return -1

# Function for Binary Search (array must be sorted)
def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1

# Function for Fibonacci Search (array must be sorted)
def fibonacci_search(arr, x):
    n = len(arr)
    fib2 = 0  # (m-2)'th Fibonacci number
    fib1 = 1  # (m-1)'th Fibonacci number
    fib = fib2 + fib1  # m'th Fibonacci number

    while (fib < n):
        fib2 = fib1
        fib1 = fib
        fib = fib2 + fib1

    offset = -1

    while (fib > 1):
        i = min(offset + fib2, n-1)

        if (arr[i] < x):
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif (arr[i] > x):
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i

    if(fib1 and arr[offset+1] == x):
        return offset+1

    return -1

# Menu for selecting search options
def menu():
    while True:
        print("\n--- Search Menu ---")
        print("1. Linear Search")
        print("2. Sentinel Search")
        print("3. Binary Search (Sorted Array Required)")
        print("4. Fibonacci Search (Sorted Array Required)")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1 or choice == 2:
            # Random Order (for Linear and Sentinel Search)
            arr = list(map(int, input("Enter roll numbers (random order): ").split()))
            x = int(input("Enter roll number to search: "))

            if choice == 1:
                result = linear_search(arr, x)
            else:
                result = sentinel_search(arr, x)

        elif choice == 3 or choice == 4:
            # Sorted Order (for Binary and Fibonacci Search)
            arr = list(map(int, input("Enter roll numbers (sorted order): ").split()))
            x = int(input("Enter roll number to search: "))

            if choice == 3:
                result = binary_search(arr, x)
            else:
                result = fibonacci_search(arr, x)

        elif choice == 5:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice! Try again.")
            continue

        if result != -1:
            print(f"Roll number {x} found at index {result}")
        else:
            print(f"Roll number {x} not found.")

# Run the menu
menu()
