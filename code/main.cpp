#include <iostream>
#include <string>

#include "declare.h"
#include "db.h"

int main(){
    std::string menu_choice;
    
    welcome_message();
    do{
        menu();
        menu_choice = main_menu_choice();
        if(check_integer(menu_choice) == true){
            //User selection is an integer.
            std::cout << "your choice is a number!!\n";
            menu_selection(menu_choice);
        }
        else{
            //User selection is an invalid format.
            invalid_main_menu_choice();
            std::cout << "your choice is invalid!!\n";
        }
    }while(!menu_choice.empty());

    return 0;
}
