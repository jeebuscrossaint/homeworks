# Extended Euclidean Algorithm implementation with user input

def extended_euclidean_algorithm(a, b):
    s, old_s = 0, 1
    t, old_t = 1, 0
    r, old_r = b, a

    while r != 0:
        q = old_r // r
        # Update r and old_r
        old_r, r = r, old_r - q * r
        # Update s and old_s
        old_s, s = s, old_s - q * s
        # Update t and old_t
        old_t, t = t, old_t - q * t
    
    print(f"GCD = {old_r}")
    return old_s, old_t

# Getting input from the user
def get_user_input():
    a = int(input("Enter the first integer: "))
    b = int(input("Enter the second integer: "))
    return a, b

# Main execution
if __name__ == "__main__":
    # Get user input
    a, b = get_user_input()
    
    # Perform Extended Euclidean Algorithm and display results
    extended_euclidean_algorithm(a, b)
