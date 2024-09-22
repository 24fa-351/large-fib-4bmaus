#include <stdio.h>
#include <stdlib.h>

unsigned long long fibonacci_iterative(int position) {
    if (position == 1) {
        return 0;
    } else if (position == 2) {
        return 1;
    }
    
    unsigned long long first = 0;
    unsigned long long second = 1;
    unsigned long long next;
    for (int current_position = 3; current_position <= position; current_position++) {
        next = first + second;
        first = second;
        second = next;
    }
    return second;
}

unsigned long long fibonacci_recursive(int position) {
    if (position == 1) {
        return 0;
    } else if (position == 2) {
        return 1;
    }
    return fibonacci_recursive(position - 1) + fibonacci_recursive(position - 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <integer> <method (r/i)> <filename>\n", argv[0]);
        return 1;
    }

    int command_line_input = atoi(argv[1]);

    char calculation_method = argv[2][0];

    FILE *input_file = fopen(argv[3], "r");
    if (!input_file) {
        printf("Error: could not open file %s\n", argv[3]);
        return 1;
    }

    int file_input;
    fscanf(input_file, "%d", &file_input);
    fclose(input_file);

    int target_position = command_line_input + file_input;

    unsigned long long fibonacci_result;
    if (calculation_method == 'i') {
        fibonacci_result = fibonacci_iterative(target_position);
    } else if (calculation_method == 'r') {
        fibonacci_result = fibonacci_recursive(target_position);
    } else {
        printf("Invalid method specified. Use 'i' for iterative or 'r' for recursive.\n");
        return 1;
    }


    printf("%llu\n", fibonacci_result);

    return 0;
}
