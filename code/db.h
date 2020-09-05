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
void create_book_database(std::string database_file_name);
std::string get_current_dir();
std::string parse_path_from_current_directory(std::string currentPath);
std::string add_directory_to_path(std::string working_path, std::string directory_name);
std::string add_file_to_path(std::string path_to_add_file, std::string file_name);
#endif