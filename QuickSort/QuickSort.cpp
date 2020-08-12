// QuickSort.cpp : Recurisve QuickSort implementation
//

#include <iostream>
#include <vector>
#include <ctime>
#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {
private:
    int partition(int lo, int hi) {
        const int pivot = array.at(lo);
        int i = lo, j = hi + 1;

        /* Swap the next item which is greater than the pivot element in the left sublist 
        with the next item which is less than the pivot elemtnet in the right sublist */
        while (true) {
            while (array.at(++i) < pivot) if (i == hi) break;
            while (array.at(--j) > pivot) if (j == lo) break;
            if (i >= j) break;
            this->swap(array, i, j);
        }
        // Swap pivot item into right position
        this->swap(array, lo, j);
        return j;
    }
public:
    QuickSort() {}
    QuickSort(std::vector<int> array) : SortingAlgorithm(array) {}

    void sort(int lo, int hi) {
        if (hi <= lo) return;
        int j = partition(lo, hi);
        // Sort left sublist
        sort(lo, j - 1);
        // Sort right sublist
        sort(j + 1, hi);
    }

    void sort() override{
        sort(0, array.size()-1);
    }

    void print() {
        std::cout << "Quick Sort: ";
        SortingAlgorithm::print();
    }
};

int main()
{
    QuickSort quickSort;
    quickSort.sort();
    quickSort.print();
}
