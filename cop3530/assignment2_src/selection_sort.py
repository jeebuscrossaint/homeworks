# Selection Sort implementation

def selection_sort(arr):
    n = len(arr)
    # Traverse through all array elements
    for i in range(n-1):
        # Find the index of the maximum element in remaining unsorted array
        max_index = i
        for j in range(i+1, n):
            if arr[j] > arr[max_index]:
                max_index = j
        # Swap the found maximum element with the first element
        arr[i], arr[max_index] = arr[max_index], arr[i]

# Input from the user
def get_user_input():
    array_size = int(input("Enter the size of the array: "))
    array = []
    for i in range(array_size):
        value = int(input(f"Enter value {i+1}: "))
        array.append(value)
    return array

# Main execution
if __name__ == "__main__":
    # Get user input
    arr = get_user_input()
    print("Unsorted array:", arr)
    
    # Sort the array
    selection_sort(arr)
    print("Sorted array:", arr)
