#include <stdio.h>
#include <stdlib.h>

void log_message(const char *msg) {
    printf("[LOG]: %s\n", msg);
}

void task_add(int a, int b) {
    log_message("Executing task_add");
    printf("Result: %d\n", a + b);
}

void task_multiply(int a, int b) {
    log_message("Executing task_multiply");
    printf("Result: %d\n", a * b);
}

void run_task(void (*task)(int, int), int x, int y) {
    log_message("Running task via function pointer");
    task(x, y);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s add|mul\n", argv[0]);
        return 1;
    }

    void (*selected_task)(int, int);

    if (argv[1][0] == 'a') {
        selected_task = task_add;
    } else {
        selected_task = task_multiply;
    }

    run_task(selected_task, 5, 3);

    return 0;
}

