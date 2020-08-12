// MergeSort.cpp : Buttom-up MergeSort implementation
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {
private:
    void merge(int lo, int mid, int hi) {
        std::vector<int> aux = array;
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            // Left half already merged: take next right half item
            if (i > mid) array.at(k) = aux.at(j++);
            // Right half already merged: take next left half item
            else if (j > hi)  array.at(k) = aux.at(i++);
            // Current right half item is less than smallest left half item
            else if (array.at(j) < aux.at(i)) array.at(k) = aux.at(j++);
            // Current left half item is less than smallest right half item 
            else array.at(k) = aux.at(i++);
        }
    }
public:
    MergeSort() {}
    MergeSort(std::vector<int> array) : SortingAlgorithm(array) {}

    void sort() override{
        const int SIZE = array.size();
        // Sort subarrays with size sz
        for (int sz = 1; sz < SIZE; sz += sz) {
            for (int lo = 0; lo < (SIZE - sz); lo += sz + sz)
                merge(lo, lo + sz - 1, std::min(lo+sz+sz-1, SIZE-1));
        }
    }

    void print() {
        std::cout << "Merge Sort: ";
        SortingAlgorithm::print();
    }
};

int main()
{
    MergeSort mergeSort{};
    mergeSort.sort();
    mergeSort.print();
}