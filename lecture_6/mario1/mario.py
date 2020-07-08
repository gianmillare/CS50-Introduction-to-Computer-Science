from cs50 import get_int

def main():
    # Infinite loop until we get an input between 1 and 8
    while True:
        n = get_int("Please insert an integer between 1 and 8: ")
        if 1 <= n <= 8:
            break

    # For loop to start creating spaces and hashes
    for i in range(n): # --> Rows
        for j in range(n): # --> Columns
            if i + j >= n - 1:
                print("#", end="")
            else:
                print(" ", end="")
        print()

# Call the Function
main()