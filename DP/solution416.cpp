#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool solution416_0(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum / 2;



    for (int &num : nums) {
        target -= num;
        if (target == 0) return true;
        if (target < 0) return false;
    }
    return false;
}