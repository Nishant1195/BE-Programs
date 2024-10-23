# Function for Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

# Function to display the top five scores
def display_top_five(arr):
    # Sort the array in descending order to display the top scores
    top_five = sorted(arr, reverse=True)[:5]
    print("Top five scores are:", top_five)

# Main program
def main():
    # Input: First year student percentages (floating-point numbers)
    percentages = list(map(float, input("Enter first-year percentages: ").split()))

    # Sorting using Quick Sort
    quick_sorted = quick_sort(percentages)
    print("Percentages sorted using Quick Sort:", quick_sorted)

    # Display the top five scores
    display_top_five(quick_sorted)

# Run the main program
main()
