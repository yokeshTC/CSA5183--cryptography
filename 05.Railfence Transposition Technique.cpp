#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int rails) {
    int len = strlen(plaintext);
    char fence[rails][len];
    
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            fence[i][j] = '.';
        }
    }
    int row = 0, dir = 1;
    for (int i = 0; i < len; i++) {
        fence[row][i] = plaintext[i];
        row += dir;
        if (row == 0 || row == rails - 1) {
            dir = -dir;
        }
    }
    printf("\nEncrypted Text: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (fence[i][j] != '.') {
                printf("%c", fence[i][j]);
            }
        }
    }
    printf("\n");
}
int main() {
    char plaintext[100];
    int rails;
    printf("Enter the plaintext: ");
    gets(plaintext); 
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    railFenceEncrypt(plaintext, rails);
    return 0;
}
