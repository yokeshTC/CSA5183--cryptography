#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareKey(char *key, char keySquare[SIZE][SIZE]) 
{
    int i, j, k = 0;
    int exists[26] = {0};
    for (i = 0; i < strlen(key); i++) {
        if (key[i] == 'J')
            key[i] = 'I'; 
        if (!exists[key[i] - 'A']) {
            keySquare[k / SIZE][k % SIZE] = key[i];
            exists[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i != ('J' - 'A') && !exists[i]) {
            keySquare[k / SIZE][k % SIZE] = i + 'A';
            k++;
        }
    }
}
void findPosition(char keySquare[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I'; 
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (keySquare[*row][*col] == ch)
                return;
        }
    }
}
void playfairEncrypt(char keySquare[SIZE][SIZE], char *message) {
    int i, len = strlen(message);
    for (i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(keySquare, message[i], &row1, &col1);
        findPosition(keySquare, message[i + 1], &row2, &col2);
        if (row1 == row2) {
            printf("%c%c", keySquare[row1][(col1 + 1) % SIZE], keySquare[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2) {
            printf("%c%c", keySquare[(row1 + 1) % SIZE][col1], keySquare[(row2 + 1) % SIZE][col2]);
        } else {
            printf("%c%c", keySquare[row1][col2], keySquare[row2][col1]);
        }
    }
}
int main() {
    char key[26];
    char keySquare[SIZE][SIZE];
    char message[100];
    printf("Enter the key (uppercase letters only): ");
    scanf("%s", key);
    printf("Enter the message to encrypt (uppercase letters only, no spaces): ");
    scanf("%s", message);
    prepareKey(key, keySquare);
    printf("Key Square:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", keySquare[i][j]);
        }
        printf("\n");
    }
    printf("Encrypted Message: ");
    playfairEncrypt(keySquare, message);
    printf("\n");
    return 0;
}
