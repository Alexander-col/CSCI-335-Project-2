

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

/**
 * @post: split between the L and R iterators in half and recursively split half until split contains only 1 element then proceed to inplace_merge back the splits together
 * @param: beginning iterator to start with 
 * @param: end iterator to end the func
 */
void inPlaceMergeSortHelper(std::vector<int>::iterator left, std::vector<int>::iterator right)
{
   if(std::distance(left, right) > 1)
   {
        auto mid = std::next(left, std::distance(left, right) / 2);

        inPlaceMergeSortHelper(left, mid);
        inPlaceMergeSortHelper(mid, right);

        std::inplace_merge(left, mid, right);
   }
}
/**
 * @post: calls the inPlaceMergeSort gving the stanr and end params of vector of nums
 * @param: vector reference of the numbers
 * @param: int reference the duration va
 * @return: returns the median numbers
 */
int inPlaceMergeSort ( std::vector<int>& nums, int& duration )
{
    auto start_time = std::chrono::high_resolution_clock::now();

    inPlaceMergeSortHelper(nums.begin(), nums.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    
    int median = nums[(nums.size() - 1) / 2];
    return median;
}