#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
void task3() {
    std::cout << "---------------------" << std::endl;
    std::vector<int> V = { 2, 4, 1, 2, 3, 2, 4, 4, 5 };
    std::cout << "Vector:{";
    for (const auto& element : V) {
        std::cout << element << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::sort(V.begin(), V.end());  
    std::multiset<int> ms(V.begin(), V.end()); 
    std::cout << "Result(value : count) :" << std::endl;
    for (auto it = ms.begin(); it != ms.end(); ) {
        auto next_it = ms.upper_bound(*it);  
        std::cout << *it << " : " << std::distance(it, next_it) << std::endl;
        it = next_it;
    }
    std::cout << "---------------------" << std::endl;
}