# Function to find two largest numbers in a list

def two_largest(arr):
    large_1 = float('-inf')  # Set initial value to negative infinity
    large_2 = float('-inf')
    
    for num in arr:
        if num > large_1:
            large_2 = large_1
            large_1 = num
        elif num > large_2:
            large_2 = num
    
    return large_1, large_2

# Get user input for the list
def get_user_input():
    arr = list(map(int, input("Enter numbers separated by spaces: ").split()))
    return arr

# Main execution
if __name__ == "__main__":
    # Get user input
    arr = get_user_input()
    
    # Find two largest numbers
    large_1, large_2 = two_largest(arr)
    
    # Output the result
    print(f"The two largest numbers are: {large_1} and {large_2}")
