// MaxHeap.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>
#include "SortingAlgorithm.h"

class Heap {
protected:
    std::vector<int> array{0};
    const int rootIndex = 1;
    int lastIndex = 0;

    void swap(int i, int j) {
        int curr = array.at(i); array.at(i) = array.at(j); array.at(j) = curr;
    }

    void swim() {
        if (lastIndex == 1) return;
        int currentIndex = lastIndex;
        while (currentIndex / 2 != 0 && array.at(currentIndex) > array.at(currentIndex / 2)) {
            swap(currentIndex, currentIndex / 2);
            currentIndex = currentIndex / 2;
        }
    }

    void sink() {
        if (array.size() == 1) return;
        int currentIndex = rootIndex, maxChildIndex;
        while (2*currentIndex <= lastIndex){
            if (2 * currentIndex == lastIndex) maxChildIndex = 2 * currentIndex;
            else maxChildIndex = (array.at(2 * currentIndex) > array.at(2 * currentIndex + 1)) ? (2 * currentIndex) : (2 * currentIndex + 1);
            if (array.at(currentIndex) > array.at(maxChildIndex)) break;
            else swap(currentIndex, maxChildIndex); currentIndex = maxChildIndex;
        }
    }
public:
    void add(int val) {
        array.push_back(val);
        swim();
        lastIndex++;
    }

    int remove() {
        int val = array.at(rootIndex);
        array.at(rootIndex) = array.back();
        array.erase(--array.end());
        lastIndex--;
        sink();
        return val;
    }

    bool isEmpty() {
        return lastIndex == 0;
    }

    void print() {
        for (size_t i = 1; i < array.size(); i++)
            std::cout << array.at(i) << " ";
        std::cout << std::endl;
    }
};


class HeapSort : public Heap, public SortingAlgorithm {
public:
    void sort() override{
        for (auto& item : SortingAlgorithm::array)
            this->add(item);
        SortingAlgorithm::array.clear();
        while(!this->isEmpty())
            SortingAlgorithm::array.push_back(this->remove());
        std::reverse(SortingAlgorithm::array.begin(), SortingAlgorithm::array.end());
    }

    void print() {
        std::cout << "Heap Sort: ";
        SortingAlgorithm::print();
    }
};

int main()
{
    std::cout << "Heap Operation Tests: \n" << std::endl;

    Heap heap;
    heap.add(2);
    heap.add(3);
    heap.add(4);
    heap.add(5);
    heap.add(1);
    heap.print();
    heap.remove();
    heap.print();
    heap.remove();
    heap.print();

    std::cout << "\n------------- \n" << std::endl;

    HeapSort heapSort{};
    heapSort.sort();
    heapSort.print();
}
