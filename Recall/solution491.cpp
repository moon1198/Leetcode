#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<int>> res;
static vector<int> tmp;

void recur491_0 (vector<int> &nums, int index) {
    // if (index >= static_cast<int>(nums.size())) {
    //     return ;
    // }

    set<int> st;
    for (int i = index; i < static_cast<int>(nums.size()); ++ i) {
        
        //three condition
        if (tmp.size() > 0) {
            if (tmp.back() > nums[i]) {
                continue;
            }
        }
        if (st.find(nums[i]) != st.end()) {
            continue;
        }

        tmp.push_back(nums[i]);
        st.insert(nums[i]);

        if (tmp.size() > 1) {
            res.push_back(tmp);
        }
        recur491_0(nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> solution491_0(vector<int> &nums) {
    recur491_0(nums, 0);
    return res;
}