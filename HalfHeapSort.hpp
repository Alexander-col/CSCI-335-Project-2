

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

/**
 * @post: applys a percolate down on a given hole
 * @param: a vector reference of numbers
 * @param: a size_type for a vector of int representing the hole 
 * @return: returns the median of the numbers
 */
void percDown ( std::vector<int>& heap, std::vector<int>::size_type hole ){
    int child;
    int value;
    for(value = std::move(heap[0]); hole * 2 < heap.size(); hole = child){
        child = hole * 2;
        if(child != heap.size() - 1 && heap[child] > heap[child+1]){
            child++;
        }
        if(value > heap[child]){
            heap[hole] = std::move(heap[child]);
        }
        else{
            break;
        }
    }
    heap[hole] = std::move(value);
}

/**
 * @post: applys percDown on half of the nums creating a min heap
 * @param: a vector reference of nums
 * @return: returns a min heap
 */
void buildHeap ( std::vector<int>& heap){
    for(int i = (heap.size()-1)/2; i>0; --i){
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

/**
 * @post: sorts half of the nums vector and returns half of the vector
 * @param: vector reference of numbers
 * @param: int reference duration
 * @return: returns the median of the numbers
 */
int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start_time = std::chrono::steady_clock::now();

    nums.push_back(nums[0]);
    buildHeap(nums);

    int median = nums.size()/2 - 1;

    for (int i = 0; i < median; i++) {
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        percDown(nums, 1);
    }

    auto end_time = std::chrono::steady_clock::now();
    duration = std::chrono::duration<double, std::milli>(end_time - start_time).count();
    return nums[1];
}