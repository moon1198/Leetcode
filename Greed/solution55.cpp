#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool solution55_0(vector<int> &nums) {
    int len = nums.size();
    int loc = 0;
    for (int i = 0; i < len && i <= loc; ++ i) {
        loc = (nums[i] + i) > loc ? nums[i] + i : loc;
    }
    if (loc >= len - 1) {
        return true;
    }
    return false;
}

bool solution55_1(vector<int> &nums) {
    int len = nums.size();
    int loc = 0;
    for (int i = 0; i <= loc; ++ i) {
        loc = (nums[i] + i) > loc ? nums[i] + i : loc;
        if (loc >= len - 1) return true;
    }
    return false;
}