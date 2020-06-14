#include <stdio.h>
#include <cs50.h>

// Declare all functions
bool is_valid(long long credit_card_number);
int find_length(long long n);
bool checksum(long long credit_card_number);
void credit_card_brand(long long credit_card_number);


int main(void)
{
    // Step 1: Prompt for input
    long long credit_card_number;
    do
    {
        credit_card_number = get_long_long("Please input your credit card number: ");

    } while (credit_card_number < 0);

    // Step 2: Calculate the check sum and check if credit card number is valid
    if (is_valid(credit_card_number) == true)
        credit_card_brand(credit_card_number);
    else
        printf("INVALID\n");
}

// Function to check validity
bool is_valid(long long credit_card_number)
{
    int len = find_length(credit_card_number);
    return (len == 13 || len == 15 || len == 16) && checksum(credit_card_number);
}

// Function to find length
int find_length(long long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}

// Function to run Luhn's Algorithm
bool checksum(long long credit_card_number)
{
    int sum = 0;
    for (int i = 0; credit_card_number != 0; i++, credit_card_number /= 10)
    {
        if (i % 2 == 0)
            sum += credit_card_number % 10;
        else
        {
            int digit = 2 * (credit_card_number % 10);
            sum += digit / 10 + digit % 10;
        }

    }
    return (sum % 10) == 0;
}

// Function to print credit card brand
void credit_card_brand(long long credit_card_number)
{
    if ((credit_card_number >= 34e13 && credit_card_number < 35e13) || (credit_card_number >= 37e13 && credit_card_number < 38e13))
        printf("AMEX\n");
    else if (credit_card_number >= 51e14 && credit_card_number < 56e14)
        printf("MASTERCARD\n");
    else if ((credit_card_number >= 4e12 && credit_card_number < 5e12) || (credit_card_number >= 4e15 && credit_card_number < 5e15))
        printf("VISA\n");
    else
        printf("INVALID\n");
}