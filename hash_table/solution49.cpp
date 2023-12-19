#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::string;

bool solution242_0(string s, string t);
vector<vector<string>> solution49_0(vector<string>& strs) {
    vector<vector<string>>ans;
    vector<string> tmp;
    tmp.push_back(strs[0]);
    ans.push_back(tmp);
    bool flag = false;
    //for (string &str : &(strs[1])) {
    for (size_t i = 1; i < strs.size(); i ++){
        for (vector<string> &str_ans : ans) {
            if (solution242_0(strs[i], str_ans[0])) {
                str_ans.push_back(strs[i]);
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
        }else{
            tmp[0] = strs[i];
            ans.push_back(tmp);
        }
    }
    return ans;
}


vector<vector<string>> solution49_1(vector<string>& strs) {
    std::unordered_map<string, vector<string>> mp;
    for (string str : strs) {
        string tmp = str;
        std::sort(tmp.begin(), tmp.end());
        mp[tmp].emplace_back(str);
    }
    vector<vector<string>>ans;
    for (auto it : mp) {
        ans.emplace_back(it.second);
    }
    return ans;
}