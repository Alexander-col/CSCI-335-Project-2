

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

/**
 * @post: split a vector in two vecs then recusively split them until a single element remains in each vec
 then std::merge to merge them together again
 * @param: a vector reference to the ints
 * @param: int reference holding the duration
 * @return: returns the median int in vector
 */
int mergeSort ( std::vector<int>& nums, int& duration )
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int length = nums.size();
    if(length < 2)
    {
        return duration;
    }
    int middle = length / 2;
    std::vector<int> left_nums(middle);

    std::vector<int> right_nums(length - middle);

    int i = 0, j = 0;

    for(i; i < length; ++i)
    {
        if(i < middle)
        {
            left_nums[i] = nums[i];
        }
        else
        {
            right_nums[j] = nums[i];
            j++;
        }
    }
    mergeSort(left_nums, duration);
    mergeSort(right_nums, duration);
    std::merge(left_nums.begin(), left_nums.end(), right_nums.begin(), right_nums.end(), nums.begin());

    auto end_time = std::chrono::high_resolution_clock::now();
    
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    int median = nums[(nums.size() - 1) / 2];
    return median;
}