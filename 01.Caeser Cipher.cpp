#include <stdio.h>
#include <string.h>
void encryptCaesar(char message[], int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
    }
}
int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);
    if (key < 0 || key > 25) {
        printf("Invalid key. Please enter a key between 0 and 25.\n");
        return 1;
    }
    message[strcspn(message, "\n")] = '\0';

    encryptCaesar(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
