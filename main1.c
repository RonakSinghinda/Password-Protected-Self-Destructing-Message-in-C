
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Use this for Sleep()

#define PASSWORD "findingronak."

void clearScreen() {
    system("cls"); // Windows screen clear
}

void fakeCrashEffect() {
    printf("\nWrong password detected... Initiating memory dump...\n\n");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 60; j++) {
            printf("%c", 33 + rand() % 94);
        }
        printf("\n");
        Sleep(50); // 50 milliseconds
    }
    printf("\nSystem failure. Press any key to exit.\n");
    getchar();
}

void showSecretMessage() {
    clearScreen();
    printf("✅ Access Granted!\n");
    printf("🔐 Secret Message: \"The cake is a lie.\"\n");
    printf("\nThis message will self-destruct in 10 seconds...\n");
    Sleep(10000); // 10 seconds
    clearScreen();
    printf("💥 Message Destroyed.\n");
}

int main() {
    char input[100];

    printf("Enter password to access the secret message: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0'; // Remove newline

    if (strcmp(input, PASSWORD) == 0) {
        showSecretMessage();
    } else {
        fakeCrashEffect();
    }

    return 0;
}
