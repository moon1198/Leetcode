#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map <string, vector<string>>mp;
      vector<vector<string>>ans;
      for (auto &it : strs) {
        string str = it;
        sort(str.begin(), str.end());
        if (mp.find(str) == mp.end()) {
            mp[str] = {it};
        } else {
            mp[str].push_back(it);
        }
      }
      for (auto &it : mp) {
        ans.emplace_back(it.second.begin(), it.second.end());
      }
      return ans;
}