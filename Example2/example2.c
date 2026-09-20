#include <stdio.h>

int main() {
    char input[100];
    int ones = 0;

    printf("Enter a binary string: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {

        if (input[i] == '1') {
            ones++;
        }
        else if (input[i] != '0') {
            printf("Invalid input!\n");
            return 0;
        }
    }

    if (ones == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}