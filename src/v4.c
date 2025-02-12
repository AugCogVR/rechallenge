#include <stdio.h>

// GROUP A: Input Validation (Fully connected internally)
int validate5() {
    int input;
    printf("Enter value A5: ");
    scanf("%d", &input);
    return (input == 3) ? 1 : 0;  // Ends clique chain
}

int validate4() {
    int input;
    printf("Enter value A4: ");
    scanf("%d", &input);
    if (input != 9) return 0;
    return validate5();  // Calls next function in the clique
}

int validate3() {
    int input;
    printf("Enter value A3: ");
    scanf("%d", &input);
    if (input != 2) return 0;
    return validate4();  // Calls next function in the clique
}

int validate2() {
    int input;
    printf("Enter value A2: ");
    scanf("%d", &input);
    if (input != 7) return 0;
    return validate3();  // Calls next function in the clique
}

int validate1() {
    int input;
    printf("Enter value A1: ");
    scanf("%d", &input);
    if (input != 5) return 0;
    return validate2();  // Calls next function in the clique
}

// GROUP B: Transformation Functions (Now forming an explicit clique)
int transform1() { return validate1() * 2; }  
int transform2() { return validate2() * 3 + transform1(); }  
int transform3() { return validate3() * 4 + transform2(); }  
int transform4() { return validate4() * 5 + transform3(); }  
int transform5() { return validate5() * 6 + transform4(); }  

// GROUP C: Aggregation Functions (Explicit clique with bridges)
int aggregate1() { return transform1() + transform2(); }
int aggregate2() { return transform3() + transform4(); }
int aggregate3() { return transform5() + aggregate1(); }
int aggregate4() { return aggregate2() + aggregate3(); }
int check_success() { return (aggregate4() == 50); }  

int main() {
    if (check_success()) {
        printf("SUCCESS: System Unlocked!\n");
    } else {
        printf("FAILURE: Access Denied.\n");
    }
    return 0;
}
