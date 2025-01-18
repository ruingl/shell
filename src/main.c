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

    // shell
    while (1) {
        printf("$ ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcasecmp(command, "hi") == 0) {
            printf("Hello, @%s!\n", user);
        } else if (strcasecmp(command, "exit") == 0) {
            printf("Exiting...");
            break;
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
