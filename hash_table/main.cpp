#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "include.h"

int main() {
    vector<string>strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //string s = "catb";
    //string t = "tac";
    //cout << solution242_0(s, t) << endl;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;
    vector<vector<int>>ans;
    ans = solution18_0(nums, target);
    for (auto &i : ans) {
        for (auto j : i) {
            cout << j << "; ";
        }
        cout << endl;
    }
    //for (auto val : solution1_0(nums, 9)) {
        //cout << val << "; ";
    //}
}