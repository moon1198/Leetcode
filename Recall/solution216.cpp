#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<int>> res;
static vector<int> tmp;

void recur216_0 (int bg, int sum, int k) {
    if (k == static_cast<int>(tmp.size())) {
        if (accumulate(tmp.begin(), tmp.end(), 0) == sum) {
            res.push_back(tmp);
        }
        return ;
    }
    //Tree pruning
    for (int i = bg; i <= static_cast<int>(9 - (k - tmp.size()) + 1); ++ i) {
        tmp.push_back(i);
        recur216_0(i + 1, sum, k);
        tmp.pop_back();
    }
    // res.emplace_back(vector<int>(1, 1));
}


vector<vector<int>> solution216_0(int k, int n){
    recur216_0(1, n, k);
    return res;
}
