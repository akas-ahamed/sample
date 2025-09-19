#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    char *hash_ptr = strchr(input, '#');
    if (hash_ptr == NULL) {
        printf("Order ID not found\n");
        return 1;
    }

    char *comma_ptr = strchr(hash_ptr, ',');
    if (comma_ptr == NULL) {
        printf("Order ID not found\n");
        return 1;
    }

    int id_length = comma_ptr - hash_ptr - 1;

    if (id_length <= 0 || id_length >= 20) {  
        printf("Invalid Order ID length\n");
        return 1;
    }

    char order_id[20];
    strncpy(order_id, hash_ptr + 1, id_length);
    order_id[id_length] = '\0';

    printf("Order ID: %s\n", order_id);
    return 0;
}