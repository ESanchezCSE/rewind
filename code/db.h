#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

/**
 *This is a note to myself.
 *Guard (below) makes sure that it is only included once when compiled.
*/
#ifndef DB_H
#define DB_H
void create_book_database();
std::string get_current_dir();
std::string parse_path_from_current_directory(std::string currentPath);
#endif