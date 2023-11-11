import cs50


def main():
    # Assign the range of input
    while True:
        n = cs50.get_int("Height: ")
        if n >= 1 and n <= 8:
            break

# print("#" if i + j >= n - 1 else " ", end="")
    # Create each row and hash
    for i in range(n):
        # First pyramid
        for j in range(n):
            if i + j >= n - 1:
                print("#", end="")
            else:
                print(" ", end="")
        # The gap between two pyramid
        for k in range(n - 2, n, 1):
            if k < n:
                print(" ", end="")
        # Second pyramid
        for l in range(n):
            if l <= i:
                print("#", end="")
        print()


main()

