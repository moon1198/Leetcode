#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<string>> res;
static vector<string> tmp;

bool ischeck(string s, int index, int i) {
    while (i > index) {
        if (s[index] != s[i]) {
            return true;
        }
        ++ index; -- i;
    }
    return false;
}
void recur131_0(string s, int index) {
    if (index >= static_cast<int>(s.size())) {
        res.push_back(tmp);
        return ;
    }
    for (int i = index; i < static_cast<int>(s.size()); ++ i) {
        if (ischeck(s, index, i)) {
            continue;
        }
        tmp.emplace_back(s.begin() + index, s.begin() + i + 1);
        recur131_0(s, i + 1);
        tmp.pop_back();
    }
}
vector<vector<string>> solution131_0(string s) {
    recur131_0(s, 0);
    return res;
}