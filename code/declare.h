#include <iostream>
#include <string>

/**
 *Guard (below) makes sure that it is only included once when compiled.
 */
#ifndef DECLARE_H
#define DECLARE_H
void welcome_message();
void menu();
std::string main_menu_choice();
void invalid_main_menu_choice();
bool check_integer(std::string str);
void menu_selection(std::string &menu_choice);
#endif