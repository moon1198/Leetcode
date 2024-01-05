#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution376_0(vector<int> &nums) {
    int len = nums.size();
    if (len == 1) return len;

    int res = 1;
    int flag = 0;

    int i = 1;
    for (; i < len && flag == 0; ++ i) {
        if (nums[i] > nums[i - 1]) {
            flag = 1;
            ++ res;
        }
        if (nums[i] < nums[i - 1]) {
            flag = -1;
            ++ res;
        }
    }

    for (; i < len; ++ i) {
        if (nums[i] > nums[i - 1]) {
            if (flag == -1) {
                ++ res;
                flag = 1;
            }
        }
        if (nums[i] < nums[i - 1]) {
            if (flag == 1) {
                ++ res;
                flag = -1;
            }
        }
    }




    // bool up_flag = false;

    // if (nums[1] >= nums[0]) up_flag = true;

    // for (int i = 2; i < len; ++ i) {
    //     if (nums[i] >= nums[i - 1]) {
    //         if (up_flag) {
    //             -- res;
    //         }else {
    //             up_flag = true;
    //         }
    //     }
    //     if (nums[i] < nums[i - 1]) {
    //         if (!up_flag) {
    //             -- res;
    //         }else {
    //             up_flag = false;
    //         }
    //     }
    // }
    return res;

}

int solution376_1(vector<int> &nums) {
    int len = nums.size();
    if (len == 1) return len;

    int res = 1;
    int flag = 0;

    for (int i = 1; i < len; ++ i) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] > nums[i - 1]) {
            if (flag == 1) continue;
            flag = 1;
        }
        if (nums[i] < nums[i - 1]) {
            if (flag == -1) continue;
            flag = -1;
        }
        ++ res;
    }
    return res;

}