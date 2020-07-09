from cs50 import get_int

def main():
    while True:
        cc_number = get_int("Please input a credit card number: ")
        if cc_number > 0:
            break

    if is_valid(cc_number):
        card_brand(cc_number)
    else:
        print("INVALID")

# Check that the credit card number is inputted correctly
def is_valid(cc_number):
    return (len(str(cc_number)) == 13 or len(str(cc_number)) == 15 or len(str(cc_number)) == 16) and check_sum(cc_number)

def check_sum(cc_number):
    sum = 0
    for i in range(len(str(cc_number))):
        if i % 2 == 0:
            sum += cc_number % 10
        else:
            digit = 2 * (cc_number % 10)
            sum += digit // 10 + digit % 10

        cc_number //= 10
    return sum % 10 == 0

# Print out the card brand using criteria supplied
def card_brand(cc_number):
    if (cc_number >= 34e13 and cc_number < 35e13) or (cc_number >= 37e13 and cc_number < 38e13):
        print("AMEX")
    elif (cc_number >= 51e14 and cc_number < 56e14):
        print("MASTERCARD")
    elif (cc_number >= 4e12 and cc_number < 5e12) or (cc_number >= 4e15 and cc_number < 5e15):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()