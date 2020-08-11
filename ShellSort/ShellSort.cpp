// ShellSort.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>
#include "SortingAlgorithm.h"

class ShellSort : public SortingAlgorithm {
public:
    ShellSort() {}
    ShellSort(std::vector<int> array) : SortingAlgorithm(array) {}

    void sort() override{
        const int SIZE = array.size();
        int h = 1; 
        while (h < SIZE / 3) h = 3 * h + 1;
        while (h >= 1) {
            for (size_t i = h; i < SIZE; i++)
            {
                for (int j = i; j >= h && (array.at(j - h) > array.at(j)); j-=h)
                    swap(array, j - h, j);
            }
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