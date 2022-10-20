#include <bits/chrono.h>
#include <bits/types/time_t.h>
#include <cstddef>
#include <iostream>
#include <map>
#include <utility>
#include <time.h>
#include <chrono>

int main() {
    const auto t_start = std::chrono::steady_clock::now();

    std::map<std::pair<size_t, size_t>, int> data1;
    data1[{0, 0}] = 1;
    std::map<std::pair<size_t, size_t>, int> data2;
    data2[{0, 0}] = 1;
    std::map<std::pair<size_t, size_t>, int> data_d;
    data_d[{0, 0}] = data1[{0, 0}] * data2[{0, 0}];

    const auto t_end = std::chrono::steady_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
    
    std::cout << "Executing time: " << duration << "\n";
}
