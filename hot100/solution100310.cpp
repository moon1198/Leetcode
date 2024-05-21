#include <bits/stdc++.h>
using namespace std;

bool isArraySpecial(vector<int>& nums) {
    if (nums.size() == 1) {
        return true;
    }
    int flag = nums[0] % 2;
    for (int i = 1; i < nums.size(); ++ i) {
        int tmp = nums[i] % 2;
        if (tmp == flag) {
            return false;
        }
        flag = tmp;
    }
    return true;
}
