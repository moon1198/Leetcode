#include <vector>
using std::vector;
vector<int> solution54_0(vector<vector<int>> &matrix){
    vector<int> vtr;
    int i = 0; int j = 0; 
    int m = matrix.size();
    int n = matrix[0].size();
    int size_m = m; int size_n = n;
    int start = 0;
    while (size_m > 1 && size_n > 1){
        start = (n - size_n) / 2;
        for (i = start, j = i; j < i + size_n; ++ j){
            vtr.push_back(matrix[i][j]);
        }
        for (-- j, ++ i; i < start + size_m; ++ i){
            vtr.push_back(matrix[i][j]);
        }
        for (-- j, -- i; j >= start ; -- j){
            vtr.push_back(matrix[i][j]);
        }
        for (++j, --i; i > start ; -- i){
            vtr.push_back(matrix[i][j]);
        }
        size_m -= 2; size_n -= 2;
    }
    if (size_m != 0 && size_n != 0){
        start = (n - size_n) / 2;
        for (i = start, j = i; j < i + size_n; ++ j){
            vtr.push_back(matrix[i][j]);
        }
        for (-- j, ++ i; i < start + size_m; ++ i){
            vtr.push_back(matrix[i][j]);
        }
    }
    return vtr;
}
vector<int> solution54_1(vector<vector<int>> &matrix){
    vector<int> vtr;
    int i = 0; int j = 0; 
    int m = matrix.size();
    int n = matrix[0].size();
    int size_m = m; int size_n = n;
    int start = 0;
    while (size_m > 1 && size_n > 1){
        for (i = start, j = i; j < i + size_n - 1; ++ j){
            vtr.push_back(matrix[i][j]);
        }
        for (; i < start + size_m - 1; ++ i){
            vtr.push_back(matrix[i][j]);
        }
        for (; j > start ; -- j){
            vtr.push_back(matrix[i][j]);
        }
        for (; i > start ; -- i){
            vtr.push_back(matrix[i][j]);
        }
        ++ start;
        size_m -= 2; size_n -= 2;
    }
    if (size_m != 0 && size_n != 0){
        if (size_m == 1){
            for (i = start, j = i; j < i + size_n; ++ j){
                vtr.push_back(matrix[i][j]);
            }
        }else{
            for (i = start, j = i; i < j + size_m; ++ i){
                vtr.push_back(matrix[i][j]);
            }
        }
    }
    return vtr;
}