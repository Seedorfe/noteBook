#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>


#include "noteManager.h"



void createNote(std::string notePath, std::string noteName){

    std::string noteFullPath{ notePath + '/' + noteName };

    std::fstream noteManager{ };

    noteManager.open(noteFullPath, std::ios::out);

    noteManager.close();

}




void writeInNote(std::string noteFullPath, std::string noteText){

    std::fstream noteManager{ };

    noteManager.open(noteFullPath);
    
    char *text = noteText.data();

    noteManager.write(text, noteText.length() + 1);

    noteManager.close();

}



std::string readNote(std::string noteFullPath){

    std::fstream noteManger{ };

    std::uintmax_t noteSize{ std::filesystem::file_size(noteFullPath) };

    noteManger.open(noteFullPath);

    char noteText[noteSize];

    noteManger.read(noteText, noteSize);

    noteManger.close();

    return noteText;
}








