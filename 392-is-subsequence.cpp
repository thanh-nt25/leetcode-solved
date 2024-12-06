#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int i1 = 0;
    	
    	for(int i=0; i < t.size(); ++i){
    		if(s[i1] == t[i]){
    	
    			i1++;
    		}
    	}
    	
    	if(i1 == s.size()) return true;


        return false;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	Solution a = Solution();
	cout << a.isSubsequence(s,t);
	
	return 0;	
}