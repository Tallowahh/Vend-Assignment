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
        int remaining = *price; // Set the amount remaining equal to the po
