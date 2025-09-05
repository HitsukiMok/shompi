#include <stdio.h>
#include <string.h>

int main(){

    char cus_name[50] = ""; //spaces are not necessary in initialization.
    char item [50] = "";
    float price = 0.0f;
    char curren[3] = "Php";
    int quanti = 0;
    float total = 0.0f;

    //hard-coding array sizes isn't usually advisable, but in bigger programs its better to use constants.
    /*
    #define NAME_LEN 50
    #define ITEM_LEN 50
    #define CURR_LEN 4
    
    char cus_name[NAME_LEN] = "";
    ... so on

    by practice, constants in C is written in UPPERCASE to ensure it won't be confused from variables
    */

    //Customer name input
    printf("Welcome to Shompi, Please enter your nickname:\n");
    scanf(" %49s", &cus_name);
    //scanf(" %s", &cus_name); - We dont need the amperstand since cus_name already decays into a pointer.
    //to take it a step further, we can add 49  in the format specifier so the user cannot enter more than 49 characters, and leaves space for the null terminator.

    
    
    //Item name input
    getchar();
    printf("\nThank you %s, Now please name your item: \n", cus_name);
    fgets(item, sizeof(item), stdin);
    item[strlen(item) - 1] = '\0';

    //item[strlen(item) - 1] = '\0' only works if it ends with \n, its dangerous if the user exactly fills the buffer, it will chop the last character of the input
    //eg asphyxiation will become asphyxiatio
    //safer alternative would be item[strcspn(item, "\n")] = '\0';
    // more general usage, and doesn't only remove \n
    // for building projects just use strlen for now lmao. strcspn is for cleanup


    //Price input
    printf("\nPlease input the price of the item: \n");
    scanf("%f", &price);

    //Quantity input
    printf("\nNow please input the quantity of the item:\n");
    scanf("%d", &quanti);

    //Total calculation & Output
    total = price * quanti;
    printf("\nThank you for your input %s, You've purchased %d %s/s, the total would be %.2f %s.", cus_name, quanti, item, total, curren);

    return 0;
}