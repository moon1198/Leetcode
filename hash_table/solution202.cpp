#include <set>

using std::set;

bool solution202_0(int n) {
    int remain = 0;
    int sum = 0;
    set<int>st;
    while (sum != 1){
        sum = 0;
        while (n != 0) {
            remain = n % 10;
            sum += remain * remain;
            n /= 10;
        }
        if (st.count(sum)) {
            return false;
        }else{
            st.emplace(sum);
        }
        n = sum;
    }
    return true;
}