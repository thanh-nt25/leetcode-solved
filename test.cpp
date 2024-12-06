#include <bits/stdc++.h>

using namespace std;

bool sinh_ke_tiep(int n, vector<int> &xau){
    for(int i=n-1; i >= 0; --i){
        if(xau[i] == 0){
            xau[i] = 1;
            for(int j = i+1; j < n; ++j){
                xau[j] = 0;
            }
            return true;
        }
    }
    return false;
}

void sinh_xau(int n, vector<int> &xau){
    bool check = true;
    
    do{
        for(auto x: xau){
            cout << x;
        }
        cout << endl;
        check = sinh_ke_tiep(n, xau);
    }while(check);
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 6;
    vector<int> xau(n, 0);

    // sinh_xau(n, xau);

    vector<int> a = {1,2,3};
    vector<int> b;
    b.assign(a.begin(), a.end());
    for(auto x : b){
        cout << x;
    }
    return 0;
}


