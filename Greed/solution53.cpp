#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution53_0(vector<int> &nums) {
    int res = nums[0];
    int left = 0, right = 0;
    int sum = 0;
    int len = nums.size();
    while (right < len) {
        if (sum >= 0) {
            sum += nums[right];
            ++ right;
        }else if (sum < 0) {
            sum -= nums[left];
            ++ left;
        }
        if (left < right) {
            res = res >= sum ? res : sum;
        }
    }
    return res;
}

int solution53_1(vector<int> &nums) {
    int res = nums[0];
    int index = 0;
    int sum = 0;
    int len = nums.size();
    while (index < len) {
        if (sum >= 0) {
            sum += nums[index];
            ++ index;
            res = res >= sum ? res : sum;
        }else if (sum < 0) {
            sum = 0;
        }
    }
    return res;
}

int solution53_2(vector<int> &nums) {
    int res = nums[0];
    int sum = 0;
    int len = nums.size();
    for (int i = 0; i < len; ++ i) {
        sum += nums[i];
        res = res >= sum ? res : sum;
        if (sum < 0) sum = 0;
    }
    return res;
}