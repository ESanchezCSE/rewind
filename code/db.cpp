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
    std::cout << "Current path: " << currentPath << std::endl;
    parse_path_from_current_directory(currentPath);
    std::cout << "New path: " << parse_path_from_current_directory(currentPath) << std::endl;
    return 0;
}


/**
 * Creation of the file that will contain the data for anything about books.
 * Checks if file is
 */
void create_book_database(){
    using namespace std;

    ofstream in_stream;
    const char *path="C:\\Users\\Edgar Sanchez\\vsCodePrograms\\rewind\\db\\bookDB.txt";
    in_stream.open(path);
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

std::string parse_path_from_current_directory(std::string currentPath){
    std::vector<std::string> result;
    std::stringstream s_stream(currentPath); //Create string stream from the string

    while(s_stream.good()){
        std::string substr;
        getline(s_stream, substr, '\\'); //Get first string delimited by comma
        result.push_back(substr);
    }
    for(int i = 0; i < result.size(); i++){
        std::cout << result.at(i) << std::endl;
    }

    std::string orginPath;
    
    for(int i = 0; i < result.size(); i++){
        std::cout << result.at(i) << std::endl;
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