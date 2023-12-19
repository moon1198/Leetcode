#include <vector>
using std::vector;
vector <vector<int>> solution59_0(int n){
    vector <vector<int>> vtr (n, vector<int>(n));
    int size = n;
    int num = 1; int i = 0; int j = 0;
    while(size > 1){
        //判别条件和边界条件杂乱，
        //for (i = (n - size) / 2, j = i; j < n - i; ++ j){
        //    vtr[i][j] = num ++;
        //}
        //for (-- j, ++ i; i <= j; ++ i){
        //    vtr[i][j] = num ++;
        //}
        //for (-- j, -- i; j >= (n - size) / 2 ; -- j){
        //    vtr[i][j] = num ++;
        //}
        //for (++j, --i; i > (n - size) / 2 ; -- i){
        //    vtr[i][j] = num ++;
        //}
        //size -= 2;
        //使上一阶段的结束为下一阶段的开始，边界条件清晰
        for (i = (n - size) / 2, j = i; j < n - i - 1; ++ j){
            vtr[i][j] = num ++;
        }
        for (; i < j; ++ i){
            vtr[i][j] = num ++;
        }
        for (; j > (n - size) / 2 ; -- j){
            vtr[i][j] = num ++;
        }
        for (; i > (n - size) / 2 ; -- i){
            vtr[i][j] = num ++;
        }
        size -= 2;
    }
    if (n % 2){
        vtr[n/2][n/2] = num;
    }
    return vtr;
}