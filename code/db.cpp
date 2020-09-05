#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "db.h"


int main(){
    std::string currentPath = get_current_dir();
    std::string orginPath = parse_path_from_current_directory(currentPath);
    std::cout << "Current path: " << currentPath << std::endl;
    std::string workingPath = add_directory_to_path(orginPath, "db\\");
    std::string workingFile = add_file_to_path(workingPath, "musicDb.txt");
    std::cout << "File Path: " << workingFile << std::endl;
    create_book_database(workingFile);
    return 0;
}


/**
 * Creation of the file that will contain the data for anything about books.
 * Checks if file is
 */
void create_book_database(std::string database_file_name){
    using namespace std;

    ofstream in_stream;
    //const char *path = database_file_name;
    in_stream.open(database_file_name);
        in_stream << "File creation is successful!\n";//Test code.
    in_stream.close();
    return;
}

/**
 * Gets current working directory.
 * 
 * @returns String containg the path of the current working directory.
 */
std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}

/**
 * Get the orgin path to the directory of the program. The orgin path should be in the format of ~\rewind\
 * 
 * @param string that contains a path of the working directory
 * 
 * @return String that contains the orgin path in the format of ~\rewind\
 */
std::string parse_path_from_current_directory(std::string currentPath){
    std::vector<std::string> result;
    std::stringstream s_stream(currentPath); //Create string stream from the string

    while(s_stream.good()){
        std::string substr;
        getline(s_stream, substr, '\\'); //Get first string delimited by comma
        result.push_back(substr);
    }
    /*
    for(int i = 0; i < result.size(); i++){
        std::cout << result.at(i) << std::endl;
    }
    */
    std::string orginPath;
    
    for(int i = 0; i < result.size(); i++){
        if(result.at(i).compare("rewind") != 0){
            orginPath.append(result.at(i));
            orginPath.append("\\");
        }
        else{
            orginPath.append(result.at(i));
            orginPath.append("\\");
            break;
        }
    }

    return orginPath;
}

/**
 * Appends the directory that you wish to work in, to the orgin path.
 * 
 * @param string[working_path] the current directory where the program path is located.
 * @param string[directory_name] the name of directory that you need to switch to.
 * 
 * @return String containing the updated path to the directory you wish to work in.
 */
std::string add_directory_to_path(std::string working_path, std::string directory_name){
    return working_path.append(directory_name);
}

/**
 * Appends the file name that you wish to work with to the path containing the directory the file should be located in.
 * 
 * @param string[path_to_add_file] containing the path of the directory the file should go in to
 * @param string[file_name] containing the name of the file that you wish to work with.
 * 
 * @return string conting the path to the file, with the file name, of the file that needs to be worked with.
 */
std::string add_file_to_path(std::string path_to_add_file, std::string file_name){
    return path_to_add_file.append(file_name);
}