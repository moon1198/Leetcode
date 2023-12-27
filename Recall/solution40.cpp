#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<int> tmp;
static vector<vector<int>> res;
static int sum = 0;

//每层开始索引递增，用于过滤元素复用
//同层相同元素只有一个可递归，过滤由于重复元素带来的重复结果；
//每层开始索引不递增，表示元素可复用
//
void recur40_0(vector<int> &candidates, int target, int index) {
    if (sum > target) return ;
    else if (sum == target) {
        res.push_back(tmp);
        return ;
    }else {
        //排序后去重
        //同层去重，下一层递增
        for (int i = index; i < static_cast<int>(candidates.size()); ++ i) {
            if (i > index && candidates[i - 1] == candidates[i]) {
                continue;
            }
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            //by choose index, fliter the same vector
            recur40_0(candidates, target, i + 1);
            tmp.pop_back();
            sum -= candidates[i];
        }
    }
}

vector<vector<int>> solution40_0(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    recur40_0(candidates, target, 0);
    return res;
}


void recur40_1(vector<int> &candidates, int target, int index, set<int> st) {
    if (sum > target) return ;
    else if (sum == target) {
        res.push_back(tmp);
        return ;
    }else {
        //同层去重，下一层递增
        for (int i = index; i < static_cast<int>(candidates.size()); ++ i) {
            if (st.find(candidates[i]) == st.end()) {
                //后面的重数，他的子树必然是前面树的的子树的子集，这是重复的来源
                //故直接掠过重数，就可以完成去重

                sum += candidates[i];
                tmp.push_back(candidates[i]);
                //by choose index, fliter the same vector
                recur40_1(candidates, target, i + 1, st);
                tmp.pop_back();
                sum -= candidates[i];

                st.insert(candidates[i]);
            }
        }
    }
}

vector<vector<int>> solution40_1(vector<int> &candidates, int target) {
    set<int> st;
    recur40_1(candidates, target, 0, st);
    return res;
}