#include <stdio.h>

// Enter integer: 5
// Enter integer: 9
// Enter integer: 8
// Enter integer: 9
// Enter integer: 8
// Enter integer: 8
// Enter integer: 9
// Enter integer: 8
// SUCCESS

int part1() 
{
    int input;
    const int valid = 5;

    printf("Enter integer: ");
    scanf("%d", &input);

    // Return the input if valid, otherwise return 0
    return (input == valid) ? input : 0;
}

int part2() 
{
    int input;
    const int valid = 9;

    printf("Enter integer: ");
    scanf("%d", &input);

    // Return the input if valid, otherwise return 0
    return (input == valid) ? input : 0;
}

int part3() 
{
    int input;
    const int valid = 8;

    printf("Enter integer: ");
    scanf("%d", &input);

    // Return the input if valid, otherwise return 0
    return (input == valid) ? input : 0;
}

int part4() 
{
    int a = part2();
    int b = part3();

    if (a != 0 && b != 0) {
        int calculation = a + b;
        return (calculation < 30) ? calculation : 0;
    }
    return 0;
}

int part5() 
{
    int a = part3();
    int b = part4();

    if (a != 0 && b != 0) {
        int calculation = a + b;
        return (calculation < 30) ? calculation : 0;
    }
    return 0;
}

int main() 
{
    // Perform multiple checks
    int result1 = part1();
    int result2 = part2();
    int result3 = part3();
    int result4 = part4();
    int result5 = part5();

    // Combine the results of all checks
    if (result1 != 0 && result2 != 0 && result3 != 0 && result4 != 0 && result5 != 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAILURE\n");
    }

    return 0;
}
