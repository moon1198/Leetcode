#include <string>
#include <vector>
using namespace std;



vector<int> get_next0(string needle) {
    int len = needle.size();
    vector<int> ans(len);
    ans[0] = 0;
    int left = 0, right = 1;
    int count = 0;
    while (right < len) {
        if(needle[left] == needle[right]) {
            ++ count;
            ans[right] = count;
            ++ right; ++ left;
        }else{
            if (count == 0) {
                ++ right;
            }else{
                count = ans[left - 1];
                left = ans[left - 1];
            }
        }
    }
    ans[len - 1] = count;
    return ans;
}
int solution28_0 (string haystack, string needle) {
    vector<int>next = get_next0(needle);
    int i = 0, j = 0;
    int len_h = haystack.size();
    int len_n = needle.size();
    while (j < len_h){
        if (needle[i] == haystack[j]) {
            ++ i; ++ j;
            if (i == len_n){
                return j - len_n;
            }
        }else {
            if (i > 0){
                i = next[i - 1];
            }else {
                ++ j;
            }
        }
    }
    return -1;
}







vector<int> get_next1(string s) {
    int len = s.size();
    vector<int>vec(len);
    vec[0] = 0;
    int left = 0, right = 1;
    while (right < len) {
        if (s[left] == s[right]) {
            ++ left;
            vec[right] = left;
            ++ right;
        }else {
            if (left == 0) {
                ++ right;
            }else {
                left = vec[left - 1];
            }
        }
        vec[len - 1] = left;
    }
    return vec;
}
int solution28_1 (string haystack, string needle) {
    int len_h = haystack.size();
    int len_n = needle.size();
    vector<int>next = get_next1(needle);
    int i = 0, j = 0;
    while (i < len_h) {
        if (haystack[i] == needle[j]) {
            ++ i; ++ j;
            if (j == len_n) {
                return i - len_n;
            }
        }else {
            if (j == 0) {
                ++ i;
            }else {
                j = next[j - 1];
            }
        }
    }
    return -1;
}

//for实现get_next
vector<int> get_next2(string s) {
    int len = s.size();
    int left = 0, right = 1;
    vector<int>vec(len);
    for (; right < len; ++ right) {
        while(left > 0 && s[left] != s[right]) {
            left = vec[left - 1];
        }
        if (s[left] == s[right]) {
            ++ left;
        }
        vec[right] = left;
    }
    return vec;
}
//-1实现get_next
vector<int> get_next3(string s) {
    int j = -1, i = 0;
    int len = s.size();
    vector<int> vec(len);
    vec[i] = j;
    for (i = 1; i < len; ++ i) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = vec[j];
        }
        if (s[i] == s[j + 1]) {
            ++ j;
        } 
        vec[i] = j;
    }
    return vec;
}
int solution28_2 (string haystack, string needle) {
    vector<int>next = get_next3(needle);
    int len_h = haystack.size(), len_n = needle.size();
    int i = 0, j = -1;
    for (; i < len_h; ++ i) {
        while (j >= 0 && haystack[i] != needle[j + 1]) {
            j = next[j];
        }
        if (haystack[i] == needle[j + 1]) {
            ++ j;
        }
        if (j == len_n - 1) {
            return i - j;
        }
    }
    return -1;
}

