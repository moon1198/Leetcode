#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<string> const nums_map = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
static string tmp;
static vector<string> res;

void recur17_0(string digits) {
    //合并判断条件出错，why?
    if (digits.size() == 0) {
        if (tmp.size() != 0) {
            res.push_back(tmp);
        }
        return ;
    }
    for (int i = 0; i < static_cast<int>(nums_map[digits[0] - '0'].size()); ++ i) {
        tmp.push_back(nums_map[digits[0] - '0'][i]);
        recur17_0(digits.substr(1));
        tmp.pop_back();
    }
}

vector<string> solution17_0(string digits) {
    recur17_0(digits);
    return res;
}