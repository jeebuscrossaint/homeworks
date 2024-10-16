def extended_euclidean_algorithm(a, b):
    s, old_s = 0, 1
    t, old_t = 1, 0
    r, old_r = b, a

    while r != 0:
        q = old_r // r
        r, old_r = old_r - q * r, r
        s, old_s = old_s - q * s, s
        t, old_t = old_t - q * t, t

    print(f"GCD = {old_r}")

def main():
    a = int(input("Enter the first integer: "))
    b = int(input("Enter the second integer: "))

    extended_euclidean_algorithm(a, b)

if __name__ == "__main__":
    main()