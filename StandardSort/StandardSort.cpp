// StandardSort.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> array{ 5, 6, 2, 9, 1, 3 };
    std::sort(array.begin(), array.end());

    std::cout << "Standard C++ Sort: ";

    for (auto& item : array)
        std::cout << item << " ";

    std::cout << "\n";
}