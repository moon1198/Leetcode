#include <string>
#include <vector>
using std::string;
using std::vector;
int getIdx(char x) {
    return x >= 'A' && x <= 'Z' ? x - 'A' + 26: x - 'a';
}
string solution76_0(string s, string t){
    int len_s = s.size();
    int left = 0; int right = 0;
    int flag = 0;
    string ans = "";
    //默认值初始化为零
    vector<int> dict(60);
    for (char x : t){
        if (++ dict[getIdx(x)] == 1) ++ flag;
    }
    for (; right < len_s; right ++){
        int idx = getIdx(s[right]);
        //右侧增长窗口，数值减少，唯有dict[idx]>0，可能更新flag
        if (dict[idx] > 0) {
            if (-- dict[idx] <= 0){
                -- flag;
            }
        }else{
            -- dict[idx];
        }
        //flag==0时，表示右侧增长到符合位置，开始左侧缩减窗口
        //此时dict中所有元素，必然都<= 0
        while (flag == 0){
            idx = getIdx(s[left ++]);
            if (++ dict[idx] > 0){
                ++ flag;
                ans = (int)ans.size() > right - left + 2 || ans.empty() ? s.substr(left - 1, right - left + 2) : ans;
                break;
            }
        }
    }
    return ans;
}