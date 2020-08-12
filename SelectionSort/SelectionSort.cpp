// SelectionSort.cpp : SelectionSort implementation
//

#include <iostream>
#include <vector>
#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm
{
public:
    SelectionSort() {}
    SelectionSort(std::vector<int> array) : SortingAlgorithm(array) {}

    void sort() override{
        // Swap the current list item with the smallest item contained in the still unsorted list section
        for (size_t i = 0; i < array.size(); i++)
        {
            int currMinIndex = i;
            int currMin = array.at(i);
            for (size_t j = i+1; j < array.size(); j++)
            {
                if (currMin > array.at(j)) {
                    currMin = array.at(j);
                    currMinIndex = j;
                }
            }
            this->swap(array, i, currMinIndex);
        }
    }

    void print() {
        std::cout << "Selection Sort: ";
        SortingAlgorithm::print();
    }
};

int main()
{
    SelectionSort selectionSort{};
    selectionSort.sort();
    selectionSort.print();
}
