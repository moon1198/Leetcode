#include <bits/stdc++.h>
using namespace std;

vector<string> ans;


void backtrack(string &path, int sem, int &n) {
    if (sem < 0 || sem > n || path.size() > 2 * n) return ;

    if (sem == 0 && (path.size() == 2 * n)) {
        // cout << path.size() << "; " << 2 * n << endl;
        // cout << path << endl;
        // cout << endl;
        ans.push_back(path);
    }

    for (auto ch : "()") {
        if (ch == '(') {
            sem ++;
        } else if (ch == ')') {
            sem --;
        } else {
            continue;
        }
        path.push_back(ch);
        backtrack(path, sem, n);
        path.pop_back();
        if (ch == '(') {
            sem --;
        } else if (ch == ')') {
            sem ++;
        }
    }
}

vector<string> generateParenthesis(int n) {
    string path;
    backtrack(path, 0, n);
    return ans;
}