#include <bits/stdc++.h>
using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    //cost
    int M = 0, P = 0, G = 0;
    //location
    int mi = 0, pi = 0, gi = 0;
    for (int i = 0; i < garbage.size(); ++ i) {
        for (char &it : garbage[i]) {
            if (it == 'M') {
                int cost = 1;
                for (int j = mi; j < i; ++ j) {
                    cost += travel[j];
                }
                mi = i;
                M += cost;
            } else if(it == 'P') {
                int cost = 1;
                for (int j = pi; j < i; ++ j) {
                    cost += travel[j];
                }
                pi = i;
                P += cost;

            } else if(it == 'G') {
                int cost = 1;
                for (int j = gi; j < i; ++ j) {
                    cost += travel[j];
                }
                gi = i;
                G += cost;
            }
        }
    }
    //cout << P << "; " << G << "; " << M << "; " << endl;

    return P + G + M;
}