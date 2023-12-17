

#include <vector>
#include <iostream>
#include <chrono>

/**
 * @post: returns the median value of the between a beginning, middle, and end iterator and swaps the median iterator to the end iterator
 * @param: a vector of ints
 * @param: a lower bound interator
 * @param: an upper bound interator
 * @return: returns the iterator with the median value
 */
std::vector<int>::iterator medianOf3(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){
    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = high;
    std::vector<int>::iterator mid = left + (right - left) / 2;
    if(*mid < *left && *mid > *right || *mid > *left && *mid < *right){
        std::iter_swap(mid,right);
    }
    else if(*left < *mid && *left > *right || *left > *mid && *left < *right){
        std::iter_swap(left, right);
    }
    return right;
}
/**
 * @post: applys hoarepatitioning between a lower iterator bound and higher iterator bound of nums vector of ints
 * @param: a vector reference of ints
 * @param: a lower bound interator
 * @param: an upper bound interator
 * @return: returns the iterator of the pivot after positioning it to the correct position
 */
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){
    std::vector<int>::iterator pivot = medianOf3(nums, low, high);
    std::vector<int>::iterator i = low;
    std::vector<int>::iterator j = pivot - 1;
    while (true) {
        while (*i < *pivot) {
            ++i;
        }
        while (*j > *pivot) {
            --j;
        }
        if (i >= j) {
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
 * @post: recusively call itself to apply hoare partition to a vector until the partition lease less than equal to 10 elements, then use sort on the ten elements
 * @param: a vector reference of ints
 * @param: a lower bound interator
 * @param: an upper bound interator
 * @param: a middle bound interator
 */
void recursiveQuickSelect(std::vector<int>& nums, std::vector<int>::iterator lower, std::vector<int>::iterator upper, std::vector<int>::iterator middle){
    if(std::distance(lower, upper) < 10){
        std::sort(lower, upper + 1);
        return;
    }

    std::vector<int>::iterator pivot = hoarePartition(nums, lower, upper);
    if(pivot == middle){
        return;
    }
    else if(pivot < middle){
        recursiveQuickSelect(nums, pivot + 1, upper, middle);
    }
    else if(pivot > middle){
        recursiveQuickSelect(nums, lower, pivot - 1, middle);
    }
}

/**
 * @post: call a recursive quick select helper function to partition until it finds the median, then return the medians index
 * @param: a vector reference of ints
 * @param: a int reference duration
 * @return: return the median of a vector
 */
int quickSelect ( std::vector<int>& nums, int& duration ){
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int>::iterator lower = nums.begin();
    std::vector<int>::iterator upper = nums.end() - 1;
    std::vector<int>::iterator middle = nums.begin() + (nums.size() - 1)/2;

    recursiveQuickSelect(nums, lower, upper, middle);

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    return *(nums.begin() + (nums.size() - 1)/2);
}
