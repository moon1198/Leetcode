#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive0(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int tmp = 0;
    for (int &num : nums) {
        if (tmp == 0 && num > 0) {
            tmp = num;
            if (tmp != 1) {
                return 1;
            }
        } else if(tmp > 0) {
            if (num > tmp + 1) {
                return tmp + 1;
            } else {
                tmp = num;
            }
        }
    }
    return tmp + 1;
}

int firstMissingPositive1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 1;
    for (int &num : nums) {
        if (num == res) {
            res ++;
            continue;
        }
        if (num > res) {
            return res;
        }
    }
    return res;
}

int firstMissingPositive2(vector<int>& nums) {
    int n = nums.size();
    for (int &num : nums) {
        while (num < n + 1 && num > 0 && nums[num - 1] != num) {
            swap(nums[num - 1], num);
            //泛型算法就是快
            // int tmp = nums[num - 1];
            // nums[num - 1] = num;
            // num = tmp;
        }
    }
    for (int i = 0; i < n; i ++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}
