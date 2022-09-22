#include "BIGNUM.h"

int main(int argc, char** argv) {
    int i;
    BigNum b;

    if (argc <= 1) {
        fprintf(stderr, "Usage: BIGNUM [n]\n");
        return 1;
    }

    if (bignum_init(argv[1], &b)) {
        fprintf(stderr, "%s must be valid integer\n", argv[1]);
        return 1;
    }

    printf("Big num:\n");
    printf("=> Digits: %d\n", b.n_digits);
    printf("=> Sign: %d\n", b.sign);

    printf("=> Number: ");

    if (b.sign == -1) {
        printf("-");
    }

    for (i = b.n_digits - 1; i >= 0; i--) {
        printf("%d", b.digits[i]);
    }

    printf("\n");

    bignum_free(&b);

    return 0;
}
