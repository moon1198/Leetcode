#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<int> tmp;
static vector<vector<int>> res;
static int sum = 0;
void recur39_0(vector<int> &candidates, int target, int index) {
    if (sum > target) return ;
    else if (sum == target) {
        res.push_back(tmp);
        return ;
    }else {
        for (int i = index; i < static_cast<int>(candidates.size()); ++ i) {
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            //by choose index, fliter the same vector
            recur39_0(candidates, target, i);
            tmp.pop_back();
            sum -= candidates[i];
        }
    }
}

vector<vector<int>> solution39_0(vector<int> &candidates, int target) {
    recur39_0(candidates, target, 0);
    return res;
}