#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

vector<int> solution438_0(string s, string p) {
    int count_p = p.size();
    int count_s = s.size();
    int flag = 0;

    vector<int>ans;
    unordered_map<char, int> mp;
    for (char ch : p) {
        if (!mp.count(ch)) {
            flag ++;
        }
        mp[ch] ++;
    }
    int left = 0, right = 0;
    while (right != count_s) {
        if(mp.count(s[right])) {
            mp[s[right]] --;
            if(!mp[s[right]]) {
                -- flag;
            }
        }
        ++ right;
        if (right - left == count_p) {
            if (flag == 0) {
                ans.push_back(left);
            }
            if(mp.count(s[left])) {
                if(!mp[s[left]]) {
                    ++ flag;
                }
                mp[s[left]] ++;
            }
            ++ left;
        }
    }
    return ans;
}