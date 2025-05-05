#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <time.h>

// ------------------ Utility Functions ------------------

void log_event(const char *msg) {
    printf("[LOG] %s\n", msg);
}

void delay_execution(int seconds) {
    log_event("Delaying execution");
    sleep(seconds);
}

void obfuscate_output(char *data) {
    log_event("Obfuscating output");
    for (int i = 0; data[i]; ++i) {
        data[i] ^= 0x5A;  // Simple XOR
    }
}

// ------------------ File I/O Functions ------------------

void read_local_data() {
    log_event("Reading local file");

    int fd = open("/dev/null", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    char buffer[64];
    read(fd, buffer, sizeof(buffer));
    close(fd);
}

void write_local_data() {
    log_event("Writing local file");

    int fd = open("/tmp/fake_output", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    char msg[] = "Dummy data";
    obfuscate_output(msg);
    write(fd, msg, strlen(msg));
    close(fd);
}

// ------------------ Configuration & Setup ------------------

void parse_config_file(const char *path) {
    log_event("Parsing config file");

    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return;
    }

    char line[128];
    while (fgets(line, sizeof(line), fp)) {
        // Simulate config parsing
    }

    fclose(fp);
}

void init_bot_environment() {
    log_event("Initializing bot environment");
    parse_config_file("/etc/fake_bot.conf");
}

// ------------------ Diagnostics ------------------

void check_cpu() {
    log_event("Checking CPU load");
    // Dummy placeholder
}

void check_disk() {
    log_event("Checking disk usage");
    // Dummy placeholder
}

void collect_system_status() {
    log_event("Collecting system status");
    check_cpu();
    check_disk();
}

// ------------------ Authorization ------------------

int authorize_command(const char *cmd) {
    log_event("Authorizing command");

    if (strcmp(cmd, "noop") == 0)
        return 0;  // blocked
    return 1;
}

// ------------------ Simulation ------------------

void simulate_heavy_task() {
    log_event("Simulating heavy task");
    int acc = 0;
    for (int i = 0; i < 100000; ++i) {
        acc += i % 7;
    }
}

// ------------------ Decision Making ------------------

void select_next_action() {
    log_event("Selecting next action");

    int r = rand() % 3;
    switch (r) {
        case 0: read_local_data(); break;
        case 1: write_local_data(); break;
        case 2: collect_system_status(); break;
    }
}

// ------------------ Command Dispatch ------------------

void handle_command(const char *cmd) {
    log_event("Handling command");

    if (!authorize_command(cmd)) {
        log_event("Unauthorized command");
        return;
    }

    if (strcmp(cmd, "read") == 0) {
        read_local_data();
    } else if (strcmp(cmd, "write") == 0) {
        write_local_data();
    } else if (strcmp(cmd, "delay") == 0) {
        delay_execution(1);
        simulate_heavy_task();
    } else if (strcmp(cmd, "compute") == 0) {
        simulate_heavy_task();
    } else {
        log_event("Unknown command");
    }
}

// ------------------ Network Communication ------------------

void authenticate_with_server(int sock) {
    log_event("Authenticating with server");

    write(sock, "AUTH", 4);
    char buffer[8];
    read(sock, buffer, 8);
}

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
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    authenticate_with_server(sock);

    char *commands[] = {"read", "write", "delay", "compute", "noop"};
    for (int i = 0; i < 5; ++i) {
        handle_command(commands[i]);
    }

    close(sock);
}

// ------------------ Shutdown ------------------

void close_logs() {
    log_event("Closing logs");
    // Simulate log closure
}

void clear_temp_files() {
    log_event("Clearing temp files");
    // Simulated file deletion
}

void cleanup_and_exit() {
    log_event("Performing cleanup");
    close_logs();
    clear_temp_files();
}

// ------------------ Main ------------------

int main() {
    srand(time(NULL));
    log_event("Bot started");

    init_bot_environment();
    receive_commands();
    select_next_action();
    cleanup_and_exit();

    log_event("Bot exiting");
    return 0;
}
