#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int solution454_0(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    int count = 0;
    unordered_map<int, int>mp1;
    unordered_map<int, int>mp2;
    for (int i : nums1) {
        for (int j : nums2) {
            mp1[i + j] ++;
        }
    }
    for (int i : nums3) {
        for (int j : nums4) {
            mp2[i + j] ++;
        }
    }
    for (auto p : mp1) {
        if (mp2.count(-p.first)) {
            if (mp2[-p.first] > 0) {
                count += mp2[-p.first] * p.second;
            }
        }
    }
    return count;
}