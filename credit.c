#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// calculates the number of digits in the card number
int getCardDigits(long long card_num)
{
    int card_digits = (int)log10(card_num) + 1;
    return card_digits;
}

int main(void)
{
    // get card number from user
    long long int card_num;
    printf("Number: ");
    scanf("%lld",&card_num);

    // use digits function
    int card_digits = getCardDigits(card_num);

    // if not a valid credit card length print invalid immediately
    if (card_digits != 13 && card_digits != 15 && card_digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }


    // storing the individual digits in an array
    int numberArray[card_digits];
    long long count = card_num;
    int i = 0;

    while (count != 0)
    {
        numberArray[card_digits - 1 - i] = count % 10;
        count = count/10;
        i++;
    }
      // Every other number starting from the second to last in array
    int numberArray2[card_digits/2];
    int k = 2;
    int l = 0;

    while ((card_digits - k) > -1)
    {
        numberArray2[l] = 2 * numberArray[card_digits - k];
        k = k + 2;
        l++;
    }

    int digit_times_two = 0;

    for (int j = 0; j < card_digits/2; j++)
    {
        if (numberArray2[j] > 9)
        {
            int split_digit = 0;
            digit_times_two = digit_times_two + (numberArray2[j] % 10);
            split_digit = numberArray2[j]/10;
            digit_times_two = digit_times_two + split_digit;
        }
        else
        {
            digit_times_two = digit_times_two + numberArray2[j];
        }
    }

    // the remainging digits added together after put in 3rd array
    int numberArray3[card_digits - (card_digits/2)];
    int m = 1;
    int n = 0;

    while ((card_digits - m) > -1)
    {
        numberArray3[n] = numberArray[card_digits - m];
        m = m + 2;
        n++;
    }


    int other_digit_count = 0;

    for (int j = 0; j < (card_digits - (card_digits/2)); j++)
    {
        other_digit_count = other_digit_count + numberArray3[j];
    }

    int companyId;
    int companyId2;


    // validating Luhn algorithm
    if ((digit_times_two + other_digit_count) % 10 == 0)
    {
        companyId = numberArray[0];
        companyId2 = numberArray[1];
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    // checking which card company
    if (card_digits == 15 && companyId == 3 && (companyId2 == 4 || companyId2 == 7))
    {
        printf("AMEX\n");
    }
    else if (card_digits == 16 && companyId == 5 && (companyId2 >= 1 && companyId2 <= 5))
    {
        printf("MASTERCARD\n");
    }
    else if ((card_digits == 13 || card_digits == 16) && companyId == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
