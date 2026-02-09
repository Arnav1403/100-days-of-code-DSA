#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;

    printf("Enter the code name: ");
    scanf("%s", str);

    // Print string in reverse
    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
