

#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

/**
 * @post: uses std::sort on a vector to return the median of that vector
 * @param: a vector reference of ints
 * @param: a int reference duration
 * @return: return the median of a vector
 */
int standardSort ( std::vector<int>& nums, int& duration ){
    auto start_time = std::chrono::high_resolution_clock::now();
    std::sort(nums.begin(), nums.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    
    int median = nums[(nums.size() - 1) / 2];
    return median;
}
