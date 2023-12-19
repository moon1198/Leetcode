#include <vector>
using std::vector;
vector<int> solution349_1(vector<int> &nums1, vector<int> &nums2) {
    vector<int>ans;
    vector<int>cmp(1001);
    for (auto val : nums1) {
        cmp[val] = 1;
    }
    for (auto val : nums2) {
        if (cmp[val]) {
            cmp[val] = 0;
            ans.push_back(val);
        }
    }
    return ans;
}