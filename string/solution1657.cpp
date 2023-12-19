#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution1657_0(string word1, string word2) {
    vector<int> vec1(26);
    vector<int> vec2(26);
    for (char i : word1) {
        vec1[i - 'a'] ++;
    }
    for (char i : word2) {
        vec2[i - 'a'] ++;
    }
    map<int, int>mp;
    //判断是否包含相同的字母集
    for (int i = 0; i < 26; ++ i) {
        if ((vec1[i] && vec2[i]) || (!(vec1[i] || vec2[i]))) {

        }else {
            return false;
        }
    }
    //判断是否有相同的频数集
    for (auto i : vec1) {
        mp[i] ++;
    }
    for (auto i : vec2) {
        if (mp.count(i)) {
            mp[i] --;
        }else {
            return false;
        }
    }
    for (auto i : mp) {
        if (i.second != 0) return false;
    }
    return true;
}