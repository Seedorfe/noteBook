

#ifndef INITIAL_FUNCTION_H
#define INITIAL_FUNCTION_H

#include <string>
#include <vector>

std::string findProgramRootPath();

void createDirectory(std::string directoryPath, std::string directoryName);

std::vector< std::string > returnNotesName(std::string notesDirectoryPath);

#endif