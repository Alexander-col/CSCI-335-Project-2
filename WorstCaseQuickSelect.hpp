

#include <vector>
#include <iostream>
#include <chrono>

/**
 * @post: create a vector for the worse case for median of 3 pivot selection for a quick select algorithm
 * @return: return a vector
 */
std::vector<int> worstCaseQuickSelect() 
{
    std::vector<int> result(20000);
    for (int i = 0; i < 20001; ++i) 
    {
        result[i] = 20000 - i;
    }

    for(int i = 0; i< 10000;i++)
    {
        if(i%2 != 0){
            result[10000+i] = 10000+i;
        }
        else{
            result[10000+i] = i+1;
        }
        result[i] = (i+1)*2;
    }

    return result;
}