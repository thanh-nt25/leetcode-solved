#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	if (s.size() == 0) return true;
    	int leng = wordDict.size();
    	
    	
    	vector<string> tmpwordDict;
    	
    	for(auto x : wordDict){
    		tmpwordDict.push_back(x);
    	}

    	map<int, vector<string>> smap;
    	for(auto x : tmpwordDict){
    		size_t sz = x.size();
    		auto it = smap.find(sz); // find with key
    		if(it != smap.end()){ // tim thay
    			smap[sz].push_back(x);
    		}else{
    			smap[sz] = {x};
    		}
    	}

    	// print map
    	// for(auto pair : smap){
    	// 	cout << pair.first << '-';
    	// 	for(auto x : pair.second){
    	// 		cout << x << ' ';
    	// 	}
    	// 	cout << endl;
    	// }
    	// cout << "-------" << endl;
    	bool check = false;
    	for(auto pair = smap.rbegin(); pair != smap.rend(); ++pair){
    		for(auto word : pair->second){
    			string sstr = s.substr(0, pair->first);
    			// cout << sstr  << '-'<< word << endl;
    			if(sstr.compare(word) == 0){
    				// cout << "dung" << " truyen vao "<< s.substr(pair->first)<< endl;
    				check = wordBreak(s.substr(pair->first), wordDict);
    				if(check == true) return true;
    			}
    		}
    	}
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

	string s; cin >> s;
	vector<string> wordDict;
	int n; cin >> n;
	for(int i=0; i < n; ++i){
		string tmp;
		cin >>  tmp;
		wordDict.push_back(tmp);
	}


	Solution a = Solution();
	cout << a.wordBreak(s, wordDict);


	return 0;	
}