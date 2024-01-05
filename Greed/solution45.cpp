#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int counts = 0;
bool recur45_0(vector<int> &nums, int loc) {
    int len = nums.size();
    if (loc >= len - 1) return true;
    for (int i = nums[loc]; i > 0; -- i) {
        loc += i;
        ++ counts;
        if (recur45_0(nums, loc)) return true;
        -- counts;
        loc -= i;
    }
    return false;
}

int solution45_0(vector<int> &nums) {
    recur45_0(nums, 0);
    return counts;
}

int solution45_1(vector<int> &nums) {
    int len = nums.size();
    if (len = 1) return 0;
    int base = 0;
    int loc = nums[0];
    int counts = 1;

    while (loc < len - 1) {
        int tmp = base + 1;
        base += 2;
        while (base <= loc) {
            tmp = base + nums[base] > tmp + nums[tmp] ? base : tmp;
            ++ base;
        }

        base = tmp;
        loc = tmp + nums[tmp];
        ++ counts;
    }

    return counts;
}