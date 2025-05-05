#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

// Cross-cutting logging utility
void log_event(const char *msg) {
    printf("[LOG] %s\n", msg);
}

// Simulated data read from file
void read_local_data() {
    log_event("Reading local file");

    int fd = open("/dev/null", O_RDONLY);  // Dummy file
    if (fd < 0) {
        perror("open");
        return;
    }

    char buffer[64];
    read(fd, buffer, sizeof(buffer));
    close(fd);
}

// Simulated file write
void write_local_data() {
    log_event("Writing local file");

    int fd = open("/tmp/fake_output", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    const char *msg = "Dummy data";
    write(fd, msg, strlen(msg));
    close(fd);
}

// Simulated command handler
void handle_command(const char *cmd) {
    log_event("Handling command");

    if (strcmp(cmd, "read") == 0) {
        read_local_data();
    } else if (strcmp(cmd, "write") == 0) {
        write_local_data();
    } else {
        log_event("Unknown command");
    }
}

// Simulated socket receiver
void receive_commands() {
    log_event("Opening socket");

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(9999),
        .sin_addr.s_addr = inet_addr("127.0.0.1")  // Dummy address
    };

    // Simulate connection attempt
    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Simulate receiving commands
    char *commands[] = {"read", "write", "noop"};
    for (int i = 0; i < 3; ++i) {
        handle_command(commands[i]);
    }

    close(sock);
}

int main() {
    log_event("Bot started");
    receive_commands();
    log_event("Bot exiting");
    return 0;
}

