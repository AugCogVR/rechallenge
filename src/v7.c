#include <stdio.h>

// ----- Part 1 Chain -----
int part1a() 
{
    int input;
    printf("Enter integer 1: ");
    scanf("%d", &input);
    return (input == 5) ? input : 0;
}

int part1b() 
{
    int a = part1a();
    return a * 2;  // 5 -> 10
}

int part1c() 
{
    int a = part1a();
    int b = part1b();
    // Now depend on both part1a and part1b.
    // With a = 5 and b = 10, we want part1c to yield 4.
    return (b - a - 1); // 10 - 5 - 1 = 4
}

int part1d() 
{
    int a = part1a();
    int b = part1b();
    int c = part1c();
    // Combine earlier results so that 10 + 4 + ? gives 9.
    // We'll use: (b - c + 3) so: 10 - 4 + 3 = 9.
    return (b - c + 3);
}

// ----- Part 2 Chain -----
int part2a() 
{
    int input;
    printf("Enter integer 2: ");
    scanf("%d", &input);
    return (input == 7) ? input : 0;
}

int part2b() 
{
    int a = part2a();
    return a * 3;  // 7 -> 21
}

int part2c() 
{
    int a = part2a();
    int b = part2b();
    // With a = 7 and b = 21, we want part2c to yield 14.
    return (b - a); // 21 - 7 = 14
}

int part2d() 
{
    int a = part2a();
    int c = part2c();
    // Combine a and c so that 14 + 7 + 2 = 23.
    return (c + a + 2);
}

// ----- Part 3 Chain -----
int part3a() 
{
    int input;
    printf("Enter integer 3: ");
    scanf("%d", &input);
    return (input == 2) ? input : 0;
}

int part3b() 
{
    int a = part3a();
    return a * 5;  // 2 -> 10
}

int part3c() 
{
    int a = part3a();
    int b = part3b();
    // With a = 2 and b = 10, choose operations so that:
    // part3c = 10 - 2 - 4 = 4.
    return (b - a - 4);
}

int part3d() 
{
    int b = part3b();
    int c = part3c();
    // With b = 10 and c = 4, compute: 10 - 4 = 6.
    return (b - c);
}

// ----- Part 4 Chain -----
int part4a() 
{
    int input;
    printf("Enter integer 4: ");
    scanf("%d", &input);
    return (input == 9) ? input : 0;
}

int part4b() 
{
    int a = part4a();
    return a * 2;  // 9 -> 18
}

int part4c() 
{
    int a = part4a();
    int b = part4b();
    // With a = 9 and b = 18, choose:
    // part4c = 18 + 9 - 10 = 17.
    return (b + a - 10);
}

int part4d() 
{
    int c = part4c();
    int d3 = part3d();
    // 17 + 6 - 3 = 20
    return (c + d3 - 3);
}

int part4e() 
{
    int d = part4d();
    int a = part4a();
    // Use both d and a so that: (20*2) + 9 - 9 = 40.
    return (d * 2) + a - 9;
}

// ----- Part 5 Chain -----
int part5a() 
{
    int input;
    printf("Enter integer 5: ");
    scanf("%d", &input);
    return (input == 3) ? input : 0;
}

int part5b() 
{
    int a = part5a();
    return a * 3;  // 3 -> 9
}

int part5c() 
{
    int a = part5a();
    int b = part5b();
    // With a = 3 and b = 9, combine them to get 11.
    return (b + a - 1);  // 9 + 3 - 1 = 11
}

int main() 
{
    if ((part1d() + part3d() + part5c()) == ((part2d() + part4e()) / 3 + 5))
        printf("SUCCESS\n");
    else
        printf("FAILURE\n");

    return 0;
}

