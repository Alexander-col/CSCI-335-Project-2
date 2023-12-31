

#include <vector>
#include <iostream>
#include <chrono>

/**
 * @post: aranges the first half of lowest ints
 * @param: vector reference of the numbers
 * @param: int reference the duration
 * @return: returns median of numbers
 */
int halfSelectionSort ( std::vector<int>& nums, int& duration)
{
    auto start_time = std::chrono::steady_clock::now();
    std::vector<int>::iterator min;
    int half = (nums.size() -1) / 2;
    for(auto it = nums.begin(); it !=nums.end(); ++it)
    {
        if(it >= nums.begin() + half + 1)
        {
            break;
        }
        min = it;
        for(auto it2 = it; it2 !=nums.end(); ++it2)
        {
            if(*it2 < *min)
            {
                min = it2;
            }
        }
        std::swap(*it, *min);
    }
    auto end_time = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return nums[half];
}