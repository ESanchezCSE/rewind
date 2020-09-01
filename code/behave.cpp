#include <iostream>
#include <string>

#include "declare.h"

/**
 * A simple pop up message to great the user.
 */
void welcome_message(){
    std::cout << "Hello, welcome to Rewind! A program designed to keep\n";
    std::cout << "track of your history here on planet Earth";
}

/**
 * Displays the main menu with options the user can select.
 */
void menu(){
    std::cout << "Options:\n";
    std::cout << "1. Add Book\n";
    std::cout << "0. Exit Program\n";
}

/**
 * Ask user to select a valid option from the main_menu.
 * Receives input from the user in the form of a string.
 * 
 * @return String that represent users selection choice.
 */
std::string main_menu_choice(){
    std::string str;

    std::cout << "What would you like to do? ";
    std::cin >> str;
    return str;
}
/**
 * Displays error message when an invalid selection choice was selected.
 */
void invalid_main_menu_choice(){
    std::cout << "ERROR:: Invalid Menu Option!\n";
    std::cout << "Please enter a valid option from the menu.\n";
}

/**
 * Determines wheather a string an integer.
 * 
 * @param String that needs to be check if its an integer.
 * 
 * @return true if string is an integer| false if string is not an integer.
 */
bool check_integer(std::string str){
    for(int i = 0; i < str.length(); i++){
        if(isdigit(str[i]) == false){
            return false;
        }
    }
    
    return true;
}
