
#include <iostream>
#include"Task1.h"
#include"Task2.h"
#include"Task3.h"
int main()
{
    std::cout << "Lab 9 \n";
    char ch = '5';
    do {
        std::cout << "Chose task 1-3 (4-exit):" << std::endl;
        std::cout << " >>> ";
        ch = std::cin.get();

        std::cin.get();

        switch (ch) {
        case '1': task1();  break;
       // case '2': Task2();  break;
        case '3': task3();  break;
        case '4': return 0;
        }
        std::cout << " Press any key and enter\n";
        ch = std::cin.get();
    } while (ch != '5');
}

