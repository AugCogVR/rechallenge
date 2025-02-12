#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// GROUP A: Input Validation (Cross-linking with Aggregation)
int validate5(int prev) {
    int input;
    printf("Enter value A5: ");
    scanf("%d", &input);
    return (input == (prev % 5) + 2) ? 1 : 0;  
}

int validate4(int prev) {
    int input;
    printf("Enter value A4: ");
    scanf("%d", &input);
    return (input == (prev % 7) + 3) ? validate5(input) : 0;  
}

int validate3(int prev) {
    int input;
    printf("Enter value A3: ");
    scanf("%d", &input);
    return (input == (prev % 4) + 5) ? validate4(input) : 0;  
}

int validate2(int prev) {
    int input;
    printf("Enter value A2: ");
    scanf("%d", &input);
    return (input == (prev % 6) + 4) ? validate3(input) : 0;  
}

int validate1() {
    int input;
    printf("Enter value A1: ");
    scanf("%d", &input);
    return (input == 5) ? validate2(input) : 0;  
}

// GROUP B: Transformation (Now non-linear dependencies)
int transform1(int seed) { return validate1() * (seed % 3) + 2; }  
int transform2(int seed) { return validate2(seed) * 3 + transform1(seed); }  
int transform3(int seed) { return validate3(seed) * 4 + transform2(seed); }  
int transform4(int seed) { return validate4(seed) * 5 + transform3(seed); }  
int transform5(int seed) { return validate5(seed) * 6 + transform4(seed); }  

// GROUP C: Aggregation (Explicit circular dependencies)
int aggregate1(int seed) { return transform1(seed) + transform3(seed); }
int aggregate2(int seed) { return transform2(seed) + aggregate1(seed); }
int aggregate3(int seed) { return transform5(seed) + aggregate2(seed); }
int aggregate4(int seed) { return aggregate3(seed) + transform4(seed); }

int check_success(int seed) { 
    return (aggregate4(seed) % 100 == 42);  // Success condition randomized 
}

int main() {
    srand(time(NULL));
    int seed = rand() % 50;  // Random entry point
    if (check_success(seed)) {
        printf("SUCCESS: System Unlocked!\n");
    } else {
        printf("FAILURE: Access Denied.\n");
    }
    return 0;
}
