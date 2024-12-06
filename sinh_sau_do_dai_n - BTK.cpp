#include <bits/stdc++.h>

using namespace std;


void sinh_xau(int subp, int n, vector<int> &xau, vector<vector<int>>& loi_giai){
    if(subp == n) {
        loi_giai.push_back(xau);
        return;
    }

    for(int i=0; i <= 1; ++i){
        xau.push_back(i);
        
        sinh_xau(++subp, n, xau, loi_giai);
        xau.pop_back();
        --subp;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r",  stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n = 4;
    vector<int> xau;
    vector<vector<int>> loi_giai;

    sinh_xau(0, n, xau,loi_giai);
    // cout << 'c';
    // cout << loi_giai.size() << endl;
    for(auto i: loi_giai){
        for(auto j: i){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}


