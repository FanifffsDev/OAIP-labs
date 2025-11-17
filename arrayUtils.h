#include <iostream>

void printIntArray(int* arr, int size){
    int i = 0;

    std::cout << "[";
    while(i < size -1){
        std::cout << arr[i] << ", ";
        i++;
    }
    std::cout << arr[size - 1] << "]" << std::endl;
}