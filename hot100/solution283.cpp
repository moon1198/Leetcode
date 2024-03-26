#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    //抽象出两个数组，fast, slow各一个， 
    //不为零填入， 为零略过
    int slow = 0, fast = 0;
    int n = nums.size();
    for (; fast < n; ++ fast) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            ++ slow;
        }
    }
    while (slow != fast) {
        nums[slow] = 0;
        ++ slow;
    }
}