// InsertionSort.cpp : InsertionSort implementation
//

#include <iostream>
#include <vector>
#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm
{
public:
    InsertionSort() {}
    InsertionSort(std::vector<int> array) : SortingAlgorithm(array) {}

    void sort() override{
        /* Swap the current list item with the previous list item as long as it is smaller
        or the begin of the list is reached */
        for (size_t i = 1; i < array.size(); i++)
        {
            for (size_t j = i; j > 0 && (array.at(j-1) > array.at(j)); j--)
                this->swap(array, j - 1, j);
        }
    }

    void print(){
        std::cout << "Insertion Sort: ";
        SortingAlgorithm::print();
    }
};

int main()
{
    InsertionSort insertionSort{};
    insertionSort.sort();
    insertionSort.print();
}