#include <bits/stdc++.h>
using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
int ret = 0;

void backtrace(vector<int> &dict) {
    // cout << "hhh" << endl;
    int flag = 0;
    for (int i = 0; i < 26; ++ i) {
        if (dict[i] != 0) {
            flag = 1;
            -- dict[i];
            backtrace(dict);
            ++ dict[i];
        }
    }
    if (!flag) {
        ++ ret;
    }
}

int bar()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;

    string s;
    cin >> s;
    vector<int>dict(26, 0);
    for (auto &ch : s) {
        ++ dict[ch - 'A'];
    }
    backtrace(dict);
    cout << ret << endl;
    
    return 0;
}