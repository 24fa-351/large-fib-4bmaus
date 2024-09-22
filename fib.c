#include <stdio.h>
#include <stdlib.h>

unsigned long long recursive_fib(int position) {
    if (position == 0) return 0;
    if (position == 1 || position == 2) return 1;
    return recursive_fib(position - 1) + recursive_fib(position - 2);
}

unsigned long long iterative_fib(int position) {
    if (position == 0) return 0;
    if (position == 1 || position == 2) return 1;
    unsigned long long previous = 1;
    unsigned long long current = 1;
    unsigned long long next_fib;
    for (int index = 3; index <= position; index++) {
        next_fib = previous + current;
        previous = current;
        current = next_fib;
    }
    return current;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer> <r|i>\n", argv[0]);
        return 1;
    }

    int position = atoi(argv[1]);
    unsigned long long result;

    if (argv[2][0] == 'r') {
        result = recursive_fib(position - 1);
    } else if (argv[2][0] == 'i') {
        result = iterative_fib(position - 1);
    } else {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    printf("%llu\n", result);

    return 0;
}
