// MaxHeap.cpp : MaxHeap and HeapSort implementation 
//

#include <iostream>
#include <vector>
#include "SortingAlgorithm.h"

class MaxHeap {
protected:
	std::vector<int> heap{ 0 };
	const int rootIndex = 1;
	int lastIndex = 0;

	void swap(int i, int j) {
		int curr = heap.at(i); heap.at(i) = heap.at(j); heap.at(j) = curr;
	}

	void swim() {
		// Swap the child with the parent node as long it is greater than it's parent node
		if (isEmpty()) return;
		int currentIndex = lastIndex;
		while (currentIndex / 2 != 0 && heap.at(currentIndex) > heap.at(currentIndex / 2)) {
			swap(currentIndex, currentIndex / 2);
			currentIndex = currentIndex / 2;
		}
	}

	void sink() {
		// Swap the parent with the greatest child as long it is less than the selected child
		if (isEmpty()) return;
		int currentIndex = rootIndex, maxChildIndex;
		while (2 * currentIndex <= lastIndex) {
			if (2 * currentIndex == lastIndex) maxChildIndex = 2 * currentIndex;
			else maxChildIndex = (heap.at(2 * currentIndex) > heap.at(2 * currentIndex + 1)) ? (2 * currentIndex) : (2 * currentIndex + 1);
			if (heap.at(currentIndex) > heap.at(maxChildIndex)) break;
			else swap(currentIndex, maxChildIndex); currentIndex = maxChildIndex;
		}
	}
public:
	void add(int val) {
		// Add item at the end and determine the right position within the MaxHeap
		heap.push_back(val);
		swim();
		lastIndex++;
	}

	int remove() {
		/* Remove maximum (root) item of MaxHeap, replace it with the last item 
		and determine the right position within the MaxHeap */
		int val = heap.at(rootIndex);
		heap.at(rootIndex) = heap.back();
		heap.erase(--heap.end());
		lastIndex--;
		sink();
		return val;
	}

	bool isEmpty() {
		return lastIndex == 0;
	}

	void print() {
		for (size_t i = 1; i < heap.size(); i++)
			std::cout << heap.at(i) << " ";
		std::cout << std::endl;
	}
};

class HeapSort : public MaxHeap, public SortingAlgorithm {
public:
	void sort() override {
		// Fill MaxHeap with the items of the unordered list
		for (auto& item : SortingAlgorithm::array)
			this->add(item);
		SortingAlgorithm::array.clear();
		// Remove all items in descending order from the MaxHeap and add it to the result list
		while (!this->isEmpty())
			SortingAlgorithm::array.push_back(this->remove());
		// Reverse descending to ascending order of the items contained in the result list
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

	MaxHeap maxHeap;
	maxHeap.add(2);
	maxHeap.add(3);
	maxHeap.add(4);
	maxHeap.add(5);
	maxHeap.add(1);
	maxHeap.print();
	maxHeap.remove();
	maxHeap.print();
	maxHeap.remove();
	maxHeap.print();

	std::cout << "\n------------- \n" << std::endl;

	HeapSort heapSort{};
	heapSort.sort();
	heapSort.print();
}
