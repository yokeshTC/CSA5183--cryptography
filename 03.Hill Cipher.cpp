#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10
int keyMatrix[MAX_SIZE][MAX_SIZE];
int messageVector[MAX_SIZE];
int encryptedVector[MAX_SIZE];
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}
void encrypt(int keySize, int messageSize) {
    for (int i = 0; i < keySize; i++) {
        encryptedVector[i] = 0;
        for (int j = 0; j < keySize; j++) {
            encryptedVector[i] += keyMatrix[i][j] * messageVector[j];
        }
        encryptedVector[i] %= 26;
    }
}
int main() {
    int keySize, messageSize;
    printf("Enter the size of the key matrix: ");
    scanf("%d", &keySize);
    printf("Enter the key matrix (row by row):\n");
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }
    printf("Enter the size of the message vector (should be %d): ", keySize);
    scanf("%d", &messageSize);
    if (messageSize != keySize) {
        printf("Invalid message size. It should be equal to the key size.\n");
        return 1;
    }

    printf("Enter the message vector (integers in the range [0, 25]):\n");
    for (int i = 0; i < messageSize; i++) {
        scanf("%d", &messageVector[i]);
        messageVector[i] %= 26;
    }
    encrypt(keySize, messageSize);
    printf("Encrypted vector: ");
    for (int i = 0; i < keySize; i++) {
        printf("%c", encryptedVector[i] + 'A');
    }
    printf("\n");
    return 0;
}
