#include <vector>
#include <limits>
#include <iostream>
using std::vector;
int solution209_0(int target, vector<int> &nums){
    int left = 0; int right = 0;
    int len = nums.size();
    int sum = 0; int count = std::numeric_limits<int>::max();
    for (; right < len; ++ right){
        sum += nums[right];
        while (sum >= target){
            if (right - left + 1 < count){
                count = right - left + 1;
            }
            std::cout << count << "; ";
            sum -= nums[left ++];
        }
    }
    std::cout << std::endl;
    return count;
}