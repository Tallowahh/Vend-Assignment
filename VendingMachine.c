#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NICKEL 5
#define DIME 10
#define PENTE 20
#define ZERO 0
#define MODCHECK 1


int vend_process(int *price);


int main (int argc, char *argv[]){

int pop_price;
int return_val;

if (argc != 2) { // Check to see if the amount of command line arguments is not two
        printf("Please specify selling price as a command line argument.\n");
        printf("Usage: pop [price]\n");
        return 1;
}


pop_price = atoi(argv[1]);  // Convert the command line argument from a string to an integer

if (pop_price < 30 || pop_price > 105) { // Check to see if the command line argument is out of the bounds of 30 and 105
        printf("Price must be from 30 to 105 centimes inclusive\n");
        return 1;
}

else if (pop_price % 5 != 0) { // Check to see if the command line argument is a multiple of 5
        printf("Price must be a multiple of 5\n");
        return 1;

}

printf("Welcome to my C Pop Machine!\n\n");

vend_process(&pop_price); // Function Call

return 0;

}

int vend_process(int *price) {

        char userinput;

        int dime_amount = ZERO;
        int nickel_amount = ZERO;
        int nickel_temp;
        int current_sum = ZERO;
        int remaining = *price; // Set the amount remaining equal to the pointer pointing to the specified price
        
        bool re_run = false;
        bool check = false;
        bool e_func = false;

        printf("Pop is %d centimes. Please insert any combination of nickels [N or\nn], dimes [D or d]", *price);
        printf("or Pentes [P or p]. You can also press R\nor r for coin return.\n\n");

        while (remaining != ZERO) { // Loop holding the framework of the vending machine

                if (userinput == 'E') {
                        break;
                }

                dime_amount = current_sum/DIME;
                nickel_temp = current_sum - (dime_amount * DIME); // Algorithm for finding the dime and nickel amount for if the User's input is Return or Exit
                nickel_amount = nickel_temp / NICKEL;

                printf("Enter coin (NDPR):\n");
                scanf("%c", &userinput);
                getchar();

                switch (userinput) {

                        case 'N':
                        case 'n':
                                printf("  Nickel detected.\n");
                                current_sum = current_sum + NICKEL; // Adding a nickel to the sum
                                remaining = remaining - NICKEL; // Adjust the amount owing by subtracting a nickel
                                printf("    You have inserted a total of %d centimes.\n", current_sum);
                        break;

                        case 'D':
                        case 'd':
                                printf("  Dime detected.\n");
                                current_sum = current_sum + DIME; // Adding a dime to the sum
                                remaining = remaining - DIME; // Adjust the amount owing by subtracting a dime
                                printf("    You have inserted a total of %d centimes.\n", current_sum);
                        break;

                        case 'P':
                        case 'p':
                                printf("  Pente detected.\n");
                                current_sum = current_sum + PENTE; // Adding a Pente to the sum
                                remaining = remaining - PENTE; // Adjust the amount owing by subtracting a Pente
                                printf("    You have inserted a total of %d centimes.\n", current_sum);
                        break;

                        case 'R':
                        case 'r':
                                printf("    Change given: %d centimes as %d dime(s) and %d nickel(s).\n\n", current_sum, dime_amount, nickel_amount);
                                re_run = true; // Check for the function to enter recursion
                        break;
                                
                                default:
                                printf("  Unknown coin rejected.\n");
                                printf("    You have inserted a total of %d centimes.\n", current_sum);

                }

                if (e_func == true) {
                        exit(0);
                }

                if (re_run == true || current_sum >= *price) { // Break from the loop if the re-run check (for recursion) is true or the price requirement has been met or exceeded
                        break;
                }

                printf("    Please insert %d more centimes.\n", remaining);
        }
                if (current_sum >= *price) {

                        printf("    Pop is dispensed. Thank you for your business! Please come\nagain.\n\n");

                        if (current_sum >= *price) {

                                dime_amount = abs(remaining)/DIME;
                                nickel_temp = abs(remaining) - (dime_amount * DIME); // Algorithm to set the dime and nickel amount for return when there is change
                                nickel_amount = nickel_temp / NICKEL;

                                printf("    Change given: %d centimes as %d dime(s) and %d nickel(s).\n\n", abs(remaining), dime_amount, nickel_amount);
                        }
                }

                vend_process(price); // Recursion Call if all other conditions are not met


