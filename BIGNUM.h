#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isNumber(char* str) {
    int i, start, digit;
    int n_digits = strlen(str);

    if (n_digits <= 0) {
        return 0;
    }

    start = 0;
    if (str[0] == '-') {
        start = 1;
        if (n_digits == 1) {
            return 0;
        }
    }

    for (i = start; i < n_digits; i++) {
        digit = str[i] - '0';
        if (digit < 0 || digit > 9) {
            return 0;
        }
    }

    return 1;
}

typedef struct BigNum {
    int sign;
    int* digits;
    unsigned int n_digits;
} BigNum;

int bignum_init(char* str, BigNum* bigNum) {
    int j, i, start, n_digits;

    if (!isNumber(str)) {
        return 1;
    }

    start = str[0] == '-' ? 1 : 0;

    bigNum->sign = start ? -1 : 1;
    bigNum->n_digits = n_digits = start ? strlen(str) - 1 : strlen(str);
    bigNum->digits = (int*) malloc(sizeof(int) * n_digits);

    if (bigNum->digits == NULL) {
        return 1;
    }

    j = 0;
    for (i = strlen(str) - 1; i >= start; i--) {
        bigNum->digits[j++] = str[i] - '0';
    }

    return 0;
}

int bignum_add(BigNum* a, BigNum* b, BigNum* c) {
}

int bignum_sub(BigNum* a, BigNum* b, BigNum* c) {
}

int bignum_mul(BigNum* a, BigNum* b, BigNum* c) {
}

int bignum_div(BigNum* a, BigNum* b, BigNum* c) {
}

int bignum_free(BigNum* bigNum) {
    free(bigNum->digits);
    return 0;
}
