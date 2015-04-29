#include<stdio.h>

int even(int test) {

    if(test % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    printf("Testing if 2 is even.\n");
    if (even(2) == 1) {
            printf("It's even!\n");
    } else {
            printf("Houston, we have a problem.\n");
    }

    return 0;
}

