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

#include "db.h"


int main(){
    create_book_database();
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
        in_stream << "File creation is successful!\n";
    in_stream.close();
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