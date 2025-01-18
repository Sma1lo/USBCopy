#include <iostream>
#include <filesystem>
#include <string>
#include <windows.h>

namespace fs = std::filesystem;

/*
@author Sma1lo
*/

void setConsoleColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

int main() {
    std::string sourceFile;
    std::string destinationPath;

    setConsoleColor(10);
    const char* asciiArt = R"(     __  _______ ____  ______                 
    / / / / ___// __ )/ ____/___  ____  __  __
   / / / /\__ \/ __  / /   / __ \/ __ \/ / / /
  / /_/ /___/ / /_/ / /___/ /_/ / /_/ / /_/ / 
  \____//____/_____/\____/\____/ .___/\__, /  
                              /_/    /____/   
    )";

    std::cout << asciiArt << std::endl;
    setConsoleColor(7);

    std::cout << "\tv 1.0, Author: Sma1lo\n";

    std::cout << "\nEnter the path to the file to copy: ";
    std::getline(std::cin, sourceFile);

    std::cout << "Enter the destination path: ";
    std::getline(std::cin, destinationPath);

    if (!fs::exists(sourceFile)) {
        std::cout << "Source file not found." << std::endl;
        return 1;
    }

    if (!fs::exists(destinationPath)) {
        std::cout << "Destination folder not found." << std::endl;
        return 1;
    }

    std::string fileName = fs::path(sourceFile).filename().string();

    try {
        fs::copy(sourceFile, destinationPath + "\\" + fileName, fs::copy_options::overwrite_existing);
        std::cout << "Copying completed." << std::endl;
    }
    catch (const fs::filesystem_error& e) {
        std::cout << "Error copying file: " << e.what() << std::endl;
        return 1;
    }

    std::cout << " Press Enter to continue...";
    std::cin.get();

    return 0;
}