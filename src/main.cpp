#include <iostream>
#include <string>
#include <vector>


#include "initialFunction.h"
#include "noteManager.h"


#define NOTES_DIRECTORY_NAME "/notes"
#define SHELL_MENU_MESSAGE "1 create new note\n2 read note\n3 edit note\n0 exit"



int main(){

    const std::string PROGRAM_PATH{ findProgramRootPath() };
    createDirectory(PROGRAM_PATH, NOTES_DIRECTORY_NAME);
    const std::string NOTES_DIRECTORY_PATH{ PROGRAM_PATH + NOTES_DIRECTORY_NAME };


    int userCommand { 0 };
    std::string userInputedNoteText;
    std::string activeNote;
    std::vector< std::string > notesName;


    while (true){

        std::cout << SHELL_MENU_MESSAGE << '\n';
        std::cout << ">>> ";
        std::cin >> userCommand;
        
        switch (userCommand)
        {
            case 1: // create new note
                std::cout << "U wanna create new note\nenter note title : ";
                
                std::cin >> activeNote;
                
                createNote(NOTES_DIRECTORY_PATH, activeNote);

                std::cout << "enter note text : " ;
                std::cin >> userInputedNoteText;

                writeInNote(PROGRAM_PATH + NOTES_DIRECTORY_NAME + '/' + activeNote, userInputedNoteText);
                std::cout << activeNote << " was created !!!\n" ;
                break;

            case 2: // read note
                // std::cout << '\n';
                notesName = returnNotesName(NOTES_DIRECTORY_PATH);

                for(int i{0}; i < notesName.size(); i++){
                    std::cout << notesName[i] << " ";
                }
                std::cout << '\n';

                std::cout << "witch note do U want to read : ";
                std::cin >> activeNote;
                userInputedNoteText = readNote(NOTES_DIRECTORY_PATH + '/' + activeNote);
                std::cout << '\n';
                std::cout << userInputedNoteText << '\n';
                std::cout << '\n';

                break;
            
            case 3: // edit note
                notesName = returnNotesName(NOTES_DIRECTORY_PATH);

                for(int i{0}; i < notesName.size(); i++){
                    std::cout << notesName[i] << " ";
                }
                std::cout << '\n';

                std::cout << "witch note do U want to Edit : ";

                std::cin >> activeNote;
                userInputedNoteText = readNote(NOTES_DIRECTORY_PATH + '/' + activeNote);
                std::cout << '\n';
                std::cout << userInputedNoteText << '\n';
                std::cout << '\n';

                std::cout << "enter new note text : ";

                std::cin >> userInputedNoteText;

                writeInNote(PROGRAM_PATH + NOTES_DIRECTORY_NAME + '/' + activeNote, userInputedNoteText);
                std::cout << activeNote << " was Edited !!!\n" ;

                break;

            case 0: // exit program

                return 0;
                break;
        }
        
        std::cout << "----------------------------------\n";

    }

 
    return 0;
}

