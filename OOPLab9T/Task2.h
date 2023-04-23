#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include<deque>

void task2() {
    std::vector<int> V = { 11, 14, 15, 16, 17, 17, 18, 10 };
    std::deque<int> D = { 1, 2, 3, 4, 5, 6 };
    if (D.size() % 2 != 0) {
        std::cout << "The deck has an odd number of elements";
        return;
    }
    std::cout << "---------------------" << std::endl;
    std::cout << "Deque D: " << std::endl << "{ ";
    for (const auto& vect : D) {
        std::cout << vect << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Vector before change:" << std::endl << "{ ";
    for (const auto& vect : V) {
        std::cout << vect << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::deque<int> first_half(D.begin(), D.begin() + D.size() / 2);
    auto it_start = std::find_end(V.begin(), V.end(), first_half.begin(), first_half.end(), 
    [](int x, int y){ 
            return ((x % 2 == 0) == (y % 2 == 0)); 
    });
    if (it_start != V.end()) {
        auto it_end = it_start + first_half.size();
        V.erase(it_start, it_end);
        std::cout << "Vector after change:" << std::endl << "{ ";
        for (const auto& vect : V) {
            std::cout << vect << " ";
        }
    }
    else {
        std::cout << "Vector not changed"<<std::endl<<"{ ";
        for (const auto& vect : V) {
            std::cout << vect << " ";
        }
    }
    std::cout << "}" << std::endl;
    std::cout << "---------------------" << std::endl;

}
