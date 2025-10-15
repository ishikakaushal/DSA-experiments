//Check if a number is positive , negative or zero

#include <stdio.h>

int main() {
    float number;

    printf("Enter a number: ");
    scanf("%f", &number);

    if (number > 0)
        printf("The number is positive.\n");
    else if (number < 0)
        printf("The number is negative.\n");
    else
        printf("The number is zero.\n");

    return 0;
}


//Find the largest of three numbers
#include <stdio.h>

int main() {
    float num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
        printf("The largest number is: %.2f\n", num1);
    else if (num2 >= num1 && num2 >= num3)
        printf("The largest number is: %.2f\n", num2);
    else
        printf("The largest number is: %.2f\n", num3);

    return 0;
}


//Check if a year is a leap year

#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);

    return 0;
}
