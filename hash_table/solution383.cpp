#include <string>
#include <vector>


using std::string;
using std::vector;
bool solution383_0(string ransomNote, string magazine) {
    vector<int>mp(26); 
    for (char ch : ransomNote) {
        mp[ch - 'a'] ++;
    }
    for (char ch : magazine) {
        mp[ch - 'a'] --;
    }
    for (int val : mp) {
        if (val > 0) {
            return false;
        }
    }
    return true;
}