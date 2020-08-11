// InsertionSort.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
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