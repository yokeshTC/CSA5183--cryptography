#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define MD5_BLOCK_SIZE 64
#define MD5_DIGEST_SIZE 16
void md5_hash(const uint8_t *message, size_t message_length, uint8_t *hash);
void md5_transform(const uint8_t *block, uint32_t *state);
int main() {
    char input[] = "Hello, MD5!";
    uint8_t hash[MD5_DIGEST_SIZE];

    md5_hash((uint8_t *)input, strlen(input), hash);

    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}

void md5_hash(const uint8_t *message, size_t message_length, uint8_t *hash) {
    uint32_t state[4] = {
        0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
    };

    size_t padded_length = ((message_length + 8) / MD5_BLOCK_SIZE + 1) * MD5_BLOCK_SIZE;
    uint8_t *padded_message = (uint8_t *)malloc(padded_length);
    memcpy(padded_message, message, message_length);
    padded_message[message_length] = 0x80;
    uint64_t bit_length = message_length * 8;
    memcpy(padded_message + padded_length - 8, &bit_length, 8);
    for (size_t i = 0; i < padded_length; i += MD5_BLOCK_SIZE)
    {
        md5_transform(padded_message + i, state);
    }
    for (int i = 0; i < 4; i++) {
        hash[i] = (state[0] >> (i * 8)) & 0xFF;
        hash[i + 4] = (state[1] >> (i * 8)) & 0xFF;
        hash[i + 8] = (state[2] >> (i * 8)) & 0xFF;
        hash[i + 12] = (state[3] >> (i * 8)) & 0xFF;
    }

    free(padded_message);
}

void md5_transform(const uint8_t *block, uint32_t *state) {
	
	
}
