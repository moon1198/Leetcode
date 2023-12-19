#include <vector>
void solution283_0(std::vector<int>& nums){
    int front = 0; int back = 0;
    int len = nums.size();
    for (; front < len; ++ front){
        if (nums[front] != 0){
            nums[back] = nums[front];
            ++ back;
        }
    }
    for (; back < len; ++ back){
        nums[back] = 0;
    }
}
void solution283_1(std::vector<int>& nums){
    int left = 0; int right = 1;
    int len = nums.size();
    while (left < len){
        if (nums[left] == 0){
            break;
        }
        ++ left;
    }
    for (right = left +  1; right < len; ++ right){
        if (nums[right] != 0){
            nums [left] = nums[right];
            nums [right] = 0;
            ++ left;
        }
    }
}