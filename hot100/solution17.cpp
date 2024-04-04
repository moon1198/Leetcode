#include <bits/stdc++.h>
using namespace std;

vector<string> dir = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> ans;

void backtrack(string &digits, int idx, string &path) {
    if (path.size() == digits.size()) {
        ans.push_back(path);
        return ;
    }
    for (int i = 0; i < dir[digits[idx] - '0'].size(); ++ i) {
        path.push_back(dir[digits[idx] - '0'][i]);
        backtrack(digits, idx + 1, path);
        path.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return ans;
    string path;
    backtrack(digits, 0, path);
    return ans;
}