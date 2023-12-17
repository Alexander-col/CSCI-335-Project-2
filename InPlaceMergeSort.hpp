

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

/**
 * @post: split between the left and right iterators in half and recursively split each half until each split contains only 1 element then proceed to inplace_merge back the splits
 * @param: beginning iterator
 * @param: end iterator
 */
void inPlaceMergeSortHelper(std::vector<int>::iterator left, std::vector<int>::iterator right){
   if(std::distance(left, right) > 1){
        auto mid = std::next(left, std::distance(left, right) / 2);

        inPlaceMergeSortHelper(left, mid);
        inPlaceMergeSortHelper(mid, right);

        std::inplace_merge(left, mid, right);
   }
}
/**
 * @post: calls the inPlaceMergeSort gving the beginning and end parameters of the vector of nums
 * @param: vector reference of numbers
 * @param: int reference duration
 * @return: returns the median of the numbers
 */
int inPlaceMergeSort ( std::vector<int>& nums, int& duration ){
    auto start_time = std::chrono::high_resolution_clock::now();

    inPlaceMergeSortHelper(nums.begin(), nums.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    
    int median = nums[(nums.size() - 1) / 2];
    return median;
}