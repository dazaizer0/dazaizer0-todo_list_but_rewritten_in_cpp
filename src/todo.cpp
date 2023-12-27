#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include "todo_manager.h"

int main() {
    // variables
    std::string message = "1 - add to todo list, 2 - remove from todo list, 3 - show list, 4 - finish, \n5 - save to txt";
    td::todo_list todo;
    int way;

    // start message
    for (const char i : message) {
        std::cout << i;
        Sleep(25);
    }

    // main loop
    while (way != 4) {
        // get way
        std::cout << "\nchoice -> ";
        std::cin >> way;

        // add to list
        if (way == 1) {
            int todo_length = static_cast<int>(todo.list.size());

            std::string what;
            std::cout << "\nadd -> ";

            std::getline(std::cin >> std::ws, what);

            todo.list[todo_length + 1] = what;
        }
        // remove from list
        else if (way == 2) {
            int index;
            std::cout << "\nremove index -> ";

            try {
                std::cin >> index;
                todo.list.erase(index);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "error: " << e.what() << std::endl;
            }
        }
        // show list
        else if (way == 3) {
            todo.show();
        }
        // finish
        else if (way == 4) {
            break;
        }
        // save to txt
        else if (way == 5) {
            std::ofstream file("todo_save.txt");

            if (file.is_open()) {
                for (const auto& pair : todo.list) {
                    file << pair.first << ": " << pair.second << std::endl;
                }

                file.close();

                std::cout << "the to-do list has been saved" << std::endl;
            }
            else {
                std::cerr << "error with saveing list." << std::endl;
            }
        }
        // other
        else {
            std::cout << "wrong choice..." << std::endl;
            continue;
        }
    }

    return 0;
}
