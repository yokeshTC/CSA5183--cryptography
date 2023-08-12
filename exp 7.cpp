-#include <stdio.h>
#include <math.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int modExp(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main() {
    int p = 6; 
    int q = 5; 
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    
    int e = 17; 
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }
    
    int d = 0;
    while ((d * e) % phi != 1)
        d++;
    
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
    
    int plaintext = 88; 
    int encrypted = modExp(plaintext, e, n);
    printf("Encrypted: %d\n", encrypted);
    
    int decrypted = modExp(encrypted, d, n);
    printf("Decrypted: %d\n", decrypted);
    
    return 0;
}
