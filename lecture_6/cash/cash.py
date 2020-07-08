from cs50 import get_float

def main():
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            break

    change = round(change * 100)
    coins_needed = 0
    denominations = [25, 10, 5, 1]


    for i in denominations:
        if i <= change:
            coins_needed += change // i
            change -= (change // i) * i

    print(coins_needed)

main()