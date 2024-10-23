# Function for Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function for Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Function to display the top five scores
def display_top_five(arr):
    # Sort the array in descending order to display the top scores
    top_five = sorted(arr, reverse=True)[:5]
    print("Top five scores are:", top_five)

# Main program
def main():
    # Input: First year student percentages (floating-point numbers)
    percentages = list(map(float, input("Enter first-year percentages: ").split()))

    # Sorting using Selection Sort
    selection_sorted = percentages.copy()
    selection_sort(selection_sorted)
    print("Percentages sorted using Selection Sort:", selection_sorted)

    # Sorting using Bubble Sort and displaying top five scores
    bubble_sorted = percentages.copy()
    bubble_sort(bubble_sorted)
    print("Percentages sorted using Bubble Sort:", bubble_sorted)
    display_top_five(bubble_sorted)

# Run the main program
main()
