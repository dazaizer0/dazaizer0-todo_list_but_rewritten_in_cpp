#ifndef TODO_TODO_MANAGER_H
#define TODO_TODO_MANAGER_H

#include <iostream>
#include <map>

namespace td {
    class todo_list {
    public:
        std::map<int, std::string> list;

        void show() {
            std::cout << std::endl;

            for (const auto& pair : list) {
                std::cout << "Nr: " << pair.first << ", ToDo: " << pair.second << std::endl;
            }

            std::cout << std::endl;
        }
    };
}

#endif
