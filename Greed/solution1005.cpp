#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution1005_0(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0;
    while (k > 0) {
        if (i < nums.size() && nums[i] < 0) {
            nums[i] = -nums[i];
            ++ i;
        }else {
            if (k % 2 == 0) {
                break;
            }
            if (i == nums.size()) {
                nums[i - 1] = -nums[i - 1];
            }else {
                if (i - 1 >= 0 && nums[i] > nums[i - 1]) {
                    i = i - 1;
                }
                nums[i] = -nums[i];
            }
            break;
        }
        -- k;
    }

    return accumulate(nums.begin(), nums.end(), 0);
}


int solution1005_1(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), [](int &a, int &b) {return abs(a) > abs(b);});
    for (int i = 0; i < nums.size(); ++ i) {
        if (k > 0 && nums[i] < 0) {
            nums[i] = -nums[i];
            -- k;
        }
    }
    if (k % 2 == 1) nums[nums.size() - 1] *= -1;
    return accumulate(nums.begin(), nums.end(), 0);
}