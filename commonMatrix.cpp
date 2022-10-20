#include <time.h>
#include <iostream>
#include <bits/types/time_t.h>
#include <cstddef>
#include <map>
#include <utility>
#include <chrono>

int main(void) {
    const auto t_start = std::chrono::steady_clock::now();

    std::map<std::pair<size_t, size_t>, int> arr1;
    std::map<std::pair<size_t, size_t>, int> arr2;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <100; j++) {
            arr1[{i, j}] = 0;
            arr2[{i, j}] = 0;
        }
    }

    arr1[{0, 0}] = 1;
    arr2[{0, 0}] = 1;

    std::map<std::pair<size_t, size_t>, int> arr_d;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr_d[{i, j}] = arr1[{i, j}] * arr2[{i, j}];
        }
    }

    const auto t_end = std::chrono::steady_clock::now();
    
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
    std::cout << "Executing time: " << duration << "\n"; 
}
