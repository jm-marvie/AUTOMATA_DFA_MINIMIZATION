#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;   // 0 = WY, 1 = X, 2 = Z

    printf("Enter a binary string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {

        if (state == 0) {          // WY
            if (input[i] == '0')
                state = 0;
            else if (input[i] == '1')
                state = 1;
            else {
                printf("Invalid input!\n");
                return 0;
            }
        }

        else if (state == 1) {     // X
            if (input[i] == '0')
                state = 0;
            else if (input[i] == '1')
                state = 2;
            else {
                printf("Invalid input!\n");
                return 0;
            }
        }

        else {                     // Z
            if (input[i] == '0')
                state = 0;
            else if (input[i] == '1')
                state = 2;
        }
    }

    if (state == 2)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}