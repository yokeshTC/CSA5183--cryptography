#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereCipher(char* text, char* key, int encrypt) {
    int textLength = strlen(text);
    int keyLength = strlen(key);

    for (int i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            int textOffset = isupper(text[i]) ? 'A' : 'a';
            int keyOffset = isupper(key[i % keyLength]) ? 'A' : 'a';
            int shift = key[i % keyLength] - keyOffset;

            if (encrypt) {
                text[i] = (text[i] - textOffset + shift) % 26 + textOffset;
            } else {
                text[i] = (text[i] - textOffset - shift + 26) % 26 + textOffset;
            }
        }
    }
}
int main() {
    char text[1000];
    char key[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter the key: ");
    scanf("%s", key);
    vigenereCipher(text, key, 1); 
    printf("Encrypted text: %s\n", text);
    vigenereCipher(text, key, 0);
    printf("Decrypted text: %s\n", text);
    return 0;
}
