#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 5
#define MAX_SYMBOLS 2

int main() {
    int transitions[MAX_STATES][MAX_SYMBOLS] = {
        {1, 2}, 
        {1, 0}, 
        {1, 2},
        {1, 4}, 
        {1, 2}  
    };

    bool is_final[MAX_STATES] = {false, false, false, false, true};
    char state_names[MAX_STATES] = {'A', 'B', 'C', 'D', 'E'};

    char input[100];
    printf("Enter binary string (e.g., 001011): ");
    if (scanf("%99s", input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int current_state = 0; 

    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i];
        int col;

        if (symbol == '0') {
            col = 0;
        } else if (symbol == '1') {
            col = 1;
        } else {
            printf("Error: Invalid character '%c'. Use only 0 and 1.\n", symbol);
            return 1;
        }

        current_state = transitions[current_state][col];
    }

    printf("Final State Reached: %c\n", state_names[current_state]);
    if (is_final[current_state]) {
        printf("Result: ACCEPTED\n");
    } else {
        printf("Result: REJECTED\n");
    }

    return 0;
}