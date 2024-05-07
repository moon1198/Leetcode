#include <bits/stdc++.h>
using namespace std;

int bar () {

    string root = "E:\\software_data\\xinjian\\";
    string name = "single_1_12GHz.txt";
    string path = root + name;
    cout << path << endl;

    fstream s(path, fstream::in);
//    cout << strerror(s.fail()) << endl;
//    cout << strerror(s.rdstate()) << endl;

    if (s.is_open()){
        cout << "Open!" << endl;
    }

    string str;
    getline(s, str);
    cout << str << "; " << endl;
    //for (int i = 0; i < 4; ++ i) {
    //    double num = 0;
    //    s >> str >> num;
    //    cout << str << "; " << to_string(round(num)) << endl;
    //}

    return 0;
}