#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <openssl/sha.h>

void sha1_hash(const char *input, unsigned char *output) {
    //SHA_CTX sha_context;
   // SHA1_Init(&sha_context);
    //SHA1_Update(&sha_context, input, strlen(input));
    //SHA1_Final(output, &sha_context);
}

int main() {
    char input[] = "Hello, SHA-1!";
    unsigned char hash[SHA_DIGEST_LENGTH];
    
    sha1_hash(input, hash);
    
    printf("Input: %s\n", input);
    printf("SHA-1 Hash: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return 0;
}
