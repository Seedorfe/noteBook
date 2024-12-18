

#ifndef NOTE_MANAGER_H
#define NOTE_MANAGER_H

#include <string>

void createNote(std::string notePath, std::string noteName);

void writeInNote(std::string noteFullPath, std::string noteText);

std::string readNote(std::string noteFullPath);


#endif
