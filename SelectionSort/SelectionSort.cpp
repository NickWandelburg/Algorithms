// SelectionSort.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
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
