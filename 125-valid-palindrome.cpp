#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	int n = s.size();
    	
    	string sub = "";
        for(int i=0; i<n; ++i){
        	if(isalnum(s[i])){
        		sub+=tolower(s[i]);
        	}
        }

        cout << sub << endl;

        if(sub.size()%2 == 1){

        	int idx = (sub.size() + 1)/2 - 1;

        	sub.erase(idx, 1);
        }
        for( int i=0; i < sub.size()/2; ++i){
        	if(sub[i] == sub[sub.size()-i-1]){
        		// cout << "bo";
        		continue;
        	}else{
        		return false;
        	}
        }


        return true;
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

	string s;
	getline(cin, s);
	Solution a= Solution();
	cout << a.isPalindrome(s);
	
	return 0;	
}