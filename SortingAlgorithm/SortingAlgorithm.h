#pragma once
#include <iostream>
#include <vector>

class SortingAlgorithm {
public:
    std::vector<int> array{ 5, 6, 2, 9, 1, 3 };

    SortingAlgorithm() {}

    SortingAlgorithm(std::vector<int> array) : array(array){}

    virtual void sort() = 0;

    void swap(std::vector<int>& array, int i, int j) {
        int curr = array.at(i); array.at(i) = array.at(j); array.at(j) = curr;
    }

    void print() {
        for (auto& item : array)
            std::cout << item << " ";
        std::cout << "\n";
    }
};