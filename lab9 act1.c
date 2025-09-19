

//3.

#include <stdio.h>
#include <string.h>

int main() {
    char receipt[] = "OrderID: #12345, Date: 2024-01-15";
    char *start, *end;
    char orderID[20]; // buffer to hold extracted ID

    // Find the '#' symbol
    start = strchr(receipt, '#');
    if (start != NULL) {
        start++; // move pointer to the first digit

        // Find the comma after the order ID
        end = strchr(start, ',');

        if (end != NULL) {
            int length = end - start; // number of characters between # and ,
            strncpy(orderID, start, length);
            orderID[length] = '\0'; // null terminate

            printf("Order ID: %s\n", orderID);
        } else {
            printf("Order ID not found properly!\n");
        }
    } else {
        printf("No '#' found in receipt!\n");
    }

    return 0;
}