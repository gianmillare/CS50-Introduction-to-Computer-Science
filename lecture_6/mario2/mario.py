# A more advanced version of mario.py

from cs50 import get_int

def main():
    while True:
        n = get_int("Please input a number between 1 and 8, incusive: ")
        if 1 <= n <= 8:
            break

    for i in range(n):
        print(" " * (n - 1 - i), end="")
        print("#" * (i + 1), end="")
        print(" " * 2, end="")
        print("#" * (i + 1), end="")
        print()

main()