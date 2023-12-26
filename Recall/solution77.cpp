#include <vector>

using namespace std;

static vector<vector<int>> res;
static vector<int> tmp;

void recur77_0 (int be, int ed, int k) {
    if (k == static_cast<int>(tmp.size())) {
        res.push_back(tmp);
        return ;
    }
    //Tree pruning
    for (int i = be; i <= static_cast<int>(ed - (k - tmp.size()) + 1); ++ i) {
        tmp.push_back(i);
        recur77_0(i + 1, ed, k);
        tmp.pop_back();
    }
    // res.emplace_back(vector<int>(1, 1));
}


vector<vector<int>> solution77_0(int n, int k){
    recur77_0(1, n, k);
    return res;
}