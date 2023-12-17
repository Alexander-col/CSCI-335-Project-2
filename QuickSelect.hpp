

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm> 

/**
 * @post: returns  median value of the between a start, mid, and end iterator and swaps the mid iterator to end iterator
 * @param: the vector of ints
 * @param: the lower bound interator
 * @param: the upper bound interator
 * @return: returns the iterator with a median value
 */
std::vector<int>::iterator medianOf3(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = high;
    std::vector<int>::iterator mid = left + (right - left) / 2;
    if(*mid < *left && *mid > *right || *mid > *left && *mid < *right)
    {
        std::iter_swap(mid,right);
    }
    else if(*left < *mid && *left > *right || *left > *mid && *left < *right)
    {
        std::iter_swap(left, right);
    }
    return right;
}
/**
 * @post: applys spliting between a end iterator bound and higher start bound of nums vector of ints
 * @param: a vector reference the ints
 * @param: a end bound interator
 * @param: an start bound interator
 * @return: returns the iterator of the pivot then positioning it to the right position
 */
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high )
{
    std::vector<int>::iterator pivot = medianOf3(nums, low, high);
    std::vector<int>::iterator i = low;
    std::vector<int>::iterator j = pivot - 1;
    while (true) {
        while (*i < *pivot) 
        {
            ++i;
        }
        while (*j > *pivot) 
        {
            --j;
        }
        if (i >= j) 
        {
            break;
        }
        std::iter_swap(i, j);
        ++i;
        --j;
    }
    std::iter_swap(i, pivot);
    return i;
}

/**
 * @post: recusively call itself then hoare's partition to vector until the partition holds less than equal to 10 elements, then use sort
 * @param: a vector reference of the ints
 * @param: a end bound interator
 * @param: an start bound interator
 * @param: a mid bound interator
 */
void recursiveQuickSelect(std::vector<int>& nums, std::vector<int>::iterator lower, std::vector<int>::iterator upper, std::vector<int>::iterator middle){
    if(std::distance(lower, upper) < 10)
    {
        std::sort(lower, upper + 1);
        return;
    }

    std::vector<int>::iterator pivot = hoarePartition(nums, lower, upper);
    if(pivot == middle)
    {
        return;
    }
    else if(pivot < middle)
    {
        recursiveQuickSelect(nums, pivot + 1, upper, middle);
    }
    else if(pivot > middle)
    {
        recursiveQuickSelect(nums, lower, pivot - 1, middle);
    }
}

/**
 * @post: call the recursive quick select helper function to part until it finds the mid, then return the mid's index
 * @param: a vector reference of the ints
 * @param: a int reference the duration val
 * @return: return the mid of a vector
 */
int quickSelect ( std::vector<int>& nums, int& duration )
{
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int>::iterator lower = nums.begin();
    std::vector<int>::iterator upper = nums.end() - 1;
    std::vector<int>::iterator middle = nums.begin() + (nums.size() - 1)/2;

    recursiveQuickSelect(nums, lower, upper, middle);

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    return *(nums.begin() + (nums.size() - 1)/2);
}
