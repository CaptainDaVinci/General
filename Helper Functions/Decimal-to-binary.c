/*
 *  Possibly Over-engineered.
 *
 *      :P
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PRECISION 10

void convertFloatPart(char binary[], float num);
void convertIntPart(char binary[], int binaryNum);
void reverse(char binary[]);

int i;

int main(void)
{
    float num;
    char *binary = calloc(1000, sizeof(int));
    int i;

    printf("Enter the number: ");
    scanf("%f", &num);

    convertIntPart(binary, (int)num);
    convertFloatPart(binary, num);

    printf("Binary: %s\n", binary);
    free(binary);
}

void convertFloatPart(char binary[], float num)
{
    bool padded = false;
    int digits = 0;
    int padding;
    int intPart = num;
    float floatPart = num - (float)intPart;

    while(floatPart != 0.0f && digits < PRECISION)
    {
        floatPart *= 2;
        intPart = floatPart;
        binary[i++] = intPart + '0';
        digits++;

        if(digits % 4 == 0)
            binary[i++] = ' ';

        floatPart -= intPart;
    }

    for(padding = 4 - digits % 4; padding >  0 && padding < 4; padding--)
    {
        padded = true;
        binary[i++] = '0';
    }

    if(padded)
        binary[i++] = ' ';

    binary[i] = '\0';
    strcat(binary, "0000");
}


void convertIntPart(char binary[], int n)
{
    bool padded = false;
    int padding;
    int rem;
    int digits = 0;

    while(n != 0)
    {
        rem = n % 2;
        n /= 2;
        binary[i++] = rem + '0';
        digits++;

        if(digits % 4 == 0)
            binary[i++] = ' ';
    }

    for(padding = 4 - digits % 4; padding >  0 && padding < 4; padding--)
    {
        padded = true;
        binary[i++] = '0';
    }

    if(padded)
        binary[i++] = ' ';

    strcat(binary, "0000.");
    i += 5;

    reverse(binary);
}

void reverse(char binary[])
{
    int j = 0;
    int k = 0;
    char temp;

    for(j = 0, k = i - 2; j < k; j++, k--)
    {
        temp = binary[j];
        binary[j] = binary[k];
        binary[k] = temp;
    }
}
