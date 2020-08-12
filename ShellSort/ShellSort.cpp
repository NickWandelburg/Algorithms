// ShellSort.cpp : ShellSort implementation with an increment sequence h
//

#include <iostream>
#include <vector>
#include "SortingAlgorithm.h"

class ShellSort : public SortingAlgorithm {
public:
    ShellSort() {}
    ShellSort(std::vector<int> array) : SortingAlgorithm(array) {}

    void sort() override{
        // Compare list items with distance h to each other and swap them if needed
        const int SIZE = array.size();
        int h = 1; 
        while (h < SIZE / 3) h = 3 * h + 1;
        while (h >= 1) {
            for (size_t i = h; i < SIZE; i++)
            {
                for (int j = i; j >= h && (array.at(j - h) > array.at(j)); j-=h)
                    swap(array, j - h, j);
            }
            // Decrease h sequentially
            h /= 3;
        }
    }

    void print() {
        std::cout << "Shell Sort: ";
        SortingAlgorithm::print();
    }
};

int main()
{
    ShellSort shellSort{};
    shellSort.sort();
    shellSort.print();
}