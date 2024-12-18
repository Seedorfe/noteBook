#include <filesystem>
#include <string>
#include <iostream>
#include <vector>




#include "initialFunction.h"




std::string findProgramRootPath(){

    std::filesystem::path rootPath { std::filesystem::current_path() };

    return rootPath;
}




void createDirectory(std::string directoryPath, std::string directoryName){

    std::filesystem::path fullDirectoryPath { directoryPath + '/' + directoryName };

    bool createDirectoryResult { std::filesystem::create_directory(fullDirectoryPath) };

}




std::vector< std::string > returnNotesName(std::string notesDirectoryPath){

    std::filesystem::directory_iterator directoryIterator{ notesDirectoryPath };
    
    std::vector< std::string > names;

    for (auto directoryEntry : directoryIterator){

        std::string noteName{ directoryEntry.path() };

        noteName.erase(0, notesDirectoryPath.length() + 1);

        names.push_back(noteName);
    }

    return names;

    // // directory_iterator can be iterated using a range-for loop
    // for(auto fileName : std::filesystem::directory_iterator{ notesDirectoryPath }){
        
    //     std::filesystem::file_status fileStatus { std::filesystem::status(fileName) };
    //     std::filesystem::file_type fileType = fileStatus.type();
    //     std::cout << fileName << '\n';
    //     std::cout << (int)fileType << '\n'; 
    // }

} 




// int main(){

//     std::vector< std::string > _temp{ returnNotesName("/home/desmond/vscode/learnCpp/note/note.db") };
    
//     for(int i = 0; i < _temp.size(); i++){
//         std::cout << _temp[i] << '\n';
//     }
//     return 0;
// }




