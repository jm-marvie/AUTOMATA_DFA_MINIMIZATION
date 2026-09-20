#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;   // 0 =, 1 = XZ

    printf("Enter a binary string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {

        if (state == 0) {        // WY
            if (input[i] == '0')
                state = 1;     
            else if (input[i] == '1')
                state = 0;    
            else {
                printf("Invalid input!\n");
                return 0;
            }
        }

        else if (state == 1) {   // XZ
            if (input[i] == '0')
                state = 0;     
            else if (input[i] == '1')
                state = 1;    
            else {
                printf("Invalid input!\n");
                return 0;
            }
        }
    }

    if (state == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}