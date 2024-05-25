#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    int len = min(m, n);
    string ans;
    for (int i = 1; i <= len; ++ i) {
        if (!(m % i || n % i)) {
            int base = 0; 
            string tmp = str1.substr(base, i);
            while (base < n || base < m) {
                if (base < m && tmp != str1.substr(base, i)) {
                    break;
                }
                if (base < n && tmp != str2.substr(base, i)) {
                    break;
                }
                base += i;
            }
            if (base >= n && base >= m) {
                if (tmp.size() > ans.size()) {
                    ans = tmp;
                }
            }
        }
    }

    return ans;
}

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";

    string long_str; int short_len = 0;
    if (str1.size() < str2.size()) {
        long_str = str2;
        short_len = str1.size();
    } else {
        long_str = str1;
        short_len = str2.size();
    }
    int len = long_str.size();
    string ans;
    for (int i = 1; i <= short_len; ++ i) {
        if (len % i == 0 && short_len % i == 0) {
            int base = 0; 
            string tmp = long_str.substr(base, i);
            while (base < len) {
                if (tmp != long_str.substr(base, i)) {
                    break;
                }
                base += i;
            }
            if (base >= len) {
                if (tmp.size() > ans.size()) {
                    ans = tmp;
                }
            }
        }
    }

    return ans;
}