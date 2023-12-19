#include <vector>
#include <iostream>
using std::vector;
vector<int> solution977_0(vector<int> &nums){
    vector<int> v;
    int len = nums.size();
    v.resize(len);
    for (int &num : nums){
        num = num * num;
    }
    int left = 0; int right = len - 1;
    int end = len - 1;
    while (left <= right){
        if (nums[left] < nums[right]){
            v[end --] = nums[right];
            -- right;
        }else{
            v[end --] = nums[left];
            ++ left;
        }
    }
    return v;
}
vector<int> solution977_1(vector<int> &nums){
    vector<int> v;
    int len = nums.size();
    v.resize(len);
    int left = 0; int right = len - 1;
    int left_val, right_val;
    int end = len - 1;
    while (left <= right){
        left_val = nums[left] * nums[left];
        right_val = nums[right] * nums[right];
        if (left_val < right_val){
            v[end --] = right_val;
            -- right;
        }else{
            v[end --] = left_val;
            ++ left;
        }
    }
    return v;
}