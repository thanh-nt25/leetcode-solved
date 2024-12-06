#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        int n = pattern.size();
        istringstream iss(s);
        string word;
        for(int i=0; i < n; ++i){
            iss >> word;
            auto it = m.find(pattern[i]);
            if(it != m.end()){
                if(word == it -> second) continue;
                else return false;
            }else{
                m[pattern[i]] = word;
            }
        }
        return true;
    }
};

int main()
{
// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solution solution;
    string pattern = "abba";
    string s = "dog dog dog dog";
    // unordered_map<char,string> m;
    // m[pattern[0]] = "hello";
    cout << bool(solution.wordPattern(pattern, s)) << endl;
    // cout << m[pattern[0]] << endl;
    
}

