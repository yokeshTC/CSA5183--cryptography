#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int h) {
    while (h != 0) {
        int temp = h;
        h = a % h;
        a = temp;
    }
    return a;
}
int main() {
    int p, q, n, phi, e, d;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }
    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            break;
        }
    }
    int msg;
    printf("Enter a message (integer): ");
    scanf("%d", &msg);
    int encrypted_msg = pow(msg, e);
    encrypted_msg = encrypted_msg % n;

    printf("Encrypted message: %d\n", encrypted_msg);
    int decrypted_msg = pow(encrypted_msg, d);
    decrypted_msg = decrypted_msg % n;
    printf("Decrypted message: %d\n", decrypted_msg);
    return 0;
}
