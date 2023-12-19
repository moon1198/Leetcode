#include <vector>
#include <map>
using std::vector;
using std::map;
vector<int>solution349_0(vector<int> &nums1, vector<int> &nums2) {
    vector<int>ans;
    map<int, int>cmp;
    for (auto val : nums1) {
        cmp[val] ++;
    }
    for (auto val : nums2) {
        if (cmp[val]) {
            cmp[val] --;
            ans.push_back(val);
        }
    }
    return ans;
}