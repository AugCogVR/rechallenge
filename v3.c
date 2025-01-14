#include <stdio.h>

// Enter integer 1: 5
// Enter integer 2: 7
// Enter integer 3: 2
// Enter integer 4: 9
// Enter integer 5: 3

int part1a() 
{
    int input;
    printf("Enter integer 1: ");
    scanf("%d", &input);
    return (input == 5) ? input : 0;
}

int part1b() 
{
    return (part1a() * 2);
}

int part1c() 
{
    return (part1b() - 4);
}

int part1d() 
{
    return (part1c() + 3);
}

int part2a() 
{
    int input;
    printf("Enter integer 2: ");
    scanf("%d", &input);
    return (input == 7) ? input : 0;
}

int part2b() 
{
    return (part2a() * 3);
}

int part2c() 
{
    return (part2b() - 2);
}

int part2d() 
{
    return (part2c() + 4);
}

int part3a() 
{
    int input;
    printf("Enter integer 3: ");
    scanf("%d", &input);
    return (input == 2) ? input : 0;
}

int part3b() 
{
    return (part3a() * 5);
}

int part3c() 
{
    return (part3b() - 6);
}

int part3d() 
{
    return (part3c() + 2);
}

int part4a() 
{
    int input;
    printf("Enter integer 4: ");
    scanf("%d", &input);
    return (input == 9) ? input : 0;
}

int part4b() 
{
    return (part4a() * 2);
}

int part4c() 
{
    return (part4b() - 1);
}

int part4d() 
{
    return (part4c() + 3);
}

int part4e() 
{
    return (part4d() * 2);
}

int part5a() 
{
    int input;
    printf("Enter integer 5: ");
    scanf("%d", &input);
    return (input == 3) ? input : 0;
}

int part5b() 
{
    return (part5a() * 3);
}

int part5c() 
{
    return (part5b() + 2);
}


int main() 
{
    // Perform multiple checks
    int result1 = part1d();
    int result2 = part2d();
    int result3 = part3d();
    int result4 = part4e();
    int result5 = part5c();

    int result = result1 + result2 + result3 + result4 + result5;
    // printf("RESULT %d\n", result);
    
    if (result == 89) printf("SUCCESS\n");
    else printf("FAILURE\n");

    return 0;
}
