#include <string>
#include <iostream>
using std::string;
bool solution844_0(string s, string t){
    int len = s.size();
    int left = -1; int right = 0;
    for (; right < len; ++ right){
        if (s[right] == '#'){
            if (left > -1){
                -- left; 
            }
        }else{
            s[++ left] = s[right];
        }
    }
    s.resize(left + 1);
    
    len = t.size();
    left = -1; right = 0;
    for (; right < len; ++ right){
        if (t[right] == '#'){
            if (left > -1){
                -- left; 
            }
        }else{
            t[++ left] = t[right];
        }
    }
    t.resize(left + 1);
    std::cout << "s = " << s << std::endl;
    std::cout << "t = " << t << std::endl;
    if (s == t){
        return true;
    }else{
        return false;
    }
}