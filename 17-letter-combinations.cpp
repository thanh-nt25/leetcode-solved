#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// sinh tap UCV
    vector<string> letterCombinations(string digits) {
    	vector<string> result;
    	if (digits.empty()) return result;
    	string current;
    	int n = digits.size();
    	backtrack(n, digits, current, result);
    	// for(auto x: result){
    	// 	cout << x;
    	// }
    	return result;

    }

    void backtrack(int n, string digits, string &current, vector<string> &result){

    	if(current.size() == n){
    		result.push_back(current);
    		return;
    	}

    	string UCV;
    	// cout << digits[0] << endl;
    	// cout << (int)digits[0]-(int)'0' << endl;
    	int num = (int)digits[0]-(int)'0';

	    switch(num){
    		case (2): {UCV.assign("abc");break;}
    		case (3): {UCV.assign("def");break;}
			case (4): {UCV.assign("ghi");break;}
			case (5): {UCV.assign("jkl");break;}
			case (6): {UCV.assign("mno");break;}
			case (7): {UCV.assign("pqrs");break;}
			case (8): {UCV.assign("tuv");break;}
			case (9): {UCV.assign("wxyz");break;}
			default:  {UCV.assign("sai");break;}

    	}
    	// cout << UCV << endl;
    	for(auto x: UCV){
    		current.push_back(x);
    		backtrack(n, digits.substr(1), current, result);
    		current.pop_back();
    	}
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

	Solution a = Solution();
	string s; cin >> s;

	vector<string> result;

	result = a.letterCombinations(s);

	for(auto x: result){
		cout << x << endl;
	}
	
	return 0;	
}