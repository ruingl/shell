/*
  @author: Rui Reogo
  @license: CC-BY-4.0
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shell(char user[]) {
    // introduction
    printf("Welcome to shell!\n");
    printf("You are logged in as @%s.\n\n", user);

    // variables
    char command[100];
    int args_count;
    char *args[10];

    // shell
    while (1) {
        printf("$ ");

        // setup cmd and args
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        char *cmd = strtok(command, " ");
        args_count = 0;

        while (cmd != NULL) {
            args[args_count++] = cmd;
            cmd = strtok(NULL, "");
        }

        if (args_count == 0) continue;

        if (strcasecmp(args[0], "hi") == 0) {
            printf("Hello, @%s!\n", user);
        } else if (strcasecmp(args[0], "exit") == 0) {
            printf("Exiting...");
            break;
        } else if (strcasecmp(args[0], "help") == 0) {
            const char *message = "Available commands:\n\n"
                                  "  1. exit\n"
                                  "  2. help\n"
                                  "  3. hi\n"
                                  "  4. clear\n"
                                  "  5. echo\n";
            printf("%s", message);
        } else if (strcasecmp(args[0], "clear") == 0) {
            system("clear");
        } else if (strcasecmp(args[0], "echo") == 0) {
            if (args_count < 2) {
                printf("\n");
            } else {
                printf("%s\n", args[1]);
            }
        } else {
            printf(
                "error: command '%s' is not found!\n",
                command
            );
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("error: not enough args!\n");
        printf("usage:\n");
        printf("  %s login <username>", argv[0]);
        return 1;
    }

    // clear screen
    system("clear");

    // variables
    char *type = argv[1];
    char *user = argv[2];

    // $ shell login user
    if (strcasecmp(type, "login") == 0) {
        shell(user);
    } else {
        printf("error: type '%s' is not found!\n", type);
    }

    return 0;
}
